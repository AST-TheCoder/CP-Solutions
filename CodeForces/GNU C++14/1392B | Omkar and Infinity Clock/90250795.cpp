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
  ll n,k;
  cin>>n>>k;
 
  ll a[n],m=-INT_MAX,x=0;
  for(ll i=0;i<n;i++){
   cin>>a[i];
   m=max(a[i],m);
  }
  for(ll i=0;i<n;i++){
   a[i]=m-a[i];
   x=max(x,a[i]);
  }k--;
  
  k%=2;
  for(ll i=0;i<n && k;i++){
   a[i]=x-a[i];
  }
   
  for(ll i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
 }
 
 return 0;
}