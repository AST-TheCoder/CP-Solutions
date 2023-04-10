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
 
  ll a[n+1];
  for(ll i=1;i<=n;i++) cin>>a[i];
 
  for(ll i=2;i<=n-1;i++){
   if(a[i]>a[i-1] && a[i]>a[i+1]){
       cout<<"YES"<<endl;
       cout<<i-1<<" "<<i<<" "<<i+1<<endl;
       goto read;
   }
  }
  cout<<"NO"<<endl;
 }
 
    return 0;
}