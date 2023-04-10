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
 
ll n,a[502],d[502],dp[501][501];
 
ll solve(ll p,ll k){
    if(p==n) return 0;
    if(dp[p][k]!=-1) return dp[p][k];
 
    dp[p][k]=Max;
    for(ll i=p+1;i<=n && i<=p+k+1;i++){
        dp[p][k]=min(dp[p][k],solve(i,k-(i-p-1))+(a[i]-a[p])*d[p]);
    }
    return dp[p][k];
}
 
int main()
{   
    ll l,k;
    cin>>n>>l>>k;
 
    for(ll i=0;i<n;i++) cin>>a[i];
    a[n]=l;
    for(ll i=0;i<n;i++) cin>>d[i];
    memset(dp,-1,sizeof(dp));
 
    ll ans=solve(0,k);
    cout<<ans<<endl;
 
    return 0;
}