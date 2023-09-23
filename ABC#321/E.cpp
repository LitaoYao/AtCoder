// https://atcoder.jp/contests/abc321/tasks/abc321_e
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void GetBound(long long x, long long k, long long& left, long long& right)
{
	left = right = x;
	for (int i = 1; i <= k; ++i)
	{
		left = left * 2;
		right = right * 2 + 1;
	}
	return;
}
void solve()
{
	long long n, x, k;
	cin >> n >> x >> k;
	long long maxDeep = 1;
	long long tmp = 1;
	while (tmp < n)
	{
		++maxDeep;
		tmp = tmp * 2 + 1;
	}
	long long nowDeep = 0;
	tmp = x;
	while (tmp >= 1)
	{
		++nowDeep;
		tmp /= 2;
	}
	long long ans = 0;
	long long left, right;
	int mod;
	if (maxDeep - nowDeep >= k)
	{
		GetBound(x, k, left, right);
		if (left <= n)
		{
			ans += min(n, right) - left + 1;
		}
	}
	mod = x % 2;
	x /= 2;
	--nowDeep;
	--k;
	while (x >= 1 && k >= 0)
	{
		if (k == 0)
		{
			++ans;
		}
		else if (maxDeep - nowDeep >= k)
		{
			if (mod == 1)
			{
				GetBound(x * 2, k - 1, left, right);
			}
			else
			{
				GetBound(x * 2 + 1, k - 1, left, right);
			}
			if (left <= n)
			{
				ans += min(n, right) - left + 1;
			}
		}
		mod = x % 2;
		x /= 2;
		--nowDeep;
		--k;
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
