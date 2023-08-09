// https://atcoder.jp/contests/abc313/tasks/abc313_a
#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int score;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> score;
		if (0 == i)
		{
			ans = score * 1000;
		}
		else
		{
			ans = ans / 1000 * 1000 + max(ans % 1000, score - ans / 1000 + 1);
		}
	}
	cout << ans % 1000 << endl;
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
