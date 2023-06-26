// https://atcoder.jp/contests/abc293/tasks/abc293_d
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int findRoot(vector<int>& root, int x)
{
	if (root[x] != x)
	{
		root[x] = findRoot(root, root[x]);
	}
	return root[x];
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> root(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		root[i] = i;
	}
	int a, b;
	char c;
	int X = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> c >> b >> c;
		int aRoot = findRoot(root, a);
		int bRoot = findRoot(root, b);
		if (aRoot != bRoot)
		{
			root[aRoot] = bRoot;
		}
		else
		{
			++X;
		}
	}
	set<int> roots;
	for (int i = 1; i <= n; ++i)
	{
		roots.insert(findRoot(root, i));
	}
	cout << X << " " << roots.size() - X << endl;
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
