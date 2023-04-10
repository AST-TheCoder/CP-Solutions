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
  ll n,ans=1;
  cin>>n;
  ll a[n+1];
 
  for(ll i=1;i<=n;i++) cin>>a[i];
 
  ll i;
  for(i=n-1;i>=1;i--){
   if(a[i]>=a[i+1]) ans++;
   else break;
  }
  for(;i>=1;i--){
   if(a[i]<=a[i+1]) ans++;
   else break;
  }
  cout<<n-ans<<endl;
 }
 
 return 0;
}