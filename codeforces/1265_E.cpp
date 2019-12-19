#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const ll eps = 1e-5;
const int N = 1e5+10;
inline ll quick_pow(ll x,int p){
	ll res=1;
	while(p){
		if(p&1) res=(res*x)%mod;
		x=(x*x)%mod, p>>=1;
	}
	return res;
}
inline inv(ll a){
	return quick_pow(a,mod-2);
}
const ll hun_inv=828542813;
int main(){
	int t,n,x,y;
	ll p,ans,up,down=1;
	scanf("%d",&n);
	ll base=quick_pow(100,n);
	up=base;
	for(int i=1;i<=n;i++){
		scanf("%lld",&p);
		down=down*p%mod;
		base=base*hun_inv%mod;
		if(i<n)
			up=(up+((base*down)%mod))%mod;
	}
	ans=up*inv(down)%mod;
	printf("%lld\n",ans);
}
