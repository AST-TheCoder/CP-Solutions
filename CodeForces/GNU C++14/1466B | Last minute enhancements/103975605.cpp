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
 cin>>t;
 
 while(t--){
  ll n;
  cin>>n;
 
  ll chk[2*n+5];
  memset(chk,0,sizeof(chk));
  ll ans=0;
  for(ll i=1;i<=n;i++){
   ll x;
   cin>>x;
   if(!chk[x]){
    ans++;
    chk[x]=1;
   }
   else if(!chk[x+1]){
    ans++;
    chk[x+1]=1;
   }
  }
  cout<<ans<<endl;
 }
 
 return 0;
}