#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
string s;
ll dp[131073][27];
 
ll solve(ll l,ll r,ll p,ll q,char x){
 if(dp[l][x-'a']!=-1) return dp[l][x-'a'];
 ll c=0,u=0,v=0;
 for(ll i=l;i<=r;i++) if(s[i]!=x) c++;
 
 
 if(p!=q){
  u=solve(p,(p+q)/2,(p+q)/2+1,q,x+1);
  v=solve((p+q)/2+1,q,p,(p+q)/2,x+1);
 }
 else{
  if(s[p]!=x+1) u=1,v=1;
 }
 
 //cout<<l<<" "<<r<<" "<<p<<" "<<q<<" "<<x<<" "<<c<<" "<<u<<" "<<v<<endl;
 return dp[l][x-'a']=c+min(u,v);
}
 
int main()
{
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,x,y;
  cin>>n>>s;
 
  for(ll i=0;i<n;i++){
   for(ll j=0;j<27;j++){
    dp[i][j]=-1;
   }
  }
 
  if(n==1){
   if(s=="a") cout<<0<<endl;
   else cout<<1<<endl;
   goto read;
  }
 
  x=solve(0,n/2-1,n/2,n-1,'a');
  y=solve(n/2,n-1,0,n/2-1,'a');
 
  //cout<<x<<" "<<y<<endl;
 
  cout<<min(x,y)<<endl;
 }
 
 return 0;
}