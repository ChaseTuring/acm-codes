#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e3+10;
const int M=1010;
int size[N],v[M][M];
int Next[2*N],head[N],ver[2*N],l[N],r[N],tot=0,dp[M];
void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
void add(int x,int y){
    ver[++tot]=y;
    Next[tot]=head[x];
    head[x]=tot;
}
void dfs(int s,int fa){
    if(s!=1)size[s]=1;
    for(int i=head[s];i;i=Next[i]){
        int v=ver[i];
        if(v==fa)continue;
        dfs(v,s);
        size[s]+=size[v];
        l[s]=min(l[s],l[v]);
        r[s]=max(r[s],r[v]);
    }
    v[l[s]][r[s]]=max(v[l[s]][r[s]],size[s]);
}
int main() {
    //redirect();
    int a,b,n,q;
    memset(l,0x3f,sizeof(l));
    memset(r,0,sizeof(r));
    scanf("%d%d",&n,&a);
    for(int i=2;i<=a;i++){
        scanf("%d",&q);
        add(i,q);
        add(q,i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&q),l[q]=r[q]=i;
    dfs(1,1);
    memset(l,0x3f,sizeof(l));
    memset(r,0,sizeof(r));
    memset(Next,0,sizeof(Next));
    memset(ver,0,sizeof(ver));
    memset(head,0,sizeof(head));
    scanf("%d",&b);
    tot=0;
    for(int i=2;i<=b;i++){
        scanf("%d",&q);
        add(i,q);
        add(q,i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&q),l[q]=r[q]=i;
    size[1]=0;
    dfs(1,1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            dp[i]=max(dp[i],dp[j]+v[j+1][i]);
        }
    }
    printf("%d",dp[n]);
}