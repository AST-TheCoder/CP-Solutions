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
        ll n,m;
        cin>>n>>m;
        ll x,y,p,q;
        cin>>x>>y>>p>>q;
        ll w,h;
        cin>>w>>h;
        if((w+p-x)>n && (h+q-y)>m){
            cout<<-1<<endl;
            continue;
        }
        ll ans=Max;
        if(w+p-x<=n){
            if(x<w) ans=min(ans,w-x);
            else ans=0;
            if(n-w<p) ans=min(ans,p-n+w);
            else ans=0;
        }
        if(h+q-y<=m){
            if(y<h) ans=min(ans,h-y);
            else ans=0;
            if(m-h<q) ans=min(ans,q-m+h);
            else ans=0;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}