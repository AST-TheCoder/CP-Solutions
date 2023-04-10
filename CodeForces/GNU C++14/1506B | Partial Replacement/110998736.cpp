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
  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  ll ans=0,c=-1,id=-1;
  for(ll i=0;i<n;i++){
   if(s[i]=='*' && c==-1){
    ans++;
    s[i]='-';
    c=0;
    continue;
   }
   if(c!=-1){
    if(s[i]=='*') id=i;
    if(c+1==k && id!=-1){
     s[id]='-';
     ans++;
     c=i-id;
     id=-1;
    }
    else c++;
   }
   //cout<<s<<" "<<id<<" "<<c<<" "<<i<<endl;
  }
  if(id!=-1) ans++;
  cout<<ans<<endl;
 }
 
 return 0;
}