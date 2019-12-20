#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
bool a[2*N];
int b[2*N];
map <int,int>c;
map <int,bool>book;
int main(){
	int t,n,res,now,req,red,blue,ans,x;
	scanf("%d",&t);
	while(t--){
		red=blue=0;
		memset(b,0,sizeof(b));
		book.clear();
		c.clear();
		scanf("%d",&n);
		for(int i=0;i<2*n;i++){
			scanf("%d",&x);
			if(x==1)a[i]=0;
			else a[i]=1;
			if(a[i])red++;
			else blue++;
		}
		for(int i=n-1;i>=0;i--){
			if(a[i])b[i]=b[i+1]+1;
			else b[i]=b[i+1]-1;
		}
		c[0]=n;
		book[0]=1;
		for(int i=n-1;i>=0;i--){
			if(!book.count(b[i])){
				c[b[i]]=i;
				book[b[i]]=1;
			}
		}
		req=red-blue;
		now=0;
		ans=INF;
		if(c.count(req-now)){
			res=n-c[req-now];
			ans=min(res,ans);
		}
		for(int i=n;i<2*n;i++){
			if(a[i])now++;
			else now--;
			if(c.count(req-now)){
				res=i+1-c[req-now];
				ans=min(res,ans);
			}
		}
		printf("%d\n",ans );
	}	
}