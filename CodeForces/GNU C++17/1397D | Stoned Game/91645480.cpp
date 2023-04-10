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
 
 while(t--){
  ll n,s=0,m=0;
  cin>>n;
  for(ll i=0;i<n;i++){
   ll x;
   cin>>x;
   s+=x;
   m=max(m,x);
  }
 
  if(m>s-m || s%2) cout<<"T"<<endl;
  else cout<<"HL"<<endl;
 }
 
 return 0;
}