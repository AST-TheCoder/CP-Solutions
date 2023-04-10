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
 ll n;
 cin>>n;
 ll a[n],x=Max;
 
 for(ll i=0;i<n;i++){
  cin>>a[i];
 }
 sort(a,a+n);
 
 for(ll i=1;;i++){
  ll c=0,p=1,ok=0;
  for(ll j=0;j<n;j++){
   c+=abs(p-a[j]);
   p*=i;
   if(c>x){
    ok=1;
    break;
   }
  }
  if(ok) break;
  x=c;
 }
 
 cout<<x<<endl;
 
 return 0;
}