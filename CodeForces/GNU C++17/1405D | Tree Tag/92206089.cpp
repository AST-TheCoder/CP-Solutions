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
 
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,a,b,d1,d2;
  cin>>n>>a>>b>>d1>>d2;
  vector<ll> graph[n+1];
  for(ll i=1;i<n;i++){
   ll x,y;
   cin>>x>>y;
   graph[x].pb(y);
   graph[y].pb(x);
  }
 
  queue<ll> q;
  q.push(a);
  ll dis[n+1],d=0,id=1;
  memset(dis,-1,sizeof(dis));
  dis[a]=0;
 
  while(!q.empty()){
   ll u=q.front();
   q.pop();
 
   for(ll i=0;i<graph[u].size();i++){
    ll v=graph[u][i];
    if(dis[v]==-1){
     dis[v]=dis[u]+1;
     id=v;
     d=dis[v];
     q.push(v);
    }
   }
  }
 
  //cout<<d<<" "<<id<<" ";
  if(dis[b]<=d1){
   cout<<"Alice"<<endl;
   goto read;
  }
 
  q.push(id);
  memset(dis,-1,sizeof(dis));d=0;
  dis[id]=0;
 
  while(!q.empty()){
   ll u=q.front();
   q.pop();
   for(ll i=0;i<graph[u].size();i++){
    ll v=graph[u][i];
    if(dis[v]==-1){
     dis[v]=dis[u]+1;
     d=dis[v];
     q.push(v);
    }
   }
  }
 
  //cout<<d<<endl;
 
  d2=min(d,d2);
  if(d2>2*d1) cout<<"Bob"<<endl;
  else cout<<"Alice"<<endl;
 }
 
 return 0;
}