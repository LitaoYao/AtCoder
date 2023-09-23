// https://atcoder.jp/contests/abc321/tasks/abc321_c
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	vector<vector<long long>> C(11, vector<long long>(11, 0));
	C[0][0] = 1;
	for (int i = 1; i <= 10; ++i)
	{
		C[i][i] = 1;
		C[i][0] = 1;
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	long long k;
	cin >> k;
	if (k <= 9)
	{
		cout << k << endl;
		return;
	}
	k -= 9;
	int digit = 2;
	for (int d = 2; d <= 10; ++d)
	{
		long long count = 0;
		for (int i = d - 1; i < 10; ++i)
		{
			count += C[i][d - 1];
		}
		if (k <= count)
		{
			digit = d;
			break;
		}
		else
		{
			k -= count;
		}
	}
	long long ans = 0;
	int lastDigit = 10;
	for (int d = digit; d >= 1; --d)
	{
		for (int i = d - 1; i < lastDigit; ++i)
		{
			long long count = C[i][d - 1];
			if (k <= count)
			{
				ans = ans * 10 + i;
				lastDigit = i;
				break;
			}
			else
			{
				k -= count;
			}
		}
	}
	cout << ans << endl;
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
