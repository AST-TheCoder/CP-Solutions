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
 
ll a[101],n,mod=1000000007;
vector<vector<ll>> dp;
ll solve(ll i,ll x){
    if(!x) return 1;
    if(i>n || a[i]>x) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    return dp[i][x]=(solve(i,x-a[i])+solve(i+1,x))%mod;
}
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n],b[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
 
        for(ll i=0;i<n;i++){
            if(a[i]>b[i]) swap(a[i],b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
 
        cout<<a[n-1]*b[n-1]<<endl;
    }
 
    return 0;
}