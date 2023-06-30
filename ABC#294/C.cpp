// https://atcoder.jp/contests/abc294/tasks/abc294_c
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<int> b(m + 1);
	for (int i = 0 ; i < n; ++i)
	{
		cin >> a[i];
	}
	a[n] = INT_MAX;
	for (int i = 0 ; i < m; ++i)
	{
		cin >> b[i];
	}
	b[m] = INT_MAX;
	int index = 1;
	for (int i = 0, j = 0; i <= n && j <= m;)
	{
		if (a[i] < b[j])
		{
			a[i++] = index++;
		}
		else
		{
			b[j++] = index++;
		}
	}
	for (int i = 0 ; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0 ; i < m; ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;
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
