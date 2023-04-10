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
  string s;
  char x;
  cin>>s;
 
  ll lr[n],rl[n];
  memset(lr,0,sizeof(lr));
  memset(rl,0,sizeof(rl));
 
  lr[0]=1;
  for(ll i=1;i<n;i++){
   if(s[i]!=s[i-1]) lr[i]=lr[i-1];
   lr[i]+=1;
  }
 
  rl[n-1]=1;
  for(ll i=n-2;i>=0;i--){
   if(s[i]!=s[i+1]) rl[i]=rl[i+1];
   rl[i]+=1;
  }
 
  for(ll i=0;i<=n;i++){
   ll ans=1;
   if(i!=0 && s[i-1]=='L') ans+=lr[i-1];
   if(i!=n && s[i]=='R') ans+=rl[i];
   cout<<ans<<" ";
  }cout<<endl;
 }
 
 return 0;
}