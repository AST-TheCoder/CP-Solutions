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
 cin>>t;
 while(t--){
  string a,b;
  cin>>a>>b;
  ll ans=a.size()+b.size();
  ll sz=ans;
  for(ll i=0;i<a.size();i++){
   for(ll j=0,k=i,s=0;j<b.size() && k<a.size();j++,k++){
    if(a[k]!=b[j]) s=0;
    else{
     s++;
     ans=min(ans,sz-2*s);
    }
   }
  }
  for(ll i=0;i<b.size();i++){
   for(ll j=0,k=i,s=0;j<a.size() && k<b.size();j++,k++){
    if(b[k]!=a[j]) s=0;
    else{
     s++;
     ans=min(ans,sz-2*s);
    }
   }
  }
  cout<<ans<<endl;
 }
 
 return 0;
}