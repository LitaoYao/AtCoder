// https://atcoder.jp/contests/abc294/tasks/abc294_d
#include <iostream>
#include <set>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	int index = 1;
	int x, y;
	set<int> s;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		if (x == 1)
		{
			s.insert(index++);
		}
		if (x == 2)
		{
			cin >> y;
			s.erase(y);
		}
		if (x == 3)
		{
			cout << *s.begin() << endl;
		}
	}
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
