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
  ll x,y;
  cin>>x>>y;
 
  ll l=0,r=0,u=0,d=0;
 
  string s;
 
  cin>>s;
 
  for(ll i=0;i<s.size();i++){
   if(s[i]=='L') l++;
   if(s[i]=='R') r++;
   if(s[i]=='U') u++;
   if(s[i]=='D') d++;
  }
  //cout<<l<<" "<<r<<" "<<u<<" "<<d<<endl;
  if(((x<=r && x>=0) || (x>=-l && x<=0)) && ((y<=u && y>=0) || (y>=-d && y<=0))){
   cout<<"YES"<<endl;
  }
  else cout<<"NO"<<endl;
 }
 
 return 0;
}