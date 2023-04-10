#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll n,m;
 cin>>n>>m;
 vector<ll> a[n+1];
 
 for(ll i=1;i<=m;i++){
  ll x,y;
  cin>>x>>y;
  a[x].push_back(y);
  a[y].push_back(x);
 }
 
 pair<ll,ll> t[n+1];
 for(ll i=1;i<=n;i++){
  cin>>t[i].first;
  t[i].second=i;
 }
 sort(t+1,t+n+1);
 
 ll c[n+1];
 memset(c,0,sizeof(c));
 vector<ll> ans;
 
 for(ll i=1;i<=n;i++){
  ll blog=t[i].second,ok=1;
 
  vector<ll> x;
  for(ll j=0;j<a[blog].size();j++){
   ll nbr_blog=a[blog][j];
   x.push_back(c[nbr_blog]);
  }
  sort(x.begin(),x.end());
  
  for(ll j=0;j<x.size();j++){
   if(ok==x[j]) ok++;
  }
  
  if(ok==t[i].first){
   ans.push_back(blog);
   c[blog]=ok;
  }
  else{
   cout<<-1<<endl;
   return 0;
  }
 }
 
 for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
 
 return 0;
}