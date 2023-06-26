// https://atcoder.jp/contests/abc293/tasks/abc293_e
#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> matrixMultipleWithModule(vector<vector<long long>>& A, vector<vector<long long>>& B, long long M)
{
	int n = A.size();
	int m = B[0].size();
	int t = B.size();
	vector<vector<long long>> ans(n, vector<long long>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < t; ++k)
			{
				ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return ans;
}
vector<vector<long long>> fastMultipleMatrixWithModule(vector<vector<long long>>& A, long long N, long long M)
{
	if (N == 1)
	{
		return A;
	}
	vector<vector<long long>> X;
	X = fastMultipleMatrixWithModule(A, N / 2, M);
	if ((N & 1) == 0)
	{
		X = matrixMultipleWithModule(X, X, M);
	}
	else
	{
		X = matrixMultipleWithModule(X, X, M);
		X = matrixMultipleWithModule(X, A, M);
	}
	return X;
}
void solve()
{
	long long A, N, M;
	cin >> A >> N >> M;
	/*
	 * S[n] = sum(A^0 + ... + A^(n - 1))
	 * =>
	 * S[n] = A * S[n - 1] + 1
	 * =>
	 *  | S[n] | = | A  1 |    *  |S[n-1]| 
	 *  |  1   |   | 0  1 |       |  1   |  
	 * =>
	 *  | S[n] | = | A  1 |^N  *  | S[0] |
	 *  |  1   |   | 0  1 |       |  1   |   
	 * =>
	 *  | S[n] | = | A  1 |^N  *  |  0   |
	 *  |  1   |   | 0  1 |       |  1   |   
	 * =>
	 * ans = | A  1 |^N
	 *       | 0  1 |  
	 * S[n] = ans[0][1]
	 */
	vector<vector<long long>> matrix = {
		{A, 1},
		{0, 1}
	};
	vector<vector<long long>> ans = fastMultipleMatrixWithModule(matrix, N, M);
	cout << ans[0][1] % M << endl;
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
