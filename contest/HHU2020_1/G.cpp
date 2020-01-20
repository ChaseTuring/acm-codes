#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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
struct node{
    int ch[30],fa,cnt,len,inder;
    node(){memset(ch,0,sizeof(ch));len=fa=0;}
}sam[2*N];

int las=0,tot=0,maxv=0;
void add(int c){
    c;
    int p=las,np=las=++tot;
    sam[np].inder=0;
    sam[np].cnt=1;
    sam[np].len=sam[p].len+1;
    for(;p&&!sam[p].ch[c];p=sam[p].fa)sam[p].ch[c]=np;
    if(p==0)sam[np].fa=1,sam[1].inder++;
    else{
        int q=sam[p].ch[c];
        if(sam[p].len+1==sam[q].len)sam[np].fa=q,sam[q].inder++;
        else{
            int nq=++tot;
            sam[nq]=sam[q];
            sam[nq].inder=0;sam[nq].cnt=0;
            sam[nq].len=sam[p].len+1;
            sam[q].fa=sam[np].fa=nq;
            sam[nq].inder+=2;
            for(;p&&sam[p].ch[c]==q;p=sam[p].fa)sam[p].ch[c]=nq;
        }
    }
}
char s[N],t[N];
int main() {
    redirect();
    tot=1;
    las=1;
    scanf("%s",s);
    int slen=strlen(s);
    for(int i=0;i<slen;i++){
        add(s[i]-'a');
    }
    scanf("%s",t);
    int u=1,l=0;
    int tlen=strlen(t);
    for(int i=0;i<tlen;i++){
        while(u&&!sam[u].ch[t[i]-'a']){
            u=sam[u].fa;
            l=sam[u].len;
        }
        if(u==0)u=1,l=0;
        else l++,u=sam[u].ch[t[i]-'a'];
        maxv=max(maxv,l);
    }
    printf("%d\n",maxv);
}