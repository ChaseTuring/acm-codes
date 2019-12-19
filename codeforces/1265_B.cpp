#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5+10;
int pos[N],ans[N];
int main(){
	int n,t,x,ori,now,dis,l,r;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)ans[i]=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			pos[x]=i;
			if(x==1)ori=i;
		}
		l=r=ori;
		now=0;
		for(int i=2;i<=n;i++){
			if(pos[i]<l){
				dis=l-pos[i];
			}
			else if(r<pos[i])dis=pos[i]-r;
			else dis=0;
			if(dis>i-(r-l+1)){
				for(int j=max(i,now);j<r-l+1+dis;j++)ans[j]=0;
				now=r-l+1+dis-1;
				
			}
			if(pos[i]<l){
				l=pos[i];
			}
			else if(r<pos[i])r=pos[i];
		}
		for(int i=1;i<=n;i++)printf("%d",ans[i] );
		printf("\n");
	}
}