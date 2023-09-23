// https://atcoder.jp/contests/abc321/tasks/abc321_b
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n;
	int totalScore;
	cin >> n >> totalScore;
	vector<int> scores(n - 1);
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> scores[i];
	}
	int ans = -1;
	for (int score = 0; score <= 100; ++score)
	{
		vector<int> tmpScores(n);
		for (int i = 0; i < n; ++i)
		{
			tmpScores[i] = scores[i];
		}
		tmpScores[n - 1] = score;
		sort(tmpScores.begin(), tmpScores.end());
		int tmpTotalScore = 0;
		for (int i = 1; i < n - 1; ++i)
		{
			tmpTotalScore += tmpScores[i];
		}
		if (tmpTotalScore >= totalScore)
		{
			ans = score;
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
