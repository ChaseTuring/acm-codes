#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
struct path{
	ll p,v;
}bdr,bdr_u,e,o;
ll k,n;
bool judge(path u){
	if(u.p>=k){
		return true;
	}
	else return false;
}
ll solve(){
	bdr.v=n;
	bdr.p=1;
	if(judge(bdr))return bdr.v;
	bdr_u.v=n-1;
	if(bdr_u.v%2){
		bdr_u.p=1;
	}
	else bdr_u.p=2;
	if(judge(bdr_u))return bdr_u.v;
	o.p=1;
	e.p=2;
	if(n%2){
		o.v=n-2;
		e.v=n-3;
		if(o.v<=n/2)o=bdr;
		if(e.v<=n/2)e=bdr_u;
		if(judge(o))return o.v;
		if(judge(e))return e.v;
	}
	else{
		o.v=n-3;
		e.v=n-2;
		if(o.v<=n/2)o=bdr_u;
		if(e.v<=n/2)e=bdr;
		if(judge(e))return e.v;
		if(judge(o))return o.v;
	}
	while(true){
		n/=2;
		if(n%2){
			if(bdr.v%2){
				bdr.p=bdr_u.p+1;
			}
			else bdr.p=bdr.p+1;
			bdr.v=n;
			if(judge(bdr))return bdr.v;
			bdr_u.v=n-1;
			bdr_u.p=e.p+1+bdr.p;
			if(judge(bdr_u))return bdr_u.v;
			o.v=n-2;
			e.v=n-3;
			o.p=e.p+1;
			e.p=e.p+1+o.p;
			if(o.v<=n/2)o=bdr;
			if(e.v<=n/2)e=bdr_u;
			if(judge(o))return o.v;
			if(judge(e))return e.v;
		}
		else{
			if(bdr.v%2){
				bdr.p=bdr_u.p+1+o.p;
			}
			else bdr.p=bdr.p+1+o.p;
			bdr.v=n;
			if(judge(bdr))return bdr.v;
			bdr_u.v=n-1;
			bdr_u.p=e.p+1;
			if(judge(bdr_u))return bdr_u.v;
			o.v=n-3;
			e.v=n-2;
			o.p=e.p+1;
			e.p=e.p+1+o.p;
			if(o.v<=n/2)o=bdr_u;
			if(e.v<=n/2)e=bdr;
			if(judge(e))return e.v;
			if(judge(o))return o.v;
		}
	}
}
int main(){
	freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%lld %lld",&n,&k);
		printf("%lld\n",solve() );
	}
}