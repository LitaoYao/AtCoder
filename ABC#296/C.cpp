// https://atcoder.jp/contests/abc296/tasks/abc296_c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	long long n, x;
	cin >> n >> x;
	x = abs(x);
	vector<long long> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		int left = 0;
		int right = i;
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (nums[i] - nums[mid] > x)
			{
				left = mid + 1;
			}
			else if (nums[i] - nums[mid] < x)
			{
				right = mid - 1;
			}
			else
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
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
