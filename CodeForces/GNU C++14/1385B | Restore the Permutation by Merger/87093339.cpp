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
  bool chk[n+1];
  memset(chk,0,sizeof(chk));
  ll ans[n+1];
 
  for(ll i=1,j=1;i<=2*n;i++){
   ll x;
   cin>>x;
   if(!chk[x]){
    ans[j]=x;
    j++;
    chk[x]=1;
   }
  }
 
  for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
  cout<<endl;
 }
 
 return 0;
}