#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
ll fact[1000007],mod=1000000007;
 
ll bigmod(ll n,ll p){
 if(p==0) return 1;
 if(p==1)return (n)%mod;
 if(p%2)return (bigmod(n,p-1)*n)%mod;
 else{
  ll x=bigmod(n,p/2);
  return (x*x)%mod;
 }
}
 
ll modinverse(ll n){
 return bigmod(n,mod-2)%mod;
}
 
int main()
{
 
 
 ll n,ans=0;
 scanf("%lli",&n);
 
 fact[0]=1;
 for(ll i=1;i<=n;i++){
  fact[i]=(i*fact[i-1]);
  fact[i]%=mod;
 }
 
 for(ll i=0;i<n;i++){
  ans+=(fact[n-1]*modinverse((fact[i]*fact[n-i-1])%mod))%mod;
  ans%=mod;
 }
 
 printf("%lli",(fact[n]-ans+mod)%mod);
 
 return 0;
}