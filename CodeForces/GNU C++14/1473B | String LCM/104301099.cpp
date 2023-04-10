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
  string s,t,ans;
  cin>>s>>t;
  if(s.size()>t.size()) swap(s,t);
 
  ans=t;
  ll i=0,j=0;
  while(1){
   if(i>=ans.size()){
    if(j>=s.size()) break;
    else ans+=t;
   }
   if(j>=s.size()) j=0;
   if(ans[i]!=s[j]){
    cout<<"-1"<<endl;
    goto read;
   }
   i++,j++;
  //cout<<ans<<endl;
  }
  cout<<ans<<endl;
 }
 
 return 0;
}