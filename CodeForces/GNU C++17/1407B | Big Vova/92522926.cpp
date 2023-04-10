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
 
  ll a[n+1],m=0,id=-1;
 
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   if(m<a[i]){
    m=a[i];
    id=i;
   }
  }
 
  cout<<m<<" ";
  a[id]=-1;
  ll g=m;
  for(ll i=2;i<=n;i++){
   m=0,id=-1;
   for(ll j=1;j<=n;j++){
    if(a[j]==-1) continue;
    if(__gcd(g,a[j])>=m){
     m=__gcd(g,a[j]);
     id=j;
    }
   }
   cout<<a[id]<<" ";
   g=__gcd(g,a[id]);
   a[id]=-1;
  }cout<<endl;
 
 }
 
 return 0;
}