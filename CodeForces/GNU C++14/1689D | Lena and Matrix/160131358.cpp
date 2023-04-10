#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{   
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        string s[n];
        ll b[n],e[n];
        for(ll i=0;i<n;i++){
            cin>>s[i];
            b[i]=e[i]=-1;
            for(ll j=0;j<m;j++){
                if(s[i][j]=='B'){
                    if(b[i]==-1) b[i]=j;
                    e[i]=j;
                }
            }
        }
        ll dis=Max,x,y;
 
        for(ll j=0;j<m;j++){
            ll l=0,r=n-1,temp=Max,u,v;
            while(l<=r){
                ll md=(l+r)/2;
                ll up=0,dn=0;
                for(ll i=0;i<=md;i++){
                    if(b[i]==-1) continue;
                    ll d=abs(b[i]-j)+(md-i);
                    d=max(d,abs(e[i]-j)+(md-i));
                    up=max(up,d);
                }
                for(ll i=md+1;i<n;i++){
                    if(b[i]==-1) continue;
                    ll d=abs(b[i]-j)+(i-md);
                    d=max(d,abs(e[i]-j)+(i-md));
                    dn=max(dn,d);
                }
                if(temp>max(up,dn)){
                    temp=max(up,dn);
                    u=md,v=j;
                }
                if(up==dn) break;
                if(up>dn) r=md-1;
                else l=md+1;
            }
            //cout<<u+1<<" "<<v+1<<" "<<temp<<endl;
            if(temp<dis){
                x=u+1;
                y=v+1;
                dis=temp;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
 
    return 0;
}