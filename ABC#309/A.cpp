// https://atcoder.jp/contests/abc309/tasks/abc309_a
#include <iostream>
using namespace std;
void solve()
{
	int a, b;
	cin >> a >> b;
	if ((a - 1) / 3 == (b - 1) / 3)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
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
