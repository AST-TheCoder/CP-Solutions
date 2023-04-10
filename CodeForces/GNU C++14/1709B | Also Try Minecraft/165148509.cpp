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
    
    ll n,m;
    cin>>n>>m;
 
    ll a[n+2];
    for(ll i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=0;
 
    ll f[n+2],b[n+2];
    f[0]=f[n+1]=b[0]=b[n+1]=0;
    for(ll i=1;i<=n;i++){
        f[i]=f[i-1];
        if(a[i]<a[i-1]) f[i]+=(a[i-1]-a[i]);
    }
 
    for(ll i=n;i>=1;i--){
        b[i]=b[i+1];
        if(a[i]<a[i+1]) b[i]+=(a[i+1]-a[i]);
    }
 
    while(m--){
        ll l,r;
        cin>>l>>r;
 
        if(l<=r) cout<<f[r]-f[l]<<endl;
        else cout<<b[r]-b[l]<<endl;
    }
 
    return 0;
}