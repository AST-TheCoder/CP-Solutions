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
  ll b[1001],ok=-1,bx[m+1];
  memset(b,0,sizeof(b));
  for(ll i=0;i<n;i++){
   ll x;
   cin>>x;
   b[x]=1;
  }
 
  for(ll i=0;i<m;i++){
   ll x;
   cin>>x;
   bx[i]=x;
   if(b[x]) ok=i;
  }
 
  if(ok>=0) cout<<"YES"<<endl<<1<<" "<<bx[ok]<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}