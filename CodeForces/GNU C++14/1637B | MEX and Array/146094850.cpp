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
 
ll mex[101][101];
ll dp[101][101];
 
ll solve(ll i, ll j){
    if(i==j) return mex[i][j]+1;
    if(dp[i][j]!=-1) return dp[i][j];
 
    for(ll k=i;k<j;k++){
        dp[i][j]=max(dp[i][j],solve(k+1,j)+mex[i][k]+1);
    }
    return dp[i][j];
}
 
int main()
{   
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(mex,0,sizeof(mex));
 
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
 
        for(ll i=0;i<n;i++){
            set<ll> s;
            ll m=0;
            for(ll j=i;j<n;j++){
                s.insert(a[j]);
                for(auto x: s){
                    if(x==m) m++;
                    else break;
                }
                mex[i][j]=m;
            }
        }
 
        ll ans=0;
        for(ll i=0;i<n;i++){
            for(ll j=i;j<n;j++){
                ans+=solve(i,j);
            }
        }
 
        cout<<ans<<endl;
    }
 
    return 0;
}