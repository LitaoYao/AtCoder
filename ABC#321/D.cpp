// https://atcoder.jp/contests/abc321/tasks/abc321_d
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	long long n, m, p;
	cin >> n >> m >> p;
	vector<long long> a(n);
	vector<long long> b(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<long long> sumb(m);
	sumb[0] = b[0];
	for (int i = 1; i < m; ++i)
	{
		sumb[i] = sumb[i - 1] + b[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= p)
		{
			ans += p * m;
			continue;
		}
		long long limitB = p - a[i];
		int index = lower_bound(b.begin(), b.end(), limitB) - b.begin();
		if (index == 0)
		{
			ans += p * m;
		}
		else
		{
			ans += a[i] * m + sumb[index - 1] + limitB * (m - index);
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
