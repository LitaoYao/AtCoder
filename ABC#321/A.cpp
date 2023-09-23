// https://atcoder.jp/contests/abc321/tasks/abc321_a
#include <iostream>
#include <string>
using namespace std;
void solve()
{
	string num;
	cin >> num;
	bool valid = true;
	int n = num.size();
	for (int i = 0; i < n - 1; ++i)
	{
		if (num[i] <= num[i + 1])
		{
			valid = false;
			break;
		}
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
