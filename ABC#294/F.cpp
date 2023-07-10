// https://atcoder.jp/contests/abc294/tasks/abc294_f
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const double eps = 1e-13;
void solve()
{
	long long n, m, k;
	cin >> n >> m >> k;
	vector<pair<long long, long long>> a(n);
	vector<pair<long long, long long>> b(m);
	vector<double> c(m);
	long long x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		a[i] = {x, y};
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		b[i] = {x, y};
	}
	// first we can binary search the answer between 0 and 1.
	// and the end condition is the difference of left and right is lower then eps.
	double left = 0, right = 1;
	while ((right - left) > eps)
	{
		double mid = (left + right) / 2;
		// now the target concentration is mid
		// and for each b[i], the concentration is b[i].first / (b[i].first + b[i].second)
		// if b[i] is tend to reach mid concentration, b[i] must add c[i] suger(here we assume c[i] can be a negative number, which means the concentration of b[i] is higher than mid)
		// where (b[i].first + c[i]) / (b[i].first + c[i] + b[i].second) = mid
		// => b[i].first + c[i] = mid * (b[i].first + c[i] + b[i].second)
		// => b[i].first + c[i] = mid * (b[i].first + b[i].second) + mid * c[i]
		// => c[i] - mid * c[i] = mid * (b[i].first + b[i].second) - b[i].first
		// => (1 - mid) * c[i] = mid * b[i].second - (1 - mid) * b[i].first
		// => c[i] = mid / (1 - mid) * b[i].second - b[i].first
		double x = mid / (1 - mid); 
		for (int i = 0; i < m; ++i)
		{
			c[i] = b[i].second * x - b[i].first;
		}
		sort(c.begin(), c.end());
		long long count = 0;
		for (int i = 0; i < n; ++i)
		{
			// with the same thinking, a[i] can reduce a[i].first - a[i].second * x suger to reach mid concentration
			// so this remaining suger can be added to b[i]
			// then the problem is convert to find out how many b[i] can reach mid concentration after add a[i].first - a[i].second * x suger
			// and it's an obvious binary search problem.
			double target = a[i].first - a[i].second * x;
			count += lower_bound(c.begin(), c.end(), target) - c.begin();
		}
		if (count >= k)
		{
			left = mid;
		}
		else if (count < k)
		{
			right = mid;
		}
	}
	printf("%.10lf\n", left * 100);
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
