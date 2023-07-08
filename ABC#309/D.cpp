// https://atcoder.jp/contests/abc309/tasks/abc309_c
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int maxPath(vector<vector<int>>& v, int node)
{
	queue<pair<int, int>> q;
	vector<int> visit(v.size());
	q.push({node, 0});
	visit[node] = 1;
	int ans = 0;
	while (!q.empty())
	{
		pair<int, int> nowNode = q.front();
		ans = nowNode.second;
		q.pop();
		for (int nextNode : v[nowNode.first])
		{
			if (visit[nextNode])
			{
				continue;
			}
			visit[nextNode] = 1;
			q.push({nextNode, nowNode.second + 1});
		}
	}
	return ans;
}
void solve()
{
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	vector<vector<int>> v1(n1 + 1);
	vector<vector<int>> v2(n2 + 1);
	int u, v;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		if (u <= n1)
		{
			v1[u].push_back(v);
			v1[v].push_back(u);
		}
		else
		{
			u -= n1;
			v -= n1;
			v2[u].push_back(v);
			v2[v].push_back(u);
		}
	}
	int a = maxPath(v1, 1);
	int b = maxPath(v2, n2);
	cout << a + b + 1 << endl;
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
