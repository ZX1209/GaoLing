/*
˼·: (��̬�滮)
	����: dp[i] ��ʾ i ���߶ε�����ֵ��
	��ʼ״̬: ȫ����Ϊ 0
	״̬ת�Ʒ���:
	dp[i] = max(dp[j]) + c[i] (j = 0 .. i - 1 �� �߶� i �� �߶� j ���ཻ)
	���: max(dp[i]) (i = 0 .. n - 1)
	ע: Ӧ�Ȱ��Ҷ�������
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
