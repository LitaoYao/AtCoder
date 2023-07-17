// https://atcoder.jp/contests/abc296/tasks/abc296_e
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& from, vector<int>& visit, vector<int>& maxDepth, int x)
{
	if (maxDepth[x] == 0)
	{
		for (int y : from[x])
		{
			if (visit[y])
			{
				maxDepth[x] = INT_MAX;
			}
			else
			{
				visit[y] = 1;
				dfs(from, visit, maxDepth, y);
				visit[y] = 0;
				if (maxDepth[y] == INT_MAX)
				{
					maxDepth[x] = INT_MAX;
				}
				else
				{
					maxDepth[x] = max(maxDepth[x], maxDepth[y] + 1);
				}
			}
		}
	}
	return;
}
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> from(n + 1);
	vector<int> maxDepth(n + 1, 0);
	int to;
	for (int i = 1; i <= n; ++i)
	{
		cin >> to;
		from[to].push_back(i);
	}
	vector<int> visit(n + 1, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		visit[i] = 1;
		dfs(from, visit, maxDepth, i);
		visit[i] = 0;
		ans += (maxDepth[i] >= n && from[i].size() > 0 ? 1 : 0);
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
