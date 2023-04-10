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
 
int main()
{ 
 
 ll n,m,ans=0;
 cin>>n>>m;
 
 string s,t;
 cin>>s>>t;
 
 ll p[m];
 for(ll i=0,j=0;i<m;i++,j++){
  while(t[i]!=s[j]) j++;
  p[i]=j;
  if(i) ans=max(ans,p[i]-p[i-1]);
 }
 
 vector<ll> x[200];
 for(ll i='a';i<='z';i++){
  for(ll j=0;j<n;j++){
   if((ll)s[j]==i) x[i].pb(j);
  }
 }
 
 ll c=n+1;
 for(ll i=m-1;i>=1;i--){
  ll idx=upper_bound(all(x[(ll)t[i]]),c)-x[(ll)t[i]].begin();
  idx=x[(ll)t[i]][idx-1];
  p[i]=idx;
  //cout<<ans<<" "<<idx<<" "<<p[i]-p[i-1]<<endl;
  ans=max(ans,p[i]-p[i-1]);
  c=idx-1;
 }
 cout<<ans<<endl;
 
 return 0;
}