#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int M = 5e4+10;
const int N=2000+10;
void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
int head[N],ver[M],Next[M],tot,inder[N];
int n,m;
int input[N],visit[N],to[N];
bitset<N>can[N];
void add(int x,int y){
    ver[++tot]=y;
    Next[tot]=head[x];
    head[x]=tot;
}
bool cmp(int a,int b){
    return visit[a]<visit[b];
}
void topo(){
    queue<int>q;
    int ans=0,num=0;
    for(int i=1;i<=n;i++){
        if(inder[i]==0){
            q.push(i);
            visit[i]=++num;
            input[num]=i;
        }
        can[i]&=0;
    }
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int i=head[v];i;i=Next[i]){
            int x=ver[i];
            inder[x]--;
            if(inder[x]==0){
                q.push(x);
                visit[x]=++num;
                input[num]=x;
            }
        }
    }
    int cnt=0;
    for(int j=n;j>=1;j--){
        cnt=0;
        int x=input[j];
        can[x][x]=1;
        for(int i=head[x];i;i=Next[i]){
            int v=ver[i];
            to[cnt++]=v;
        }
        sort(to,to+cnt,cmp);
        for(int k=0;k<cnt;k++){
            if(can[x][to[k]])ans++;
            else can[x]|=can[to[k]];
        }
    }
    printf("%d\n",ans);
}
int main() {
    //redirect();
    int t,x,y;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        tot=0;
        memset(head,0,sizeof(head));
        memset(ver,0,sizeof(ver));
        memset(Next,0,sizeof(Next));
        memset(inder,0,sizeof(inder));
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++){
            scanf("%d%d",&x,&y);
            add(x,y);
            inder[y]++;
        }
        topo();
    }
}