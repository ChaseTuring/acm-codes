#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
int main(){
	ll n,k,res,ans;
	int a,b;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		n=abs(a-b);
		for(k=0;;k++){
			if(k*(k+1)/2<=n&&n<(k+1)*(k+2)/2)break;
		}
		res=k*(k+1)/2;
		if(n==res)ans=k;
		else if(k%2){
			if((n-res)%2)ans=k+2;
			else ans=k+1;
		}
		else{
			if((n-res)%2)ans=k+1;
			else ans=k+3;
		}
		printf("%lld\n",ans );
	}
}