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
 
ll dp[2][200007],st,en,cs,ce;
string s[2];
 
ll solve(ll i,ll j){
    if(j>en) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
 
    dp[i][j]=solve(i,j+1)+1;
    if(s[i==0][j]=='*') dp[i][j]++;
    dp[i][j]=min(solve(i==0,j+1)+2,dp[i][j]);
    return dp[i][j];
}
 
int main()
{   
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        cin>>s[0]>>s[1];
 
        for(ll i=0;i<=n;i++) dp[0][i]=dp[1][i]=-1;
        st=-1,en=-1;
 
        for(ll i=0;i<n;i++){
            if(s[0][i]=='*' || s[1][i]=='*'){
                if(st==-1){
                    st=i;
                    if(s[0][i]=='*') cs=0;
                    else cs=1;
                }
                en=i;
                if(s[0][i]=='*') ce=0;
                else ce=1;
            }
        }
        ll ans=solve(cs,st)-1;
        cout<<ans<<endl;
    }
 
    return 0;
}