// https://atcoder.jp/contests/abc295/tasks/abc295_e
#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;
struct ModInt{
	ModInt(long long num=0): num(num % mod){}
	long long num;
	ModInt& operator = (long long num)
	{
		this->num = num % mod;
		return *this;
	}
	ModInt operator + (const ModInt& other)
	{
		ModInt newModInt((this->num + other.num) % mod);
		return newModInt;
	}
	ModInt operator - (const ModInt& other)
	{
		ModInt newModInt(((this->num - other.num) % mod + mod) % mod);
		return newModInt;
	}
	ModInt operator * (const ModInt& other)
	{
		ModInt newModInt((this->num * other.num) % mod);
		return newModInt;
	}
	ModInt operator ^ (long long x)
	{
		ModInt ans;
		if (x == 0)
		{
			ans = ModInt(1);
		}
		else if (x == 1)
		{
			ans = *this;
		}
		else
		{
			ModInt tmp = *this ^ x / 2;
			if ((x & 1) == 0)
			{
				ans = tmp * tmp;
			}
			else
			{
				ans = tmp * tmp * *this;
			}
		}
		return ans;
	}
	ModInt operator / (const ModInt& other)
	{
		// according to Fermat's little theorem, when c is a prime, b ^ (c - 1) (mod c) = 1. 
		// so,
		// a / b (mod c)
		// = a / b * 1 (mod c)
		// = a / b * b ^ (c - 1) (mod c)
		// = a * b ^ (c - 2) (mod c)
		ModInt tmp = other;
		return *this * (tmp ^ (mod - 2));
	}
};
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	vector<vector<ModInt>> C(n + 1, vector<ModInt>(n + 1));
	C[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	// E(X) = sum_1_m(i * P(X = i)) 
	// = 1 * P(1) + 2 * P(2) + ... + m*P(m)
	// = (P(1) + P(2) + ... + P(m)) + (P(2) + ... + P(m)) + (P(3) + .. + P(m) + ... + (P(m))
	// = P(X >= 1) + P(X >= 2) + ... + P(X >= m)
	// = sum_1_m(P(X >= i))
	ModInt ans = 0;
	int targetCount = n - k + 1;
	for (int i = 1; i <= m; ++i)
	{
		int count = 0;
		int zero = 0;
		for (int num : nums)
		{
			if (num >= i)
			{
				++count;
			}
			if (0 == num)
			{
				++zero;
			}
		}
		// need to fill at least leftCount zero such that zero >= i
		int leftCount = (targetCount - count);
		if (leftCount < 0)
		{
			// always satisfy
			ans = ans + ModInt(1);
			continue;
		}
		if (leftCount > zero)
		{
			// never satisfy
			continue;
		}
		// P is the probability of P(zero >= i) for each zero
		ModInt P = ModInt(m - i + 1) / ModInt(m);
		ModInt Q = ModInt(1) - P;
		for (int j = leftCount; j <= zero; ++j)
		{
			// C_zero_j * P^j * Q^(zero - j)
			ans = ans + C[zero][j] * (P ^ j) * (Q ^ (zero - j));
		}
	}
	cout << ans.num << endl;
	return;
}
void fastRead()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main()
{
	fastRead();
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
