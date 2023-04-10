#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main(){
 
 ll n,a,r,m,ans=-1;
 cin>>n>>a>>r>>m;
 m=min(m,a+r);
 ll h[n+1],p[n+1];
 p[0]=0;
 for(ll i=1;i<=n;i++) cin>>h[i];
 sort(h+1,h+n+1);
 for(ll i=1;i<=n;i++) p[i]=p[i-1]+h[i];
 
 for(ll i=1;i<=n;i++){
  ll x=h[i]*i-p[i];
  ll y=p[n]-p[i]-(h[i]*(n-i));
  ll v=min(x,y);
  x-=v;
  y-=v;
  ll cost=v*m+x*a+y*r;
  //cout<<v<<" "<<x<<" "<<y<<" "<<cost<<" "<<ans<<endl;
  if(ans==-1) ans=cost;
  ans=min(ans,cost);
 }
 
 ll hg=p[n]/n,x=0,y=0,v;
 for(ll i=1;i<=n;i++){
  if(h[i]<hg) x+=hg-h[i];
  else y+=h[i]-hg;
 }
 v=min(x,y);
 x-=v;
 y-=v;
 ll cost=v*m+x*a+y*r;
 ans=min(ans,cost);
 
 hg=p[n]/n+1,x=0,y=0;
 for(ll i=1;i<=n;i++){
  if(h[i]<hg) x+=hg-h[i];
  else y+=h[i]-hg;
 }
 v=min(x,y);
 x-=v;
 y-=v;
 cost=v*m+x*a+y*r;
 ans=min(ans,cost);
 
 cout<<ans<<endl;
 
 return 0;
}