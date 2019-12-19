#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-5;
const int N = 1e5+10;
//by Judge
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
int main(){
	cout<<(-50)+mod<<endl;
}