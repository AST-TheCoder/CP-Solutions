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
 
 ll idx;
 cout<<"? "<<1<<" "<<n<<endl;
 cin>>idx;
 
 ll l=1,r=n;
 
 while(l+1<r){
  ll m=(l+r)/2;
  ll p;
  if(idx>=l && idx<=m){
   cout<<"? "<<l<<" "<<m<<endl;
   cin>>p;
   if(p==idx) r=m;
   else l=m;
  }
  else if(idx>=m && idx<=r){
   cout<<"? "<<m<<" "<<r<<endl;
   cin>>p;
   if(p==idx) l=m;
   else r=m;
  }
  else if(idx>m){
   cout<<"? "<<m<<" "<<idx<<endl;
   cin>>p;
   if(p==idx) l=m;
   else r=m;
  }
  else if(idx<m){
   cout<<"? "<<idx<<" "<<m<<endl;
   cin>>p;
   if(p==idx) r=m;
   else l=m;
  }
 }
 
 ll ans;
 if(l<r){
  cout<<"? "<<l<<" "<<r<<endl;
  cin>>idx;
  if(idx==l) ans=r;
  else ans=l;
 }
 else ans=l;
 
 cout<<"! "<<ans<<endl;
 
 
 return 0;
}