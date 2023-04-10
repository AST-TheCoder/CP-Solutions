#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll n,k;
  cin>>n;
 
  vector<ll> a;
  for(ll i=0;i<n;i++){
   ll x;
   cin>>x;
   a.push_back(x);
  }
  sort(a.begin(),a.end());
  for(k=1;k<1024;k++){
   ll ok=0;
   vector<ll> x;
   for(ll i=0;i<n;i++) x.push_back(a[i]^k);
   sort(x.begin(),x.end());
   for(ll i=0;i<n;i++){
    if(a[i]!=x[i]) ok=1;
   }
   if(!ok) break;
  }
  if(k==1024) cout<<-1<<endl;
  else cout<<k<<endl;
 }
 
 return 0;
}