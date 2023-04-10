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
 
 ll t;
 scanf("%lli",&t);
 
 while(t--){
  ll n;
  scanf("%lli",&n);
 
  ll u[n];
  for(ll i=0;i<n;i++) scanf("%lli",&u[i]);
 
  vector<ll> s[n+1];
  for(ll i=0;i<n;i++){
   ll x;
   scanf("%lli",&x);
   s[u[i]].pb(x);
  }
  ll ans[n+1];
  memset(ans,0,sizeof(ans));
  for(ll i=1;i<=n;i++){
   sort(all(s[i]),greater<ll>());
  //cout<<"OK"<<endl;
   for(ll j=1;j<s[i].size();j++) s[i][j]+=s[i][j-1];
   for(ll j=0;j<s[i].size();j++){
    ll k=j+1,l=s[i].size();
    ans[k]+=s[i][(l-(l%k))-1];
   }
  }
 
  for(ll i=1;i<=n;i++) printf("%lli ",ans[i]);
  printf("\n");
 }
 
    return 0;
}