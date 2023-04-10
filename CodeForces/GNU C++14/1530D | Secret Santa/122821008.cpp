#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
    
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+1],b[n+1],c[n+1],cnt=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            b[i]=c[i]=-1;
        }
 
        vector<ll> x,y;
 
        for(ll i=1;i<=n;i++){
            if(c[a[i]]==-1){
                c[a[i]]=0;
                b[i]=a[i];
                cnt++;
            }
            else x.pb(i);
        }
        
        for(ll i=1;i<=n;i++){
            if(c[i]) y.pb(i);
        }
        if(cnt!=n){
            if(x[0]==y[0]){
                if(x.size()!=1) swap(y[0],y[1]);
                else{
                    for(ll i=1;i<=n;i++){
                        if(i==x[0]) continue;
                        if(a[i]==a[x[0]]){
                            b[x[0]]=a[x[0]];
                            x[0]=i;
                            b[i]=-1;
                            break;
                        }
                    }
                }
            }
            for(ll i=1;i<x.size();i++){
                if(x[i]==y[i]) swap(y[i],y[0]);
            }
            for(ll i=0;i<x.size();i++) b[x[i]]=y[i];
        }
 
        cout<<cnt<<endl;
        for(ll i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
    }
 
    return 0;
}