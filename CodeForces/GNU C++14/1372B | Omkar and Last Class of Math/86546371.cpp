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
  
  for(ll i=2;i<=sqrt(n)+1;i++){
   if(n%i==0){
    ll x=n/i;
    cout<<x<<" "<<n-x<<endl;
    goto read;
   }
  }
  cout<<1<<" "<<n-1<<endl;
 }
 
    return 0;
}