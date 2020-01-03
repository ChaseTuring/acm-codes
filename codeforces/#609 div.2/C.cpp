#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-5;
const int N = 2e5 + 10;
char s[N];
int n, m;
void redirect() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
}
void add(int x,int y,int z) {
    int i = x;
    while (s[i] == '9') {
        s[i] = '0';
        i--;
    }
    s[i]++;
    if(i<=y){
        for (int j = y-m+1; j + m <= z; j++) s[j + m] = s[j];
    }
    s[x + 1] = s[x + 1 - m];
}
int main() {
    //redirect();
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    s[0] = '0';
    if (n / m > 1) {
        int num = n / m;
        for(int i=n;i>num*m;i--){
            if (s[i] < s[i - m]) {
                s[i] = s[i - m];
            }
            else if (s[i] > s[i - m]) {
                add(i - 1,num*m,n);
            }
        }
        for(int i=num*m;i>(num-1)*m;i--){
            if (s[i] < s[i - m]) {
                s[i] = s[i - m];
            }
            else if (s[i] > s[i - m]) {
                add(i - 1,(num-1)*m,num*m);
            }
            if(i==(num-1)*m+1)num--;
            if(num==1)break;
        }
        printf("%d\n",n);
        for (int i = 0;; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%c", s[j]);
                if (i * m + j >= n) {
                    printf("\n");
                    return 0;
                }
            }
        }
    }
    else {
        for (int i = n; i >= m + 1; i--) {
            if (s[i] < s[i - m]) {
                s[i] = s[i - m];
            }
            else if (s[i] > s[i - m]) {
                add(i - 1,m,n);
            }
        }
        printf("%d\n%s\n", n, s + 1);
    }
    return 0;
}