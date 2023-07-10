// https://atcoder.jp/contests/abc309/tasks/abc309_b
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0)
			{
				if (j > 0)
				{
					cout << grid[i][j - 1];
				}
				else
				{
					cout << grid[i + 1][j];
				}
			}
			else if (j == 0)
			{
				if (i < n - 1)
				{
					cout << grid[i + 1][j];
				}
				else
				{
					cout << grid[i][j + 1];
				}
			}
			else if (i == n - 1)
			{
				if (j < n - 1)
				{
					cout << grid[i][j + 1];
				}
				else
				{
					cout << grid[i - 1][j];
				}
			}
			else if (j == n - 1)
			{
				if (i > 0)
				{
					cout << grid[i - 1][j];
				}
				else
				{
					cout << grid[i][j - 1];
				}
			}
			else
			{
				cout << grid[i][j];
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
