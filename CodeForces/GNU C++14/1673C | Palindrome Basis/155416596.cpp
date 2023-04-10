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
 
ll dp[40001];
int main()
{   
    vector<ll> v;
    ll mod=1000000007;
    for(ll i=1;i<=40000;i++){
        ll x=i,y=0;
        while(x){
            y=y*10+(x%10);
            x/=10;
        }
        if(y==i) v.pb(i);
    }
    
    dp[0]=1;
    for(ll i=0;i<v.size();i++){
        for(ll j=v[i];j<=40000;j++){
            dp[j]+=dp[j-v[i]];
            dp[j]%=mod;
        }
    }
 
 
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
 
    return 0;
}