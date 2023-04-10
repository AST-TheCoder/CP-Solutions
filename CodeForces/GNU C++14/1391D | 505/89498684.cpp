#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
string s[1000007];
ll p[]={0,1,1,2,1,2,2,3};
 
ll cnt(ll n,ll m,ll x,ll y,ll u,ll v)
{
 ll ret=0;
 
 for(ll i=0;i<m;i++){
  ll bin=0;
  for(ll j=0;j<n;j++) bin+=((s[j][i]-'0')*pow(2LL,j));
 
  if(i%2) ret+=min(p[bin^x],p[bin^y]);
  else ret+=min(p[bin^u],p[bin^v]);
 }
 
 return ret;
}
 
ll solve(ll n,ll m,ll x,ll y,ll u,ll v)
{
 return min(cnt(n,m,x,y,u,v),cnt(n,m,u,v,x,y));
}
 
int main()
{
 
 ll n,m;
 cin>>n>>m;
 for(ll i=0;i<n;i++) cin>>s[i];
 
 if(n>=4 && m>=4) cout<<-1<<endl;
 if(n==1 || m==1) cout<<0<<endl;
 
 if(n>m){
  string x[m];
  for(ll j=0;j<m;j++){
   for(ll i=0;i<n;i++){
    x[j]+=s[i][j];
   }
  }
  for(ll i=n-1;i>=0;i--){
   if(i>=m) s[i].clear();
   else s[i]=x[i];
  }
  swap(n,m);
 }
 
 
 if(n==2) cout<<solve(n,m,0,3,1,2);
 if(n==3) cout<<min(solve(n,m,0,7,2,5),solve(n,m,1,6,3,4));
 
 return 0;
}