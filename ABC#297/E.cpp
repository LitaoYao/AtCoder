// https://atcoder.jp/contests/abc297/tasks/abc297_e
#include <iostream>
#include <vector>
#include <set>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<long long> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	set<long long> bases;
	set<long long> results;
	for (int i = 0; i < n; ++i)
	{
		bases.insert(nums[i]);
	}
	long long ans = 0;
	while (bases.begin() != bases.end())
	{
		long long now = *(bases.begin());
		for (int i = 0; i < n; ++i)
		{
			bases.insert(now + nums[i]);
		}
		bases.erase(now);
		results.insert(now);
		if ((int)results.size() >= k)
		{
			ans = now;
			break;
		}
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
