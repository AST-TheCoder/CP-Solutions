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
 
ll popcnt(ll n){
    ll cnt=0;
    while(n){
        if(n%2) cnt++;
        n/=2;
    }
    return cnt;
}
vector<ll> chk;
ll dp[100000],n;
 
ll solve(ll mask){
 
    if(dp[mask]!=-1) return dp[mask];
 
    ll sum=0,cnt=0;
    for(ll i=0;i<15;i++){
        if(mask&(1<<i)){
            sum+=chk[i];
            cnt++;
        }
    }
 
    if(n-sum<0) return 100;
    dp[mask]=cnt+popcnt(n-sum);
    for(ll i=0;i<15;i++){
        if(!(mask&(1<<i))){
            dp[mask]=min(dp[mask],solve(mask|(1<<i)));
        }
    }
    return dp[mask];
}
 
int main()
{   
    ll t;
    cin>>t;
 
    read:
 
    for(ll i=1,c=1;c<=1000000000000;i++){
        c*=i;
        chk.pb(c);
    }
 
    while(t--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        
        cout<<solve(0)<<endl;
    }
 
    return 0;
}