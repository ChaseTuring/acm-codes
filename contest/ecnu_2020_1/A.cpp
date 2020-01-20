#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
}
int ans[20], cnt = -2, res;
bool check() {
    if (ans[8] * 10 + ans[9] > 24) return false;
    if (ans[10] * 10 + ans[11] > 59) return false;
    if (ans[12] * 10 + ans[13] > 59) return false;
    return true;
}
void solve() {
    int x;
    for (int i = 2020; i <= 9999; i++) {
        x = i;
        for (int t = 3; t >= 0; t--) {
            ans[t] = x % 10;
            x /= 10;
        }
        for (int j = 1; j <= 12; j++) {
            x = j;
            for (int t = 5; t >= 4; t--) {
                ans[t] = x % 10;
                x /= 10;
            }
            for (int k = 1; k <= 2; k++) {
                ans[6] = ans[7] = k;
                for (int l = 8; l < 14; l++) {
                    ans[l] = ans[13 - l];
                }
                if (check())
                    cnt++;
                else
                    continue;
                if (cnt == res) {
                    for (int s = 0; s < 14; s++) {
                        printf("%d", ans[s]);
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }
}
int main() {
    // redirect();
    scanf("%d", &res);
    solve();
}