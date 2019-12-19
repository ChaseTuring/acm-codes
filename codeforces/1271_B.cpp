#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
int main(){
	int n,a[210],ans[210],cnt=0,b=0,w=0;
	char s[210];
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++){
		if(s[i]=='W')a[i+1]=0;
		else a[i+1]=1;
	}
	for(int i=1;i<n;i++){
		if(a[i]){
			ans[cnt++]=i;
			a[i]=!a[i];
			a[i+1]=!a[i+1];
		}
	}
	if(a[n]==1){
		for(int i=0;i<n;i++){
			if(s[i]=='W')a[i+1]=0;
			else a[i+1]=1;
		}
		cnt=0;
		for(int i=1;i<n;i++){
			if(a[i]==0){
				ans[cnt++]=i;
				a[i]=!a[i];
				a[i+1]=!a[i+1];
			}
		}
		if(a[n]==0){
			printf("-1\n");
		}
		else {
			printf("%d\n",cnt );
			for(int i=0;i<cnt;i++){
				if(i)printf(" ");
				printf("%d",ans[i] );
			}
			printf("\n");
		}
	}
	else{
		printf("%d\n",cnt );
		for(int i=0;i<cnt;i++){
			if(i)printf(" ");
			printf("%d",ans[i] );
		}
		printf("\n");
	}
}