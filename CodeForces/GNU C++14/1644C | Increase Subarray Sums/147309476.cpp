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
        ll n,x;
        cin>>n>>x;
 
        ll a[n+1];
        a[0]=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
 
       ll dp[n+1];
       for(ll i=0;i<=n;i++) dp[i]=INT_MIN;
       dp[0]=0;
       for(ll i=1;i<=n;i++){
           for(ll j=i;j<=n;j++){
               dp[j-i+1]=max(dp[j-i+1],a[j]-a[i-1]);
           }
       }
 
       for(ll k=0;k<=n;k++){
           ll ans=0;
           for(ll i=0;i<=n;i++){
               ans=max(ans,dp[i]+min(i,k)*x);
           }
           cout<<ans<<" ";
       }cout<<endl;
    }
 
    return 0;
}