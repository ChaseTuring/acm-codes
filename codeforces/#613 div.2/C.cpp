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
    int x,ans,i;
    scanf("%d",&x);
    for(i=sqrt(x)+1;;i++){
        if(x%i==0){
            ans=max(i,x/i);
            break;
        }
    }
    printf("%d %d\n",x/ans,ans);
}