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

int main() {
    //redirect();
    int n,m,q,x;
    string s[30],t[30];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        cin>>t[i];
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&x);
        x--;
        cout<<s[x%n]<<t[x%m]<<endl;
    }
}