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
 read:
 while(t--){
  ll n;
  cin>>n;
 
  ll x[n+1],y[n+1];
  for(ll i=1;i<=n;i++) cin>>x[i]>>y[i];
  sort(x+1,x+n+1);
  sort(y+1,y+n+1);
  ll a=100000000000000LL,b=1000000000000LL;
  ll s1[n+1],s2[n+1];
  s1[0]=s2[0]=0;
  for(ll i=1;i<=n;i++){
   s1[i]=s1[i-1]+x[i];
   s2[i]=s2[i-1]+y[i];
  }
  vector<ll> p,q;
 
  for(ll i=1;i<=n;i++){
   ll m1=i*x[i]-s1[i]+s1[n]-(n-i+1)*x[i]-s1[i-1];
   ll m2=i*y[i]-s2[i]+s2[n]-(n-i+1)*y[i]-s2[i-1];
   //cout<<x[i]<<" "<<m1<<" "<<y[i]<<" "<<m2<<endl;
   if(m1<a){
    p.clear();
    a=m1;
    p.pb(x[i]);
   }
   else if(m1==a) p.pb(x[i]);
   if(m2<b){
    q.clear();
    b=m2;
    q.pb(y[i]);
   }
   else if(m2==b) q.pb(y[i]);
  }
  cout<<(p[p.size()-1]-p[0]+1)*(q[q.size()-1]-q[0]+1)<<endl;
 }
 
 return 0;
}