// https://atcoder.jp/contests/abc309/tasks/abc309_e
#include <iostream>
#include <vector>
using namespace std;
int dfs(int x, vector<vector<int>>& childs, vector<int>& gens)
{
	int count = 0;
	if (gens[x] > 0)
	{
		++count;
	}
	for (int child : childs[x])
	{
		if (gens[child] < gens[x] - 1)
		{
			gens[child] = gens[x] - 1;
		}
		count += dfs(child, childs, gens);
	}
	return count;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> childs(n + 1);
	int p;
	for (int i = 2; i <= n; ++i)
	{
		cin >> p;
		childs[p].push_back(i);
	}
	vector<int> gens(n + 1);
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		gens[x] = max(gens[x], y + 1);
	}
	cout << dfs(1, childs, gens) << endl;
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
