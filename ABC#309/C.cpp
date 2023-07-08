// https://atcoder.jp/contests/abc309/tasks/abc309_c
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b)
{
	return a.first > b.first;
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<pair<long long, long long>> medicines(n);
	long long a, b;
	long long maxDay = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		medicines[i] = {a, b};
		maxDay = max(maxDay, a);
	}
	sort(medicines.begin(), medicines.end(), cmp);
	medicines.push_back({0, 0});
	long long pills = 0;
	long long ans = maxDay + 1;
	for (int i = 0; i < n;)
	{
		int j = i;
		long long tmp = 0;
		while (j < n && medicines[i].first == medicines[j].first)
		{
			tmp += medicines[j].second;
			++j;
		}
		if (pills + tmp > k)
		{
			break;
		}
		ans = medicines[j].first + 1;
		pills += tmp;
		i = j;
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
