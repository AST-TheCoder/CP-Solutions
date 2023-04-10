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
 
 ll n;
 cin>>n;
 ll a[n+1];
 for(ll i=1;i<=n;i++) cin>>a[i];
 
 vector<ll> x,y;
 for(ll i=1;i<=n;i++){
  ll p=a[i];
  if((ll)x.size()==0) x.pb(p);
  else if(x[(ll)x.size()-1]!=p && ((ll)y.size()==0 || y[(ll)y.size()-1]!=p)){
   if(i==n || x[(ll)x.size()-1]==a[i+1]) x.pb(p);
   else y.pb(p);
  }
  else if(x[(ll)x.size()-1]!=p) x.pb(p);
  else if((ll)y.size()==0) y.pb(p);
  else if(y[(ll)y.size()-1]!=p) y.pb(p);
 }
 
 cout<<x.size()+y.size()<<endl;
 
 return 0;
}