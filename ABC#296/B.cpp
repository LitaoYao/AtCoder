// https://atcoder.jp/contests/abc296/tasks/abc296_b
#include <iostream>
using namespace std;
void solve()
{
	int n = 8;
	char x;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> x;
			if (x == '*')
			{
				cout << char('a' + j - 1) << n - i + 1 << endl;
			}
		}
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
