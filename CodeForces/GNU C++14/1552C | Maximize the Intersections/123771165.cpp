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
        ll n,k;
        cin>>n>>k;
        ll a[2*n+1],e[2*n+1];
        memset(a,0,sizeof(a));
        for(ll i=1;i<=k;i++){
            ll u,v;
            cin>>u>>v;
            if(u>v) swap(u,v);
            a[u]=1;
            a[v]=-1;
            e[u]=v;
        }
 
        vector<ll> v;
        for(ll i=1;i<=2*n;i++){
            if(!a[i]) v.pb(i);
        }
        ll c=v.size()/2;
        for(ll i=0;i<c;i++){
            a[v[i]]=1;
            a[v[i+c]]=-1;
            e[v[i]]=v[i+c];
        }
        ll cnt=0,ans=0;
        for(ll i=1;i<=2*n;i++){
            if(a[i]==1){
                for(ll j=1;j<=2*n;j++){
                    if(j==i || j==e[i] || a[j]!=1) continue;
                    //cout<<i<<" "<<e[i]<<" "<<j<<" "<<e[j]<<endl;
                    if(j>i && j<e[i] && e[j]>e[i]){
                        //cout<<i<<" "<<j<<endl;
                        ans++;
                    }
                    if(e[j]>i && e[j]<e[i] && j<i){
                        //cout<<i<<" "<<j<<endl;
                        ans++;
                    }
                }
            }
        }
        cout<<ans/2<<endl;
    }
 
    return 0;
}