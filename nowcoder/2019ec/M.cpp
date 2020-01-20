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
int a[N],b[N],n;
bool book[N];
struct adi{
    int val,k;
};
ll find(int m){
    int now=m,cnt=0,num;
    adi c[100],add[100],p;
    ll res=0,maxv=0;
    while(now<=n){
        p.val=now;
        p.k=cnt+1;
        c[cnt++]=p;
        book[now]=1;
        now*=m;
    }
    int choice=1<<cnt;
    for(int i=0;i<choice;i++){
        num=res=0;
        for(int j=0;j<cnt;j++){
            if(i>>j&1){
                res+=a[c[j].val];
                add[num++]=c[j];
            }
        }
        for(int j=0;j<num;j++){
            for(int l=0;l<j;l++){
                if(add[j].k%add[l].k==0){
                    res-=b[add[j].val];
                }
            }
        }
        maxv=max(res,maxv);
    }
    return maxv;
}
int main() {
    //redirect();
    ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    ans+=a[1];
    for(int i=2;i<=n;i++){
        if(book[i])continue;
        if((ll)i*i>n)ans+=a[book[i]],book[i]=1;
        else {
            ans+=find(i);
        }
    }
    printf("%lld\n",ans);
}