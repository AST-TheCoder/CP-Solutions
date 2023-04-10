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
  ll a,b,n;
  cin>>a>>b>>n;
 
  pair<ll,ll> x[n];
  for(ll i=0;i<n;i++) cin>>x[i].first;
  for(ll i=0;i<n;i++) cin>>x[i].second;
 
  sort(x,x+n);
  for(ll i=0;i<n;i++){
   ll ac=x[i].second/a-(x[i].second%a==0);
   b-=(ac*x[i].first);
   if(b<=0){
    cout<<"NO"<<endl;
    goto read;
   }
  }
  for(ll i=0;i<n;i++){
   b-=x[i].first;
   if(i+1!=n && b<=0){
    cout<<"NO"<<endl;
    goto read;
   }
  }
  cout<<"YES"<<endl;
 }
 
 return 0;
}