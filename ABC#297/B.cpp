// https://atcoder.jp/contests/abc297/tasks/abc297_b
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	vector<int> b;
	vector<int> r;
	int k;
	char ch;
	for (int i = 0; i < 8; ++i)
	{
		cin >> ch;
		if (ch == 'B')
		{
			b.push_back((i & 1));
		}
		if (ch == 'R')
		{
			r.push_back(i);
		}
		if (ch == 'K')
		{
			k = i;
		}
	}
	bool valid = true;
	if (b[0] == b[1])
	{
		valid = false;
	}
	if (!(r[0] < k && k < r[1]))
	{
		valid = false;
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
