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
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  
  sort(a,a+n);
  for(ll i=1;i<n;i++){
   if(a[i]-a[i-1]>1){
    cout<<"NO"<<endl;
    goto read;
   }
  }
 
  cout<<"YES"<<endl;
 }
 
 return 0;
}