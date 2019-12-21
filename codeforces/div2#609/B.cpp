#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-5;
const int N = 1e5 + 10;
int a[2010], b[2010], res[2010];
int n, m;

void redirect() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
}
inline bool judge(int now) {
    for (int i = 0; i < n; i++) {
        res[i] = (a[i] + now) % m;
    }
    sort(res, res + n);
    for (int i = 0; i < n; i++) {
        if (res[i] != b[i]) return false;
    }
    return true;
}
int main() {
    int ans = INF, now, x;
    //redirect();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i] = x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        b[i] = x;
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (a[i] > b[0]) {
            now = m - a[i] + b[0];
        } else {
            now = b[0] - a[i];
        }
        if (judge(now)) {
            ans = min(ans, now);
        }
    }
    printf("%d\n", ans);
}