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
 
ll n,dp[1100000];
vector<ll> cnt[20];
ll solve(ll mask,ll prev){
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    dp[mask]=0;
    for(ll i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        if(cnt[i].size()>prev+2) dp[mask]=max(dp[mask],cnt[i][prev]);
        else if(cnt[i].size()<prev+2) dp[mask]=max(dp[mask],solve(mask|(1<<i),prev-(cnt[i].size()-2)+cnt[i][cnt[i].size()-1]));
        else dp[mask]=max(dp[mask],cnt[i][prev]+solve(mask|(1<<i),cnt[i][prev+1]));
    }
    //cout<<mask<<" "<<prev<<" "<<dp[mask]<<endl;
    return dp[mask];
}
 
int main()
{
 
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        cnt[i].pb(0);
        for(ll j=0,c=0,t=0;j<s.size();j++){
            if(s[j]=='(') c--;
            else c++;
            if(c==0) cnt[i][t]++;
            if(c>0){
                t++;
                cnt[i].pb(1);
                c=0;
            }
            if(j+1==s.size()) cnt[i].pb(-1*c);
        }
    }
    ll ans=solve(0,0);
    cout<<ans<<endl;
 
    return 0;
}