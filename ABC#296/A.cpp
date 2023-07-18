// https://atcoder.jp/contests/abc296/tasks/abc296_a
#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	char x, y;
	cin >> x;
	bool valid = true;
	for (int i = 1; i < n; ++i)
	{
		cin >> y;
		if (x == y)
		{
			valid = false;
		}
		x = y;
	}
	cout << (valid ? "Yes" : "No") << endl;
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
