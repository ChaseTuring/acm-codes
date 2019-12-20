#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}

int main() {
    //redirect();
    int t,plen,hlen;
    char p[110],h[110];
    int a[110],b[110];
    bool flag;
    scanf("%d",&t);
    while(t--){
        memset(b,0,sizeof(b));
        scanf("%s",p);
        scanf("%s",h);
        plen=strlen(p);
        hlen=strlen(h);
        for(int i=0;i<plen;i++){
            b[p[i]-'a']++;
        }
        for(int i=0;i<hlen;i++){
            flag=true;
            memset(a,0,sizeof(a));
            for(int j=i;j<min(i+plen,hlen);j++){
                a[h[j]-'a']++;
            }
            for(int j=0;j<26;j++){
                if(a[j]!=b[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
}