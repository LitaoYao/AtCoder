// https://atcoder.jp/contests/abc293/tasks/abc293_c
#include <iostream>
#include <vector>
#include <set>
using namespace std;
void dfs(vector<vector<int>>& grids, set<int>& visits, int n, int m, int x, int y, int& ans)
{
	if (x == n - 1 && y == m - 1)
	{
		++ans;
		return;
	}
	for (int i = 0; i < 2; ++i)
	{
		int nextx = x + i;
		int nexty = y + (1 - i);
		if (nextx < n && nexty < m)
		{
			if (visits.find(grids[nextx][nexty]) == visits.end())
			{
				visits.insert(grids[nextx][nexty]);
				dfs(grids, visits, n, m, nextx, nexty, ans);
				visits.erase(grids[nextx][nexty]);
			}
		}
	}
	return;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grids(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grids[i][j];
		}
	}
	set<int> visits;
	visits.insert(grids[0][0]);
	int ans = 0;
	dfs(grids, visits, n, m, 0, 0, ans);
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
