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
 
pair<ll,pair<ll,ll>> nodes[4000007];
string s;
 
void build(ll n,ll l,ll r){
 if(l==r){
  if(s[l]=='+') nodes[n]={1,{0,1}};
  else nodes[n]={-1,{-1,0}};
  //cout<<l+1<<" "<<r+1<<" "<<nodes[n].first<<" "<<nodes[n].second.first<<" "<<nodes[n].second.second<<endl;
  return;
 }
 
 ll m=(l+r)/2,lf=2*n,rt=2*n+1;
 build(2*n,l,m);
 build(2*n+1,m+1,r);
 
 ll fr=nodes[lf].first+nodes[rt].first;
 ll sc=min(nodes[lf].first+nodes[rt].second.first,nodes[lf].second.first);
 ll tr=max(nodes[lf].first+nodes[rt].second.second,nodes[lf].second.second);
 
 nodes[n]={fr,{sc,tr}};
 //cout<<l+1<<" "<<r+1<<" "<<nodes[n].first<<" "<<nodes[n].second.first<<" "<<nodes[n].second.second<<endl;
}
 
pair<ll,pair<ll,ll>> query(ll n,ll l,ll r,ll i,ll j){
 if(j<l || i>r) return {0,{0,0}};
 if(l>=i && r<=j){
  return nodes[n];
 }
 
 ll m=(l+r)/2,lf=2*n,rt=2*n+1;
 pair<ll,pair<ll,ll>> x=query(2*n,l,m,i,j);
 pair<ll,pair<ll,ll>> y=query(2*n+1,m+1,r,i,j);
 
 ll fr=x.first+y.first;
 ll sc=min(x.first+y.second.first,x.second.first);
 ll tr=max(x.first+y.second.second,x.second.second);
 
 return {fr,{sc,tr}};
}
 
int main()
{ 
 
 ll t;
 cin>>t;
 
 
 while(t--){
  ll n,q;
  cin>>n>>q;
  cin>>s;
  for(ll i=0;i<=2*n+1;i++) nodes[i]={0,{0,0}};
  build(1,0,n-1);
  while(q--){
   ll l,r;
   cin>>l>>r;
   pair<ll,pair<ll,ll>> left,right;
   if(l-2>=0) left=query(1,0,n-1,0,l-2);
   else left={0,{0,0}};
   if(r<n) right=query(1,0,n-1,r,n-1);
   else right={0,{0,0}};
   //cout<<1<<" "<<l-1<<" "<<left.second.first<<" "<<left.second.second<<endl;
   //cout<<r+1<<" "<<n<<" "<<right.second.first<<" "<<right.second.second<<endl;
   ll lm=min(left.first+right.second.first,left.second.first);
   ll rm=max(left.first+right.second.second,left.second.second);
   cout<<rm-lm+1<<endl;
  }
 }
 
 return 0;
}