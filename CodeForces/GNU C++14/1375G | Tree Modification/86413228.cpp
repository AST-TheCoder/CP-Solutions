#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 ll n,odd_node=1,even_node=0;
 cin>>n;
 ll dis[n+1];
 memset(dis,0,sizeof(dis));
 
 vector<ll> graph[n+1];
 for(ll i=1;i<n;i++){
  ll u,v;
  cin>>u>>v;
  graph[u].pb(v);
  graph[v].pb(u);
 }
 
 queue<ll> q;
 q.push(1LL);
 dis[1]=1;
 
 while(!q.empty()){
  ll u=q.front();
  q.pop();
  for(ll i=0;i<graph[u].size();i++){
   ll v=graph[u][i];
   if(!dis[v]){
    q.push(v);
    dis[v]=dis[u]+1;
    if(dis[v]%2) odd_node++;
    else even_node++;
   }
  }
 }
 
 cout<<min(odd_node,even_node)-1<<endl;
 
    return 0;
}