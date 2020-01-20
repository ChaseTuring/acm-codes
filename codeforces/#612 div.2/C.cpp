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
bool book[110];
int main() {
    redirect();
    int n,a[110],ans=0,odd=0,even=0,h_pos,t_pos;
    bool head,tail,flag;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        book[a[i]]=1;
    }
    for(int i=0;i<n-1;i++){
        if(a[i]&&a[i+1]){
            if((a[i]%2)^(a[i+1]%2))ans++;
        }
    }
    for(int i=1;i<=n;i++)
        if(!book[i]){
            if(i%2)odd++;
            else even++;
        }
        cout<<odd<<" "<<even<<endl;
    if(a[0]==0){
        flag=false;
    }
    else{
        flag=true;
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1]==0){
            if(a[i]){
                if(a[i]%2)head=1;
                else head=0;
                h_pos=i;
                flag=true;
            }
        }
        else if(a[i]==0){
            if(flag){
                if(a[i+1]%2)tail=1;
                else tail=0;
                t_pos=i+1;
                if(head^tail)ans++;
                else if(head&&tail){
                    if(odd>=t_pos-h_pos-1)odd-=t_pos-h_pos-1;
                    else ans+=2;
                }
                else{
                    if(even>=t_pos-h_pos-1)even-=t_pos-h_pos-1;
                    else ans+=2;
                }    
            }
            else{
                if(a[i+1]%2)tail=1;
                else tail=0;
                t_pos=i+1;
                if(tail){
                    if(odd>=t_pos)odd-=t_pos;
                    else ans++;
                }
                else{
                    if(even>=t_pos)even-=t_pos;
                    else ans++;
                }    
            }
        }
    }
    if(a[n-1]==0){
        t_pos=n;
        if(flag){
            if(head){
                if(odd>=t_pos-h_pos-1)odd-=t_pos-h_pos-1;
                else ans++;
            }
            else{
                if(even>=t_pos-h_pos-1)even-=t_pos-h_pos-1;
                else ans++;
            }
        }
        else {
            if(n>1)ans=1;
            else ans=0;
        }
    }
    printf("%d\n",ans);
}