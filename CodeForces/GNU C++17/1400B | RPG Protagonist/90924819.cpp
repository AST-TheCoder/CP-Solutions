#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll t;
 cin>>t;
 
 while(t--){
  ll w1,w2;
  cin>>w1>>w2;
  ll n,m;
  cin>>n>>m;
  ll e1,e2;
  cin>>e1>>e2;
 
  if(e1>e2){
   swap(e1,e2);
   swap(n,m);
  }
 
  ll ans=0;
 
  for(ll i=0;i<=n;i++){
   ll x=min(w1/e1,i);
   ll ww1=w1-(x*e1);
   ll y=min(ww1/e2,m);
 
   ll nn=n-x,mm=m-y;
 
   ll p=min(w2/e1,nn);
   ll ww2=w2-(p*e1);
   ll q=min(ww2/e2,mm);
 
   //cout<<x<<" "<<y<<" "<<p<<" "<<q<<endl;
 
   ans=max(ans,x+y+p+q);
  }
  
  cout<<ans<<endl;
 }
 
 return 0;
}