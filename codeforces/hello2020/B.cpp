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
int minv[N],maxv[N],a[N];
bool book[N];
int main() {
    //redirect();
    bool flag;
    int n,m,x,mini,maxi,pos,cnt=0;
    ll ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        mini=INF;
        maxi=0;
        flag=false;
        scanf("%d",&x);
        mini=x;
        maxi=x;
        for(int j=1;j<m;j++){
            scanf("%d",&x);
            if(x>mini){
                if(!flag)
                    flag=true;
                if(x>maxi)maxi=x;
            }
            else if(x<mini)mini=x;
        }
        minv[i]=mini;
        maxv[i]=maxi;
        if(flag)a[cnt++]=mini,book[i]=true;
    }
    sort(minv,minv+n);
    for(int i=0;i<n;i++){
        if(book[i])ans+=n;
        else{
            pos=lower_bound(minv,minv+n,maxv[i])-minv;
            if(pos>=n)pos--;
            while(minv[pos]>=maxv[i]&&pos)pos--;
            if(minv[pos]==maxv[i]){
                ans+=pos;
            }
            else ans+=pos+1;
            pos=lower_bound(a,a+cnt,maxv[i])-a;
            if(pos>=cnt)pos--;
            if(a[pos]>=maxv[i])ans+=cnt-pos;
        }
    }
    printf("%lld\n",ans);
}