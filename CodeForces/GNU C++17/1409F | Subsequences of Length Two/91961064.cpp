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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
ll n,k,dp[207][207][207];
string s,t;
 
ll solve(ll pos,ll move,ll cnt){
 if(pos==n) return 0;
 if(dp[pos][move][cnt]!=-1) return dp[pos][move][cnt];
 
 return dp[pos][move][cnt]=max({solve(pos+1,move,cnt+(s[pos]==t[0]))+cnt*(s[pos]==t[1]),
                                move<k?solve(pos+1,move+1,cnt+1)+cnt*(t[0]==t[1]):0LL,
                                move<k?solve(pos+1,move+1,cnt+(t[0]==t[1]))+cnt:0LL});
}
 
int main()
{
 
 cin>>n>>k>>s>>t;
 memset(dp,-1,sizeof(dp));
 
 cout<<solve(0,0,0)<<endl;
 
 return 0;
}