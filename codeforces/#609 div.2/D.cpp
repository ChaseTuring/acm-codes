#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 3e5+10;

void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
ll a[2];
int main() {
    //redirect();
    ll ans=0;
    int n,len;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&len);
        a[1]+=len/2;
        a[0]+=len/2;
        a[i%2]+=len%2;
    }
    ans=min(a[0],a[1]);
    printf("%lld\n",ans);
}