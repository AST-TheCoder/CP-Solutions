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
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  ll p[n],q[n];
  ll x[n+5],y[n+5];
  memset(x,0,sizeof(x));
  memset(y,0,sizeof(y));
 
  p[0]=a[0];
  x[p[0]]=1;
  for(ll i=1,j=1;i<n;i++){
   if(a[i]!=a[i-1]){
    p[i]=a[i];
    x[p[i]]=1;
    continue;
   }
   while(x[j]) j++;
   p[i]=j;
   x[j]=1;
  }
  for(ll i=0;i<n;i++) cout<<p[i]<<" ";cout<<endl;
 
  priority_queue<ll> s;
  q[0]=a[0];
  y[q[0]]=1;
  ll j=1;
  for(;j<a[0];j++) s.push(j);
  for(ll i=1;i<n;i++){
   if(a[i]!=a[i-1]){
    q[i]=a[i];
    y[q[i]]=1;
    while(j<q[i]){
     if(!y[j]) s.push(j);
     j++;
    }
    continue;
   }
   q[i]=s.top();
   s.pop();
  }
  for(ll i=0;i<n;i++) cout<<q[i]<<" ";cout<<endl;
 }
 
 return 0;
}