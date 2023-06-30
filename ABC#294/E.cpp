// https://atcoder.jp/contests/abc294/tasks/abc294_e
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	long long L, N1, N2;
	cin >> L >> N1 >> N2;
	vector<pair<int, long long>> A1(N1);
	vector<pair<int, long long>> A2(N2);
	int v;
	long long l;
	for (int i = 0; i < N1; ++i)
	{
		cin >> v >> l;
		A1[i] = {v, l};
	}
	for (int i = 0; i < N2; ++i)
	{
		cin >> v >> l;
		A2[i] = {v, l};
	}
	long long index1 = 0, index2 = 0;
	long long ans = 0;
	for (int i = 0, j = 0; i < N1 || j < N2;)
	{
		if (index1 <= index2)
		{
			if (j > 0 && A1[i].first == A2[j - 1].first)
			{
				ans += min(index1 + A1[i].second, index2) - index1;
			}
			index1 += A1[i++].second;
		}
		else
		{
			if (i > 0 && A1[i - 1].first == A2[j].first)
			{
				ans += min(index1, index2 + A2[j].second) - index2;
			}
			index2 += A2[j++].second;
		}
	}
	cout << ans << endl;
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
