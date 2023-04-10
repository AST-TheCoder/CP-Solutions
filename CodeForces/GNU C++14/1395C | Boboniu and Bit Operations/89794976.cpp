#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n,m;
 scanf("%lli %lli",&n,&m);
 
 ll a[n],b[m];
 vector<ll> x[n];
 for(ll i=0;i<n;i++) scanf("%lli",&a[i]);
 for(ll i=0;i<m;i++) scanf("%lli",&b[i]);
 
 for(ll i=0;i<n;i++){
  for(ll j=0;j<m;j++){
   x[i].pb((a[i]&b[j]));
  }
 }
 
 for(ll k=0;k<512;k++){
  ll oh=0;
  for(ll i=0;i<n;i++){
   ll ok=0;
   for(ll j=0;j<m;j++){
    if((k|x[i][j])==k){
     ok=1;
     break;
    }
   }
   if(!ok){
    oh=1;
    break;
   }
  }
  if(!oh){
   printf("%lli\n",k);
   break;
  }
 }
 
 return 0;
}