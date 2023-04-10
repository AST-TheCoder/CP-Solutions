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
  ll x,y;
  scanf("%lli %lli",&x,&y);
 
  ll p=sqrt(x+1);
  if(p*p>x+1) p--;
  if((p+1)*(p+1)<=x+1) p++;
 
  if(p>y) p=y;
 
  ll ans=((p-1)*p)/2;
  ll l=p;
  for(ll i=p-1;i>=1;i--){
   ll r=(x-i)/i;
   if(r>y) r=y;
   if(r>l){
    ans+=(r-l)*i;
    l=r;
   }
  }
  cout<<ans<<endl;
 }
 
 return 0;
}