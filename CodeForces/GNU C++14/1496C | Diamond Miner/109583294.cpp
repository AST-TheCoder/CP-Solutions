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
 cin>>t ;
 
 while(t--){
  ll n;
  cin>>n;
 
  vector<ll> x,y;
  for(ll i=0;i<2*n;i++){
   ll p,q;
   cin>>p>>q;
   if(!p) y.pb(abs(q));
   else x.pb(abs(p));
  }
  sort(all(y));
  sort(all(x));
 
  double ans=0.0;
  for(ll i=0;i<n;i++){
   //cout<<x[i]<<" "<<y[i]<<endl;
   ans+=(double)sqrt((double)x[i]*(double)x[i]+(double)y[i]*(double)y[i]);
  }
  cout<<fixed<<setprecision(15)<<ans<<endl;
 }
 
 return 0;
}