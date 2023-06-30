// https://atcoder.jp/contests/abc294/tasks/abc294_b
#include <iostream>
using namespace std;
void solve()
{
	int h, w;
	cin >> h >> w;
	int x;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> x;
			if (x > 0)
			{
				cout << char('A' + x - 1);
			}
			else
			{
				cout << '.';
			}
		}
		cout << endl;
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
