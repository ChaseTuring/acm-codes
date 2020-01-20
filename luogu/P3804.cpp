#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e6+10;

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
void topo(){
    queue<int>q;
    for(int i=1;i<=tot;i++){
        if(sam[i].inder==0)q.push(i);
    }
    while(!q.empty()){
        int p=q.front();
        q.pop();
        sam[sam[p].fa].cnt+=sam[p].cnt;
        sam[sam[p].fa].inder--;
        if(sam[sam[p].fa].inder==0)q.push(sam[p].fa);
    }
}
char s[N];
int main() {
    redirect();
    tot=1;
    las=1;
    scanf("%s",s);
    int slen=strlen(s);
    for(int i=0;i<slen;i++){
        add(s[i]-'a');
    }
    topo();
    for(int i=2;i<=tot;i++)
        printf("%d %d %d\n",sam[i].fa,sam[i].cnt,sam[i].len);
    for(int i=2;i<=tot;i++){
        if(sam[i].cnt>1&&maxv<sam[i].len*sam[i].cnt){
            maxv=sam[i].len*sam[i].cnt;
        }
    }
    printf("%d\n",maxv);
}