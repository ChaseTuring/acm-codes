#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
int main(){
	int a,b,c,d,e,f,mini,ans=0;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if(e>f){
		mini=min(a,d);
		a-=mini;
		d-=mini;
		ans+=mini*e;
		mini=min(b,c);
		mini=min(mini,d);
		b-=mini;
		c-=mini;
		d-=mini;
		ans+=mini*f;
	}
	else{
		mini=min(b,c);
		mini=min(mini,d);
		b-=mini;
		c-=mini;
		d-=mini;
		ans+=mini*f;
		mini=min(a,d);
		a-=mini;
		d-=mini;
		ans+=mini*e;
	}
	printf("%d\n",ans );
}