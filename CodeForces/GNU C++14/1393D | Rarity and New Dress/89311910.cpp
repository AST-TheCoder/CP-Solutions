#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n,m,ans=0;
 cin>>n>>m;
 
 ll cnt[n][m];
 memset(cnt,0,sizeof(cnt));
 
 ll dx[]={-1,0,1,0};
 ll dy[]={0,1,0,-1};
 
 string s[n];
 for(ll i=0;i<n;i++) cin>>s[i];
 
 queue<pair<ll,ll>> q;
 for(ll i=0;i<n;i++){
  for(ll j=0;j<m;j++){
   for(ll k=0;k<4;k++){
    ll x=i+dx[k],y=j+dy[k];
    if(i==0 || i==n-1 || j==0 || j==m-1 || s[i][j]!=s[x][y]){
     cnt[i][j]=1;
     q.push(mp(i,j));
     ans++;
     break;
    }
   }
  }
 }
 
 while(!q.empty()){
  pair<ll,ll> p=q.front();
  q.pop();
 
  ll i=p.first,j=p.second;
  for(ll k=0;k<4;k++){
   ll x=i+dx[k],y=j+dy[k];
   if(x>=0 && x<=n-1 && y>=0 && y<=m-1 && s[i][j]==s[x][y] && !cnt[x][y]){
    cnt[x][y]=cnt[i][j]+1;
    q.push(mp(x,y));
    ans+=cnt[x][y];
   }
  }
 }
 
 cout<<ans<<endl;
 
 return 0;
}