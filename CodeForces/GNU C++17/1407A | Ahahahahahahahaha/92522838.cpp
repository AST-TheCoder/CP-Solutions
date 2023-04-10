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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n;
  cin>>n;
 
  ll a[n+1],o=0,z=0,id,k=n/2;
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   if(a[i]) o++,id=i;
   else z++;
  }
 
  if((o>=n/2 && !(o%2)) || ((o-1)>=n/2 && o%2)){
   if(o%2) o--;
   cout<<o<<endl;
   for(ll i=1;i<=o;i++) cout<<1<<" ";
   cout<<endl;
  }
  else if(z>=n/2){
   cout<<z<<endl;
   for(ll i=1;i<=z;i++) cout<<0<<" ";
   cout<<endl;
  }
 }
 
 return 0;
}