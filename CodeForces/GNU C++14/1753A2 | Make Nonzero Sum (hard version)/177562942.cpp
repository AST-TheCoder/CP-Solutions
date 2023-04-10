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
 
  ll a[n+1],s=0;
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   s+=a[i];
  }
  if(abs(s)%2){
   cout<<-1<<endl;
   continue;
  }
  if(s==0){
   cout<<n<<endl;
   for(ll i=1;i<=n;i++){
    cout<<i<<" "<<i<<endl;
   }
   continue;
  }
 
  ll c=abs(s)/2;
  s/=abs(s);
  vector<ll> ans;
  for(ll i=n;i>=1;i--){
   ans.pb(i);
   if(c && s==a[i]){
    i--;
    c--;
   } 
  }
  cout<<ans.size()<<endl;
  reverse(all(ans));
  for(ll i=0,l=1;i<ans.size();i++){
   cout<<l<<" "<<ans[i]<<endl;
   l=ans[i]+1;
  }
 }
 
 return 0;
}