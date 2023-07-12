// https://atcoder.jp/contests/abc295/tasks/abc295_d
#include <iostream>
#include <string>
#include <map>
using namespace std;
void solve()
{
	string str;
	cin >> str;
	map<long long, long long> counts;
	// bits refers to counts of num module 2
	// it has 10 bits
	long long bits = 0;
	++counts[bits];
	for (char c : str)
	{
		bits ^= 1 << (c - '0');
		++counts[bits];
	}
	long long ans = 0;
	for (auto& iter : counts)
	{
		// the interval between the same bits can be a happy string
		ans += (iter.second * (iter.second - 1)) >> 1;
	}
	cout << ans << endl;
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
