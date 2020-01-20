#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
int ans[210];
bool book[210];
int main() {
    //redirect();
    int t,k,sum,res;
    char s[210];
    bool flag;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&k);
        scanf("%s",s);
        sum=0;
        do{
            flag=false;
            for(int j=0;j<k-1;j++){
                if(s[j]=='A'){
                    if(s[j+1]=='P')flag=true,book[j+1]=1;
                }
            }
            for(int j=0;j<k;j++)
                if(book[j])s[j]='A',book[j]=0;
            if(flag)sum++;
        }while(flag);
        ans[i]=sum;
    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
}