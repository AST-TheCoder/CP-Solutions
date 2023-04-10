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
 
    ll n,m;
    cin>>n>>m;
    ll c[n+1],ans=n;
    memset(c,0,sizeof(c));
 
    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        if(!c[min(x,y)]) ans--;
        c[min(x,y)]++;
    }
    ll q;
    cin>>q;
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll x,y;
            cin>>x>>y;
            if(!c[min(x,y)]) ans--;
            c[min(x,y)]++;
        }
        if(t==2){
            ll x,y;
            cin>>x>>y;
            c[min(x,y)]--;
            if(!c[min(x,y)]) ans++;
        }
        if(t==3) cout<<ans<<endl;
    }
 
    return 0;
}