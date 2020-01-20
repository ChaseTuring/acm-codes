#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}

int main() {
    //redirect();
    int n,m,num_n=0,num_m=0;
    ll ans=0;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i+=2){
        ans+=(n-i+1)*(m+1);
        num_n+=(n-i+1);
    }
    for(int i=2;i<=m;i+=2){
        ans+=(m-i+1)*(n+1);
        num_m+=(m-i+1);
    }
    for(int i=2;i<=n;i+=2){
        ans+=2*(n-i+1)*num_m;
    }
    printf("%lld\n",ans);
}