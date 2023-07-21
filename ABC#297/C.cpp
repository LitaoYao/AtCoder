// https://atcoder.jp/contests/abc297/tasks/abc297_c
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> strs(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> strs[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			if (strs[i][j] == 'T' && strs[i][j + 1] == 'T')
			{
				strs[i][j] = 'P';
				strs[i][j + 1] = 'C';
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << strs[i] << endl;
	}
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
