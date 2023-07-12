// https://atcoder.jp/contests/abc295/tasks/abc295_a
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<string> patterns = {"and", "not", "that", "the", "you"};
	string str;
	bool valid = false;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (string pattern : patterns)
		{
			if (str == pattern)
			{
				valid = true;
				break;
			}
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
