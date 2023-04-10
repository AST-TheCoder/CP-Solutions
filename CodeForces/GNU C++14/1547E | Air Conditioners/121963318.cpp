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
 
    read:
    while(t--){
        ll n,k;
        cin>>n>>k;
 
        ll cell[k],ans[n+1];
        for(ll i=1;i<=n;i++) ans[i]=Max;
        for(ll i=0;i<k;i++) cin>>cell[i];
        for(ll i=0;i<k;i++){
            ll x;
            cin>>x;
            ans[cell[i]]=x;
        }
        for(ll i=1,t=Max;i<=n;i++){
            ans[i]=min(t+1,ans[i]);
            t=ans[i];
        }
        for(ll i=n,t=Max;i>=1;i--){
            ans[i]=min(t+1,ans[i]);
            t=ans[i];
        }
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}