#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll t;
 cin>>t;
 while(t--){ 
  ll n;
  cin>>n;
  vector<ll> a[n+1],dis[n+1];
 
  for(ll i=1;i<n;i++){
   ll x,y;
   cin>>x>>y;
   a[x].pb(y);
   a[y].pb(x);
  }
 
  ll root,dist,lvl[n+1];
  memset(lvl,-1,sizeof(lvl));
 
  cout<<"? "<<n;
  for(ll i=1;i<=n;i++) cout<<" "<<i;cout<<endl;
  cin>>root>>dist;
 
  queue<ll> q;
  q.push(root);
  lvl[root]=0;
 
  while(!q.empty()){
   ll u=q.front();
   q.pop();
 
   for(ll i=0;i<a[u].size();i++){
    ll v=a[u][i];
    if(lvl[v]==-1){
     lvl[v]=lvl[u]+1;
     dis[lvl[v]].pb(v);
     q.push(v);
    }
   }
  }
 
  ll l=dist/2,r=dist;
  if(!l) l=1;
 
  while(l<=r){
   ll mid=(l+r)/2,x,p;
   if(!dis[mid].size()){
    r=mid-1;
    continue;
   }
 
   cout<<"? "<<dis[mid].size();
   for(ll i=0;i<dis[mid].size();i++) cout<<" "<<dis[mid][i];cout<<endl;
   cin>>x>>p;
   if(p>dist) r=mid-1;
   else{
    root=x;
    l=mid+1;
   }
  }
 
  memset(lvl,-1,sizeof(lvl));
  dis[dist].clear();
  q.push(root);
  lvl[root]=0;
 
  while(!q.empty()){
   ll u=q.front();
   q.pop();
 
   for(ll i=0;i<a[u].size();i++){
    ll v=a[u][i];
    if(lvl[v]==-1){
     lvl[v]=lvl[u]+1;
     dis[lvl[v]].pb(v);
     q.push(v);
    }
   }
  }
 
  ll end;
  cout<<"? "<<dis[dist].size();
  for(ll i=0;i<dis[dist].size();i++) cout<<" "<<dis[dist][i];cout<<endl;
  cin>>end>>dist;
 
  string s;
  cout<<"! "<<root<<" "<<end<<endl;
  cin>>s;
 }
 
    return 0;
}