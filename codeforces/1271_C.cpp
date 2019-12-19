#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
int main(){
	int a=0,b=0,c=0,d=0,l=0,r=0,u=0,s=0,n;
	int sx,sy,px,py,sum,x,y;
	scanf("%d%d%d",&n,&sx,&sy);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if(x<sx){
			if(y<sy)a++;
			else if(y>sy)b++;
			else u++;
		}
		else if(x>sx){
			if(y<sy)c++;
			else if(y>sy)d++;
			else s++;
		}
		else{
			if(y<sy)l++;
			else r++;
		}
	}	
	u+=a+b;
	s+=c+d;
	l+=a+c;
	r+=b+d;
	int maxi=max(u,s);
	maxi=max(maxi,l);
	maxi=max(maxi,r);
	if(maxi==u){
		px=sx-1;
		py=sy;
	}
	else if(maxi==s){
		px=sx+1;
		py=sy;
	}
	else if(maxi==l){
		px=sx;
		py=sy-1;
	}
	else {
		px=sx;
		py=sy+1;
	}
	printf("%d\n",maxi );
	printf("%d %d\n",px,py );
}