#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;
deque<int>dq;
int main(){
	int a,b,c,d;
	while(~scanf("%d%d%d%d",&a,&b,&c,&d)){
		bool flag=true;
		dq.clear();
		while(a&&b){
			dq.push_back(0);
			dq.push_back(1);
			a--,b--;
		}
		if(a==0&&b==0){
			if(dq.size()==0&&c==d-1)dq.push_front(3),d--;
			while(c&&d){
				dq.push_back(2);
				dq.push_back(3);
				c--,d--;
			}
			if(c==0&&d==0){
				flag=true;
			}
			else if(c==0){
				flag=false;
			}
			else {
				if(c==1)dq.push_back(2);
				else flag=false;
			}
		}
		else if(a==0){
			while(b&&c){
				dq.push_back(2);
				dq.push_back(1);
				c--,b--;
			}
			if(c==0&&b==0){
				if(d==1){
					dq.push_front(1);
					dq.pop_back();
					dq.push_back(3);
				}
				else if(d==0)flag=true;
				else flag=false;
			}
			else if(c==0){
				if(b==1&&d==0){
					dq.push_front(1);
				}
				else flag=false;
			}
			else {
				if(c==d-1){
					dq.push_front(1);
					dq.pop_back();
					dq.push_back(3);
					d--;
				}
				while(c&&d){
					dq.push_back(2);
					dq.push_back(3);
					c--,d--;
				}
				if(c==0&&d==0){
					flag=true;
				}
				else if(c==0){
					flag=false;
				}
				else {
					if(c==1)dq.push_back(2);
					else flag=false;
				}
			}
		}
		else {
			if(a==1&&c==0&&d==0)dq.push_back(0);
			else flag=false;
		}
		if(flag){
			printf("YES\n");
			while(!dq.empty()){
				if(dq.size()==1)printf("%d",dq.front() );
				else printf("%d ",dq.front() );
				dq.pop_front();
			}
			printf("\n");
		}
		else {
			printf("NO\n");
		}
	}
}