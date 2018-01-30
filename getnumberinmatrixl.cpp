#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 80 + 1;
const int MAXM = 80 + 1;
const int SIZE = 100 + 1; 

string add(string s1, string s2) {
    int a[SIZE] = { 0 }, b[SIZE] = { 0 }, c[SIZE] = { 0 };
    int size_a = s1.size(), size_b = s2.size();
    for (int i = 0; i < size_a; i++) a[size_a - i] = s1[i] - '0';
    for (int i = 0; i < size_b; i++) b[size_b - i] = s2[i] - '0';
    int size_c = 1, x = 0;
    while (size_c <= size_a || size_c <= size_b) {
        c[size_c] = a[size_c] + b[size_c] + x;
        x = c[size_c] / 10;
        c[size_c] %= 10;
        size_c++;
    }
    c[size_c] = x;
    while (size_c > 1 && c[size_c] == 0) size_c--;
    string res;
    res.resize(size_c);
    for (int i = size_c; i >= 1; i--) res[size_c - i] = c[i] + '0';
    return res;
}

string mul(string s1, string s2) {
    int a[SIZE] = { 0 }, b[SIZE] = { 0 }, c[SIZE] = { 0 };
    int size_a = s1.size(), size_b = s2.size();
    for (int i = 0; i < size_a; i++) a[size_a - i] = s1[i] - '0';
    for (int i = 0; i < size_b; i++) b[size_b - i] = s2[i] - '0';  
    for (int i = 1; i <= size_a; i++) {
        int x = 0;
        for (int j = 1; j <= size_b; j++) {
            int now = i + j - 1;
            c[now] += a[i] * b[j] + x;
            x = c[now] / 10;
            c[now] %= 10;
        }
        c[i + size_b] = x;
    }
    int size_c = size_a + size_b;
    while (size_c > 1 && c[size_c] == 0) size_c--;
    string res;
    res.resize(size_c);
    for (int i = size_c; i >= 1; i--) res[size_c - i] = c[i] + '0';
    return res;
}

int n, m;
string a[MAXM], pow2[MAXM], f[MAXN][MAXM], ans;

inline string max(string a, string b) {
    if (a.size() > b.size()) return a;
    if (a.size() < b.size()) return b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) return a;
        if (a[i] < b[i]) return b;
    }
    return a;
}

int main(int argc, char *argv[]) {
    cin >> n >> m;
    pow2[0] = "1";
    for (int i = 1; i <= m; i++) pow2[i] = mul(pow2[i - 1], "2");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[j];
            f[j][j] = mul(pow2[m], a[j]);
        }
        for (int d = 1; d <= m - 1; d++) {
            for (int l = 1; l <= m - d; l++) {
                int r = l + d;       
                f[l][r] = max(add(f[l + 1][r], mul(pow2[m - d], a[l])), add(f[l][r - 1], mul(pow2[m - d], a[r])));
            }
        }
        ans = add(ans, f[1][m]);
    }
    cout << ans << endl;
    return 0;
}
