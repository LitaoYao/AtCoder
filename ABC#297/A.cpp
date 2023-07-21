// https://atcoder.jp/contests/abc297/tasks/abc297_a
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	long long n, d;
	cin >> n >> d;
	long long last = 0;
	long long x;
	long long ans = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (last != 0 && x - last <= d)
		{
			ans = x;
			break;
		}
		last = x;
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

