#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 5;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
}

inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

int n; int ans = 0;
string a[N]; 
int b[N];
int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t; scanf("%d",&t);
        b[i]=t;
        string s="000000000000000000000000000000";
        int pos = 29;
        while(t){
            if(t%2==1) s[pos] = '1';
            pos--; t/=2;
        }
        a[i] = s;
        cout<<s<<endl;
    }
    int l,r,base=0,binary,ans=INF,bid,len;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        l=1,r=n;
        base=0;
        binary=pow(2,29);
        for(int j=0;j<30;j++){
            if(a[n][j]=='0'){
                binary/=2;
                continue;
            }
            //cout<<binary<<" ";
            if(a[i][j]=='1'){
                l=lower_bound(b+l,b+r,base)-b;
                if(base+binary<=b[l])base+=binary;
                r=lower_bound(b+l,b+r,base+binary)-b;
                if(b[r]>base+binary)r--;
            }
            else{
                base+=binary;
                if(lower_bound(b+l,b+r,base)-b>r)base-=binary;
                else{
                    l=lower_bound(b+l,b+r,base)-b;
                    r=lower_bound(b+l,b+r,base+binary)-b;
                    if(b[r]>base+binary)r--;
                }
            }
            binary/=2;
        }
        ans=min(b[l]^b[i],ans);
        //cout<<b[l]<<endl;
    }
    printf("%x\n",ans);
    for(int i=1;i<=n;i++)printf("%x",ans^b[i]);
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/
