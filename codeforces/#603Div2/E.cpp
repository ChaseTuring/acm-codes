#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e6+10;
int n;
void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
struct segtree{
    int l,r,maxi,add,mini;
}seg[4*N];
void build(int s,int l,int r){
    if(l==r){
        seg[s].l=seg[s].r=l;
        seg[s].add=0;
        seg[s].maxi=0;
        seg[s].mini=0;
        return;
    }
    int mid=(l+r)/2;
    seg[s].l=l;
    seg[s].r=r;
    build(s*2,l,mid);
    build(s*2+1,mid+1,r);
    seg[s].add=seg[s].maxi=seg[s].mini=0;
}
void push(int s){
    seg[s*2].add+=seg[s].add;
    seg[s*2+1].add+=seg[s].add;
    seg[s*2].maxi+=seg[s].add;
    seg[s*2+1].maxi+=seg[s].add;
    seg[s*2].mini+=seg[s].add;
    seg[s*2+1].mini+=seg[s].add;
    seg[s].add=0;
}
void change(int s,int l,int r,int d){
    if(l<=seg[s].l&&seg[s].r<=r){
        seg[s].add+=d;
        seg[s].maxi+=d;
        seg[s].mini+=d;
        return;
    }
    if(seg[s].add)push(s);
    int mid=(seg[s].l+seg[s].r)/2;
    if(l<=mid)change(s*2,l,r,d);
    if(r>mid)change(s*2+1,l,r,d);
    seg[s].maxi=max(seg[s*2].maxi,seg[s*2+1].maxi);
    seg[s].mini=min(seg[s*2].mini,seg[s*2+1].mini);
}
int ask(int s,int m){
    if(seg[s].l==seg[s].r)return seg[s].maxi;
    if(seg[s].add)push(s);
    int mid=(seg[s].l+seg[s].r)/2;
    if(m<=mid)return ask(s*2,m);
    else return ask(s*2+1,m);
}
char s[N];
char t[N];
int main() {
    //redirect();
    int p=1,now=0;
    scanf("%d",&n);
    build(1,1,n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]=='L')p--;
        else if(s[i]=='R')p++;
        else if(s[i]=='('){
            if(t[p]==')'){
                change(1,p,n,2);
                t[p]='(';
                now+=2;
            }
            else if(t[p]!='('){
                change(1,p,n,1);
                t[p]='(';
                now++;
            }
        }
        else if(s[i]==')'){
            if(t[p]=='('){
                change(1,p,n,-2);
                t[p]=')';
                now-=2;
            }
            else if(t[p]!=')'){
                change(1,p,n,-1);
                t[p]=')';
                now--;
            }
        }
        else{
            if(t[p]=='('){
                change(1,p,n,-1);
                now--;
            }
            else if(t[p]==')'){
                change(1,p,n,1);
                now++;
            }
            t[p]=s[i];
        }
        p=max(p,1);
        if(i)printf(" ");
        if(ask(1,n)==0&&seg[1].mini>=0)printf("%d",seg[1].maxi);
        else printf("-1");
    }
    printf("\n");
}