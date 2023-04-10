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
 
 read:
 while(t--){
  ll n;
  cin>>n;
 
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  if(n==1){
   cout<<0<<endl;
   goto read;
  }
  ll c=-1;
  for(ll i=0;i<n-1;i++){
   if(a[i]<=a[i+1]){
    if(c==-1) c=a[i+1]-a[i];
    else{
     if(a[i+1]-a[i]!=c){
      cout<<-1<<endl;
      goto read;
     }
    }
   }
  }
  if(c==-1){
   ll x=a[0]-a[1];
   for(ll i=1;i<n-1;i++){
    if(a[i]-a[i+1]!=x){
     cout<<-1<<endl;
     goto read;
    }
   }
   cout<<0<<endl;
   goto read;
  }
 
  ll m=-1;
  for(ll i=0;i<n-1;i++){
   if(a[i]>a[i+1]){
    m=(a[i]+c)-a[i+1];
    break;
   }
  }
  if(m==-1){
   cout<<0<<endl;
   goto read;
  }
  if(m<=a[0] || c>=m){
   cout<<-1<<endl;
   goto read;
  }
  for(ll i=1;i<n;i++){
   //cout<<a[i-1]<<" "<<c<<" "<<m<<" "<<(a[i-1]+c)%m<<" "<<a[i]<<endl;
   if(((a[i-1]+c)%m)!=a[i]){
    cout<<-1<<endl;
    goto read;
   }
  }
  cout<<m<<" "<<c<<endl;
 }
 
 return 0;
}