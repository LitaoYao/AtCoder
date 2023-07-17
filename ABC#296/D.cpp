// https://atcoder.jp/contests/abc296/tasks/abc296_d
#include <iostream>
using namespace std;
void solve()
{
	long long n, m;
	cin >> n >> m;
	long long ans = -1;
	for (int i = 1; i <= n; ++i)
	{
		long long x = (m + i - 1) / i;
		if (x > n)
		{
			continue;
		}
		if (ans == -1 || ans > i * x)
		{
			ans = i * x;
		}
		if (x < i)
		{
			break;
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
