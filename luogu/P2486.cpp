#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const int N = 1e5+10,M=N<<1;
int head[N],Next[M],ver[M],tot,son[N],size[N],f[N],rk[N],top[N],num,val[N],id[N],sx,sy;
int mod,cnt;
struct segtree{
	int sum,l,r,lc,rc,tag;
}seg[N<<2];
inline void add(int x,int y){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;
}
inline void dfs1(int s,int fa){
	int v;
	size[s]=1,f[s]=fa;
	for(int i=head[s];i;i=Next[i]){
		v=ver[i];
		if(v==fa)continue;
		dfs1(v,s);
		if(size[v]>size[son[s]]) son[s]=v;
		size[s]+=size[v];
	}
}
inline void dfs2(int s,int tp){
	rk[s]=++num;
	id[num]=s;
	top[s]=tp;
	if(son[s]==0)return;
	int v=son[s];
	dfs2(v,tp);
	for(int i=head[s];i;i=Next[i]){
		v=ver[i];
		if(v==f[s]||v==son[s])continue;
		dfs2(v,v);
	}
}
inline void build(int s,int l,int r){
	seg[s].tag=0;
	seg[s].l=l;
	seg[s].r=r;
	seg[s].lc=val[id[l]];
	seg[s].rc=val[id[r]];
	if(l==r){
		seg[s].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(s<<1,l,mid);
	build(s<<1|1,mid+1,r);
	seg[s].sum=seg[s<<1].sum+seg[s<<1|1].sum;
	if(seg[s<<1].rc==seg[s<<1|1].lc)seg[s].sum--;
}
inline void spread(int s){
	seg[s<<1].sum=1;
	seg[s<<1|1].sum=1;
	seg[s<<1].tag=seg[s].tag;
	seg[s<<1|1].tag=seg[s].tag;
	seg[s<<1].lc=seg[s<<1].rc=seg[s<<1|1].lc=seg[s<<1|1].rc=seg[s].tag;
	seg[s].tag=0;
}
inline void change(int s,int l,int r,int d){
	if(l<=seg[s].l&&seg[s].r<=r){
		seg[s].tag=d;
		seg[s].sum=1;
		seg[s].lc=seg[s].rc=d;
		return;
	}
	if(seg[s].tag)spread(s);
	int mid=(seg[s].l+seg[s].r)/2;
	if(l<=mid)change(s<<1,l,r,d);
	if(r>mid)change(s<<1|1,l,r,d);
	seg[s].sum=seg[s<<1].sum+seg[s<<1|1].sum;
	if(seg[s<<1].rc==seg[s<<1|1].lc)seg[s].sum--;
	seg[s].lc=seg[s<<1].lc;
	seg[s].rc=seg[s<<1|1].rc;
}
inline int ask(int s,int l,int r){
	if(l<=seg[s].l&&seg[s].r<=r){
		if(seg[s].l==l)val[id[l]]=seg[s].lc;
		if(seg[s].r==r)val[id[r]]=seg[s].rc;
		return seg[s].sum;
	}
	if(seg[s].tag)spread(s);
	int mid=(seg[s].l+seg[s].r)/2;
	int ans=0;
	if(l<=mid)ans+=ask(s<<1,l,r);
	if(r>mid)ans+=ask(s<<1|1,l,r);
	if(l<=mid&&r>mid){
		if(seg[s<<1].rc==seg[s<<1|1].lc)ans--;
	}
	return ans;
}
inline void update(int x,int y,int d){
	int fx=top[x],fy=top[y];
	while(fx!=fy){
		if(rk[fx]>rk[fy]){
			change(1,rk[fx],rk[x],d);
			x=f[fx];
			fx=top[x];
		}
		else{
			change(1,rk[fy],rk[y],d);
			y=f[fy];
			fy=top[y];
		}
	}
	if(rk[x]<rk[y])change(1,rk[x],rk[y],d);
	else change(1,rk[y],rk[x],d);
}
inline int query(int x,int y){
	int fx=top[x],fy=top[y],sx=0,sy=0;
	int ans=0;
	while(fx!=fy){
		if(rk[fx]>rk[fy]){
			ans+=ask(1,rk[fx],rk[x]);
			if(val[x]==val[sx])ans--;
			sx=fx;
			x=f[fx];
			fx=top[x];
		}
		else{
			ans+=ask(1,rk[fy],rk[y]);
			if(val[y]==val[sy])ans--;
			sy=fy;
			y=f[fy];
			fy=top[y];
		}
	}
	if(rk[x]<rk[y]) ans+=ask(1,rk[x],rk[y]);
	else ans+=ask(1,rk[y],rk[x]);
	if(val[x]==val[sx])ans--;
	if(val[y]==val[sy])ans--;
	return ans;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("test.out","w",stdout);
	int n,m,x,y,z;
	char op[10];
	tot=num=cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=0;i<m;i++){
		scanf("%s",op);
		if(op[0]=='C'){
			scanf("%d%d%d",&x,&y,&z);
			update(x,y,z);
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%d\n",query(x,y));
		}
	}
}