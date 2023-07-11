// https://atcoder.jp/contests/abc309/tasks/abc309_f
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
	Node(int from, int to): from(from), to(to), value(INT_MAX), left(nullptr), right(nullptr) {}
	int from;
	int to;
	int value;
	Node* left;
	Node* right;
	int mid()
	{
		return (from + to) >> 1;
	}
};
class SegmentTree
{
public:
	SegmentTree(int from, int to)
	{
		root = new Node(from, to);
	}
	void update(int pos, int value)
	{
		update(root, pos, value);
	}
	int quest(int from, int to)
	{
		return quest(root, from, to);
	}
private:
	void ensure(Node* node)
	{
		if (node->from == node->to)
		{
			return;
		}
		int mid = node->mid();
		if (nullptr == node->left)
		{
			node->left = new Node(node->from, mid);
		}
		if (nullptr == node->right)
		{
			node->right = new Node(mid + 1, node->to);
		}
	}
	void update(Node* node, int pos, int value)
	{
		if (nullptr == node)
		{
			return;
		}
		ensure(node);
		node->value = min(node->value, value);
		int mid = node->mid();
		if (pos <= mid)
		{
			update(node->left, pos, value);
		}
		else
		{
			update(node->right, pos, value);
		}
	}
	int quest(Node* node, int from, int to)
	{
		if (node->from == from && node->to == to)
		{
			return node->value;
		}
		ensure(node);
		int ans = INT_MAX;
		int mid = node->mid();
		if (from <= mid)
		{
			ans = min(ans, quest(node->left, from, min(mid, to)));
		}
		if (to > mid)
		{
			ans = min(ans, quest(node->right, max(from, mid + 1), to));
		}
		return ans;
	}
	Node* root;
};
bool cmp(vector<int>& a, vector<int>& b)
{
	if (a[0] != b[0])
	{
		return a[0] < b[0];
	}
	return a[1] > b[1];
}
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> boxes(n, vector<int>(3));
	for (int i = 0; i < n; ++i)
	{
		cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
		// sort to make sure h <= w <= d
		sort(boxes[i].begin(), boxes[i].end(), less<int>());
	}
	// compress length to 0 ~ n-1
	for (int j = 0; j < 3; ++j)
	{
		vector<int> tmp(n);
		for (int i = 0; i < n; ++i)
		{
			tmp[i] = boxes[i][j];
		}
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < n; ++i)
		{
			int index = lower_bound(tmp.begin(), tmp.end(), boxes[i][j]) - tmp.begin();
			boxes[i][j] = index;
		}
	}
	// use segment tree to maintain minimum d of 0 ~ i-1 by interval w
	// quest the minimum d by interval [0, w_i) and judge if d_i is strickly greater than it
	SegmentTree tree(0, n - 1);
	sort(boxes.begin(), boxes.end(), cmp);
	bool valid = false;
	for(int i = 0; i < n; ++i)
	{
		if (boxes[i][1] > 0)
		{
			int value = tree.quest(0, boxes[i][1] - 1);
			if (value < boxes[i][2])
			{
				valid = true;
				break;
			}
		}
		tree.update(boxes[i][1], boxes[i][2]);
	}
	cout << (valid ? "Yes" : "No") << endl;
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

