#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll unsigned long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
    
    ll n,k,mod=998244353;
    cin>>n>>k;
    ll dp[n+1];
    ll temp[n+1];
    memset(dp,0,sizeof(dp));
    memset(temp,0,sizeof(temp));
    dp[0]=1;
    temp[0]=1;
    for(ll i=k,s=k;s<=n;i++){
        ll temp1[n+1];
        memset(temp1,0,sizeof(temp1));
        for(ll j=s;j<=n;j++){
            temp1[j]=(temp[j-i]+temp1[j-i])%mod;
            dp[j]+=temp1[j];
            dp[j]%=mod;
        }
        for(ll j=s;j<=n;j++) temp[j]=temp1[j];
        s+=(i+1);
    }
    for(ll j=1;j<=n;j++) cout<<dp[j]<<" ";cout<<endl;
 
    return 0;
}