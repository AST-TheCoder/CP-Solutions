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
  ll x1,y1,z1;
  cin>>x1>>y1>>z1;
  ll x2,y2,z2;
  cin>>x2>>y2>>z2;
 
  ll chk=max(0LL,y1-(x2+y2)),ans;
 
  if(chk) ans=-2*chk;
  else ans=2*min(z1,(y2-max(0LL,y1-x2)));
 
  cout<<ans<<endl;
 }
 
 return 0;
}