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
  ll n,m;
  cin>>n>>m;
 
  ll chk[1001],ok=0,b[m+1];
  memset(chk,0,sizeof(chk));
 
  for(ll i=1;i<=n;i++){
   ll x;
   cin>>x;
   chk[x]=1;
  }
 
  for(ll i=1;i<=m;i++){
   ll x;
   cin>>x;
   b[i]=x;
 
   if(chk[x]) ok=i;
  }
 
  if(ok) cout<<"YES"<<endl<<1<<" "<<b[ok]<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}