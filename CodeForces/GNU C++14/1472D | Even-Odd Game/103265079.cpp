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
  ll n;
  cin>>n;
  vector<ll> alice,bob;
  ll a=0,b=0;
  for(ll i=0;i<n;i++){
   ll x;
   cin>>x;
   if(x%2){
    bob.pb(x);
   }
   else{
    alice.pb(x);
   }
  }
  sort(all(alice),greater<ll>());
  sort(all(bob),greater<ll>());
 
  for(ll turn=1,i=0,j=0;turn<=n;turn++){
   if(turn%2){
    if(i>=alice.size()) j++;
    else if(j>=bob.size() || alice[i]>=bob[j]){
     a+=alice[i];
     i++;
    }
    else j++;
   }
   else{
    if(j>=bob.size()) i++;
    else if(i>=alice.size() || bob[j]>=alice[i]){
     b+=bob[j];
     j++;
    }
    else i++;
   }
  }
 
  if(a==b) cout<<"Tie"<<endl;
  else if(a>b) cout<<"Alice"<<endl;
  else cout<<"Bob"<<endl;
 }
 
 return 0;
}