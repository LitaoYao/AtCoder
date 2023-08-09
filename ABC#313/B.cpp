// https://atcoder.jp/contests/abc313/tasks/abc313_b
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<bool> loser(n + 1, false);
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		loser[y] = true;
	}
	int winner = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!loser[i])
		{
			if (winner)
			{
				winner = -1;
				break;
			}
			else
			{
				winner = i;
			}
		}
	}
	cout << winner << endl;
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
