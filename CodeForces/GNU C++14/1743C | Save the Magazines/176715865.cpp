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
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n;
  cin>>n;
 
  string s;
  ll a[n],ans=0;
  cin>>s;
  for(ll i=0;i<n;i++) cin>>a[i];
  min_heap<ll> q;
  for(ll i=n-1;i>=0;i--){
   if(s[i]=='1') q.push(a[i]);
   else{
    q.push(a[i]);
    q.pop();
    while(!q.empty()){
     ans+=q.top();
     q.pop();
    }
   }
  }
  while(!q.empty()){
   ans+=q.top();
   q.pop();
  }
  cout<<ans<<endl;
 }
 
 return 0;
}