#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
 
int main()
{
 
 ll t;
 cin>>t;
 
 while(t--){
  vector<ll> odd,even;
  ll n,cnt=0;
  cin>>n;
 
  for(ll i=1;i<=2*n;i++){
   ll x;
   cin>>x;
   if(x%2) odd.pb(i);
   else even.pb(i);
  }
 
  for(ll i=1;i<odd.size() && cnt<n-1;i+=2){
   cout<<odd[i-1]<<" "<<odd[i]<<endl;
   cnt++;
  }
 
  for(ll i=1;i<even.size() && cnt<n-1;i+=2){
   cout<<even[i-1]<<" "<<even[i]<<endl;
   cnt++;
  }
 }
 
    return 0;
}