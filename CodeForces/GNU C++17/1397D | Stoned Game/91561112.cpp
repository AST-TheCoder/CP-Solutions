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
 read:
 while(t--){
  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
 
  ll ok=0,id=-1;
  while(1){
   ll m=0,x=-1;
   for(ll i=0;i<n;i++){
    if(i==id) continue;
    if(a[i]>m){
     m=a[i];
     x=i;
    }
   }
   if(m){
    ok=(ok==0);
    a[x]--;
    id=x;
   }
   else{
    if(ok) cout<<"T"<<endl;
    else cout<<"HL"<<endl;
    goto read;
   }
  }
 }
 
 return 0;
}