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
    ll a[35];
    a[0]=1;
    for(ll i=1;i<35;i++) a[i]=a[i-1]*2;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll x=(n^m);
        vector<ll> p,q;
        for(ll i=0;i<35;i++){
            p.pb(x%2);
            x/=2;
        }
        for(ll i=0;i<35;i++){
            q.pb(m%2);
            m/=2;
        }
 
        ll ans=Max,s=0;
        for(ll i=34;i>=0;i--){
            if(q[i]==0){
                ll temp;
                if(!p[i]) temp=a[i];
                else temp=0;
                ans=min(ans,s+temp);
            }
            if(p[i]) s+=a[i];
        }
        cout<<ans<<endl;
    }
 
    return 0;
}