// https://atcoder.jp/contests/abc297/tasks/abc297_d
#include <iostream>
using namespace std;
long long deal(long long& A, long long& B)
{
	long long count = A / B;
	A = A % B;
	if (A == 0)
	{
		A = B;
		--count;
	}
	return count;
}
void solve()
{
	long long A, B;
	cin >> A >> B;
	long long ans = 0;
	while (A != B)
	{
		if (A > B)
		{
			ans += deal(A, B);
		}
		else
		{
			ans += deal(B, A);
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
