// https://atcoder.jp/contests/abc313/tasks/abc313_c
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> nums(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		sum += nums[i];
	}
	long long target = sum / n;
	// target * x + (target + 1) * (n - x) = sum
	// target * x + (target + 1) * n - (target + 1) * x = sum
	// x = (target + 1) * n - sum
	int x = (target + 1) * n - sum;
	long long ans = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < x; ++i)
	{
		ans += abs(nums[i] - target);
	}
	for (int i = x; i < n; ++i)
	{
		ans += abs(target + 1 - nums[i]);
	}
	ans /= 2;
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
