// https://atcoder.jp/contests/abc313/tasks/abc313_d
#include <iostream>
#include <vector>
using namespace std;
int query(vector<int>& indexs)
{
	cout << "? ";
	for (int index : indexs)
	{
		cout << index << " ";
	}
	cout << endl;
	cout << flush;
	int parity;
	cin >> parity;
	return parity;
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> nums(n + 1);
	nums[1] = 0;
	int lastParity = -1;
	int firstParity = 0;
	for (int i = 1; i <= n - k + 1; ++i)
	{
		vector<int> indexs;
		indexs.push_back(i);
		for (int j = n - k + 2; j <= n; ++j)
		{
			indexs.push_back(j);
		}
		int parity = query(indexs);
		if (-1 == lastParity)
		{
			firstParity = parity;
		}
		else
		{
			if (parity == lastParity)
			{
				nums[i] = nums[i - 1];
			}
			else
			{
				nums[i] = nums[i - 1] ^ 1;
			}
		}
		lastParity = parity;
	}
	for (int i = n - k + 2; i <= n; ++i)
	{
		vector<int> indexs;
		indexs.push_back(1);
		indexs.push_back(2);
		for (int j = n - k + 2; j <= n; ++j)
		{
			if (j == i)
			{
				continue;
			}
			indexs.push_back(j);
		}
		int parity = query(indexs);
		if (parity == firstParity)
		{
			nums[i] = nums[2];
		}
		else
		{
			nums[i] = nums[2] ^ 1;
		}
	}
	int check = nums[1];
	for (int j = n - k + 2; j <= n; ++j)
	{
		check ^= nums[j];
	}
	if (check != firstParity)
	{
		for (int i = 1; i <= n; ++i)
		{
			nums[i] = nums[i] ^ 1;
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	cout << flush;
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
	// fastRead();
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
