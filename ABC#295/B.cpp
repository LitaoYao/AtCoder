// https://atcoder.jp/contests/abc295/tasks/abc295_b
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	char x;
	queue<vector<int>> q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> x;
			if (x == '.')
			{
				board[i][j] = 0;
			}
			else if (x == '#')
			{
				board[i][j] = -1;
			}
			else
			{
				board[i][j] = x - '0';
				q.push({i, j});
			}
		}
	}
	vector<vector<int>> ways = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	while (!q.empty())
	{
		vector<int> now = q.front();
		q.pop();
		for (vector<int>& way : ways)
		{
			vector<int> next = {now[0] + way[0], now[1] + way[1]};
			if (next[0] >= 0 && next[0] < n && next[1] >= 0 && next[1] < m)
			{
				if (board[next[0]][next[1]] < board[now[0]][now[1]] - 1)
				{
					board[next[0]][next[1]] = board[now[0]][now[1]] - 1;
					q.push(next);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << (board[i][j] >= 0 ? '.' : '#');
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
