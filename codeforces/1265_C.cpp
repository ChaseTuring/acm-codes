#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 4e5+10;
int num[N],val[N],a[N],cnt=0,n;
inline void read_discrete(){
	memset(num,0,sizeof(num));
	cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
		a[cnt++]=val[i];
	}
	sort(a,a+cnt);
	cnt=unique(a,a+cnt)-a;
	for(int i=0;i<n;i++){
		num[lower_bound(a,a+cnt,val[i])-a]++;
	}
}
int main(){
	int t,g,s,b;
	bool flag;
	scanf("%d",&t);
	while(t--){
		read_discrete();
		g=num[cnt-1];
		s=b=0;
		int i;
		if(cnt-2<=0)flag=false;
		else flag=true;
		if(flag){
			for(i=cnt-2;i>=0&&s<=g;i--){
				s+=num[i];
				if(g+s>n/2){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			for(;i>=0;i--){
				b+=num[i];
				if(g+s+b>n/2){
					b-=num[i];
					if(b<=g){
						flag=false;
					}
					break;
				}
			}
		}
		if(flag){
			printf("%d %d %d\n",g,s,b);
		}
		else printf("0 0 0\n");
	}
}