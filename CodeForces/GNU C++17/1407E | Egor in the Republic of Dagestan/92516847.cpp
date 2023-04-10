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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll n,m;
 cin>>n>>m;
 
 ll ok[n+1],dis[n+1];
 vector<pair<ll,ll>> graph[n+1];
 queue<ll> q;
 memset(dis,-1,sizeof(dis));
 memset(ok,-1,sizeof(ok));
 
 for(ll i=1;i<=m;i++){
  ll x,y,t;
  cin>>x>>y>>t;
  if(x!=y) graph[y].pb(mp(x,t));
 }
 
 ok[n]=1;
 dis[n]=0;
 q.push(n);
 while(!q.empty()){
  ll u=q.front();
  q.pop();
  for(ll i=0;i<graph[u].size();i++){
   ll v=graph[u][i].first,t=graph[u][i].second;
   if(ok[v]==-1){
    ok[v]=(t==0);
   }
  }
  for(ll i=0;i<graph[u].size();i++){
   ll v=graph[u][i].first,t=graph[u][i].second;
   if(dis[v]==-1 && ok[v]==t){
    dis[v]=dis[u]+1;
    q.push(v);
   }
  }
 }
 
 cout<<dis[1]<<endl;
 for(ll i=1;i<=n;i++){
  if(ok[i]==-1) ok[i]=1;
  cout<<ok[i];
 }
 cout<<endl;
 
 return 0;
}