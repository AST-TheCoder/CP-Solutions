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
  string a;
  cin>>a;
 
  ll c=0,ans=0;
  vector<ll> x;
  for(ll i=0;i<a.size();i++){
   if(a[i]=='1') c++;
   else{
    if(c){
     x.pb(c);
     c=0;
    }
   }
  }
  if(c) x.pb(c);
 
  sort(all(x),greater<ll>());
  for(ll i=0;i<x.size();i+=2) ans+=x[i];
 
  cout<<ans<<endl;
 }
 
 return 0;
}