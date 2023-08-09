// https://atcoder.jp/contests/abc313/tasks/abc313_e
#include <iostream>
#include <string>
using namespace std;
const int MOD = 998244353;
void solve()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	bool valid = true;
	for (int i = 0; i < n - 1; ++i)
	{
		if ('1' != s[i] && '1' != s[i + 1])
		{
			valid = false;
			break;
		}
	}
	if (!valid)
	{
		cout << -1;
	}
	else
	{
		long long ans = 0;
		for (int i = n - 1; i > 0; --i)
		{
			// To erase each s[i], we must cost (s[i] - '0' - 1) * (ans + 1) + 1 times.
			// Here (s[i] - '0' - 1) * (ans + 1) is the count of '1' duplicated by s[i].
			ans = (ans + (s[i] - '0' - 1) * (ans + 1) + 1) % MOD;
		}
		cout << ans << endl;
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
