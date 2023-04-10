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
  ll n,ans=0,x=1;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++){
   cin>>a[i];
  }
 
  for(ll i=1;i<n;){
   ll c=x;
   x=0;
   ans++;
   while(c){
    x++;
    i++;
    if(i==n) break;
    if(a[i-1]>a[i]){
     c--;
    }
   }
  }
 
  cout<<ans<<endl;
 }
 
 return 0;
}