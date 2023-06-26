// https://atcoder.jp/contests/abc293/tasks/abc293_b
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> nums[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		nums[nums[i]] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (nums[i] != 0)
		{
			++ans;
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n; ++i)
	{
		if (nums[i] != 0)
		{
			cout << i << " ";
		}
	}
	cout << endl;
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
