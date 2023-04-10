#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
 
 ll n;
 cin>>n;
 
 string s,t;
 cin>>t;
 
 if(count(all(t),'0')==n){
  cout<<0<<endl;
  return 0;
 }
 
 for(ll i=0;i<n;i++){
  if(t[i]=='0' && s.size()==0) continue;
  s+=t[i];
 }
 n=s.size();
 if(count(all(s),'1')==n){
  cout<<s<<endl;
  return 0;
 }
 s="0"+s;
 ll c[n+1];
 c[0]=0;
 for(ll i=1;i<=n;i++){
  c[i]=c[i-1];
  if(s[i]=='1') c[i]++;
 }
 
 ll l=1,r=0;
 set<ll> p;
 for(ll i=1;i<=n;i++){
  if(s[i]=='0') break;
  r++;
  p.insert(r);
 }
 
 for(ll i=1;i<=n;i++){
  if(s[i]=='1') continue;
  ll v=0;
  set<ll> temp;
  for(auto x:p){
   if(s[i-x]=='0') continue;
   temp.insert(x);
   v=max(v,x);
  }
  if(!v) continue;
  r=v;
  l=*temp.begin();
  p.clear();
  p=temp;
 }
 
 
 
 //cout<<l<<" "<<r<<endl;
 
 for(ll i=1;i<=n;i++){
  if(s[i]=='1') cout<<1;
  else{
   if(s[i-r]=='1') cout<<1;
   else cout<<0;
  }
 }cout<<endl;
 
 return 0;
}