// https://atcoder.jp/contests/abc293/tasks/abc293_f
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
const int maxBits = 62; // log(10^18, 2) + 1;
bool isBase(long long n, long long b)
{
	while (n != 0)
	{
		long long mod = n % b;
		if (mod > 1)
		{
			return false;
		}
		n /= b;
	}
	return true;
}
void solve()
{
	long long n;
	cin >> n;
	set<long long> bases;
	// initial base = n is valid
	bases.insert(n);
	if (n > 2)
	{
		// base = n - 1 is valid
		bases.insert(n - 1);
		// iterate bits from 3 ~ maxBits
		for (int bits = 3; bits <= maxBits; ++bits)
		{
			long long l = 2;
			long long r = sqrt(n) + 1;
			while (l < r)
			{
				long long base = (l + r) >> 1;
				__int128 upper = 0;
				__int128 nowBase = 1;
				for (int bit = 0; bit < bits; ++bit)
				{
					upper += nowBase;
					if (n < upper)
					{
						break;
					}
					nowBase = nowBase * base;
				}
				if (n > upper)
				{
					l = base + 1;
				}
				else
				{
					r = base;
				}
			}
			long long b = l;
			if (bases.find(b) == bases.end() && isBase(n, b))
			{
				bases.insert(b);
			}
		}
	}
	cout << bases.size() << endl;
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
