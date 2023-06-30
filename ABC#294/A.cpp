// https://atcoder.jp/contests/abc294/tasks/abc294_a
#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if ((x & 1) == 0)
		{
			cout << x << " ";
		}
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
