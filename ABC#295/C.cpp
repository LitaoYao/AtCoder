// https://atcoder.jp/contests/abc295/tasks/abc295_c
#include <iostream>
#include <map>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	map<int, int> nums;
	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		++nums[x];
	}
	int ans = 0;
	for (auto& iter : nums)
	{
		ans += iter.second / 2;
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
