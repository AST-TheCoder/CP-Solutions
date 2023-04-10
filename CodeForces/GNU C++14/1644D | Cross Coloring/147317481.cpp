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
    ll t;
    cin>>t;
 
    read:
 
    while(t--){
        ll n,m,k,q,mod=998244353,ans=1;
        cin>>n>>m>>k>>q;
 
        pair<ll,ll> p[q];
        for(ll i=0;i<q;i++) cin>>p[i].first>>p[i].second;
        ll r[n+1],c[m+1],cr=0,cc=0;
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
 
        for(ll i=q-1;i>=0;i--){
            if((r[p[i].first]|| cc==m) && (c[p[i].second] || cr==n)) continue;
            ans=(ans*k)%mod;
            if(!r[p[i].first]) r[p[i].first]=1,cr++;
            if(!c[p[i].second]) c[p[i].second]=1,cc++;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}