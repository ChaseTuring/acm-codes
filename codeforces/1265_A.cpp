#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
int main(){
	int n,len;
	char s[N];
	bool flag;
	scanf("%d",&n);
	while(n--){
		flag=true;
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='?'){
				if(i+1<len){
					if(i-1>=0){
						if(s[i+1]!='?'){
							if(s[i-1]==s[i+1]){
								if(s[i-1]=='a')s[i]='b';
								else s[i]='a';
							}
							else {
								if(s[i-1]=='a'){
									if(s[i+1]=='b'){
										s[i]='c';
									}
									else if(s[i+1]=='c')s[i]='b';
								}
								else if(s[i-1]=='b'){
									if(s[i+1]=='a'){
										s[i]='c';
									}
									else if(s[i+1]=='c')s[i]='a';
								}
								else{
									if(s[i+1]=='a'){
										s[i]='b';
									}
									else if(s[i+1]=='b')s[i]='a';
								}
							}
						}
						else{
							if(s[i-1]=='a')s[i]='b';
							else s[i]='a';
						}
					}
					else{
						if(s[i+1]!='?'){							
							if(s[i+1]=='a')s[i]='b';
							else s[i]='a';
						}
						else{
							s[i]='a';
						}
					}
				}
				else{
					if(i-1>=0){
						if(s[i-1]=='a')s[i]='b';
						else s[i]='a';
					}
					else{
						s[i]='a';
					}
				}
			}
			else{
				if(i+1<len){
					if(s[i]==s[i+1]){
						flag=false;break;
					}
				}
			}
		}	
		if(flag)
			printf("%s\n",s );
		else printf("-1\n");
	}
}