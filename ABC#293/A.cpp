// https://atcoder.jp/contests/abc293/tasks/abc293_a
#include <iostream>
#include <string>
using namespace std;
void solve()
{
	string str;
	cin >> str;
	int n = str.size();
	for (int i = 0; i < n; i += 2)
	{
		swap(str[i], str[i + 1]);
	}
	cout << str << endl;
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
