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
  ll n,a,b;
  cin>>n>>a>>b;
 
  ll d=b-a;
  for(ll i=1;i<=d;i++){
   if(!(d%i) && d/i+1<=n){
    while(b-(d+i)>0 && d/i+1<n){
     d+=i;
    }a=b-d;
 
    for(ll j=0;j<n;j++){
     cout<<a<<" ";
     a+=i;
    }cout<<endl;
 
    goto read;
   }
  }
 }
 
 return 0;
}