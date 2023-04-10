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
 
ll a[100001],dp[100001];
ll solve(ll l,ll r){
    if(l>r) return 0;
    if(dp[l]!=-1) return dp[l];
 
    ll x,y=Max;
 
    ll d=max(a[l-1],a[l+1])-a[l]+1;
    if(d<0) d=0;
    x=solve(l+2,r)+d;
    if((r-l)%2){
        d=max(a[l+2],a[l])-a[l+1]+1;
        if(d<0) d=0;
        y=solve(l+3,r)+d;
    }
    return dp[l]=min(x,y);
}
 
int main()
{   
    
    ll t;
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            dp[i]=-1;
        }
 
        ll ans=solve(2,n-1);
        cout<<ans<<endl;
    }
 
    return 0;
}