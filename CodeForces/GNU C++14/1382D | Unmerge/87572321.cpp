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
  ll a[2*n+1],idx[2*n+1],chk=2*n;
  vector<ll> coin;
  coin.pb(0LL);
 
  idx[0]=0;
  for(ll i=1;i<=2*n;i++){
   cin>>a[i];
   idx[a[i]]=i;
  }
  for(ll i=2*n;i>=1;i--){
   if(idx[i]<=chk){
    coin.pb(chk-idx[i]+1);
    chk=idx[i]-1;
   }
  }
 
  //for(ll i=1;i<coin.size();i++) cout<<coin[i]<<" ";cout<<endl;
 
  ll cost=n,coin_no=coin.size()-1;
  ll dp[coin_no+1][cost+1];
 
  for(ll i=0;i<=coin_no;i++){
   for(ll j=0;j<=cost;j++){
    if(!j) dp[i][j]=1;
    else dp[i][j]=0;
   }
  }
 
  for(ll i=1;i<=coin_no;i++){
   for(ll j=1;j<=cost;j++){
    dp[i][j]=dp[i-1][j];
    if(coin[i]<=j) dp[i][j]|=dp[i-1][j-coin[i]];   
   }
  }
 
  if(dp[coin_no][cost]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}