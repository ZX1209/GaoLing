/*
�����У�ans�������ڼ�¼ʹ��i�š�1����j�š�2����k�š�3����l�š�4��ʱ�����÷�
s1��s4���ڼ�¼��1����2����3����4�����Եĸ�����֮��4��ѭ������������
*/
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int ans[41][41][41][41] = {}, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
int main() {
    int n, m, a[351], b, i, j, k, l;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= m; i++) {
        scanf("%d", &b);
        if (b == 1) s1++;
        if (b == 2) s2++;
        if (b == 3) s3++;
        if (b == 4) s4++;
    }
    ans[0][0][0][0] = a[1];
    for (i = 0; i <= s1; i++)
        for (j = 0; j <= s2; j++)
            for (k = 0; k <= s3; k++)
                for (l = 0; l <= s4; l++) {
                    int x = 1 + i + j * 2 + k * 3 + l * 4;
                    if (i) ans[i][j][k][l] = max(ans[i][j][k][l], ans[i - 1][j][k][l] + a[x]);
                    if (j) ans[i][j][k][l] = max(ans[i][j][k][l], ans[i][j - 1][k][l] + a[x]);
                    if (k) ans[i][j][k][l] = max(ans[i][j][k][l], ans[i][j][k - 1][l] + a[x]);
                    if (l) ans[i][j][k][l] = max(ans[i][j][k][l], ans[i][j][k][l - 1] + a[x]);
                }
    printf("%d\n", ans[s1][s2][s3][s4]);
    return 0;
}
