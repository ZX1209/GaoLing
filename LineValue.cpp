/*
思路: (动态规划)
	定义: dp[i] 表示 i 条线段的最大价值和
	初始状态: 全部置为 0
	状态转移方程:
	dp[i] = max(dp[j]) + c[i] (j = 0 .. i - 1 且 线段 i 与 线段 j 不相交)
	结果: max(dp[i]) (i = 0 .. n - 1)
	注: 应先按右顶点排序
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct line {
	int left, right, c;
};

int comp(line a, line b) {
	return a.right < b.right;
}

int main() {
	int n;
	cin >> n;
	line a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].left >> a[i].right >> a[i].c;
	sort(a, a + n, comp);
	int dp[n];
	memset(dp, 0, sizeof(dp));
	int result = 0;
	for (int i = 0; i < n; i++) {
		int _max = 0;
		for (int j = 0; j < i; j++)
			if (a[i].left >= a[j].right)
				_max = max(_max, dp[j]);
		dp[i] = _max + a[i].c;
		result = max(result, dp[i]);
	}
	cout << result << endl;
	return 0;
}
