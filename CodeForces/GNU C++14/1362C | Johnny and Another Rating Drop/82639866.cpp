#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 vector<pair<ll,ll>> x;
 ll sz=0,sum=0;
 x.push_back({sz,sum});
 
 for(ll i=1;sz<1000000000000000000;i++){
  sz=2*sz+1;
  sum=2*sum+i;
  x.push_back({sz,sum});
 }
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n,ans=0;
  cin>>n;
  for(ll i=x.size()-1;i>=1;i--){
   if(x[i].first<=n){
    n-=x[i].first;
    ans+=x[i].second;
    if(n){
     ans+=(i+1);
     n--;
    }
   }
  }
  cout<<ans<<endl;
 }
 
 return 0;
}