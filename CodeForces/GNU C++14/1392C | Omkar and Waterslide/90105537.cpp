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
 
 read:
 while(t--){
  ll n;
  cin>>n;
 
  ll a[n],ans=0;
  for(ll i=0;i<n;i++) cin>>a[i];
  for(ll i=n-1;i>=1;i--){
   if(a[i-1]>a[i]) ans+=(a[i-1]-a[i]);
  }
  cout<<ans<<endl;
 }
 
 return 0;
}