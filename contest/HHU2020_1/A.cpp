#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 200+10;

void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
int dp[N][N][N];
pair<pair<int,int>,pair<int,char> >path[N][N][N];
int main() {
    //redirect();
    int n,m,len,nxti,nxtj;
    string s,t;
    cin>>s;
    cin>>t;
    n=s.size();
    m=t.size();
    len=max(n,m);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=len;k++){
                nxti=i+(i<n&&s[i]=='(');
                nxtj=j+(j<m&&t[j]=='(');
                if(dp[nxti][nxtj][k+1]>dp[i][j][k]+1){
                    dp[nxti][nxtj][k+1]=dp[i][j][k]+1;
                    path[nxti][nxtj][k+1]=make_pair(make_pair(i,j),make_pair(k,'('));
                }
                nxti=i+(i<n&&s[i]==')');
                nxtj=j+(j<m&&t[j]==')');
                if(k>0&&dp[nxti][nxtj][k-1]>dp[i][j][k]+1){
                    dp[nxti][nxtj][k-1]=dp[i][j][k]+1;
                    path[nxti][nxtj][k-1]=make_pair(make_pair(i,j),make_pair(k,')'));
                }
            }
        }
    }
    int ans_k=0;
    for(int k=0;k<=len;k++){
        if(dp[n][m][k]+k<dp[n][m][ans_k]+ans_k){
            ans_k=k;
        }
    }
    int ni,nj,nk,cnt=ans_k+dp[n][m][ans_k],now_i=n,now_j=m,now_k=ans_k;
    char ans[2*N];
    ans[cnt]='\0';
    for(int i=0;i<ans_k;i++){
        ans[--cnt]=')';
    }
    while(now_i||now_j||now_k){
        ans[--cnt]=path[now_i][now_j][now_k].second.second;
        ni=path[now_i][now_j][now_k].first.first;
        nj=path[now_i][now_j][now_k].first.second;
        nk=path[now_i][now_j][now_k].second.first;
        now_i=ni;
        now_j=nj;
        now_k=nk;
    }
    printf("%s\n",ans);
}