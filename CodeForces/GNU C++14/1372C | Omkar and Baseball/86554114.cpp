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
  
  ll a[n+1],l=1,r=n;
  for(ll i=1;i<=n;i++) cin>>a[i];
 
  while(r>=1 && a[r]==r) r--;
  while(l<=n && a[l]==l) l++;
 
  if(l>r){
   cout<<0<<endl;
   goto read;
  }
 
  for(ll i=l;i<=r;i++){
   if(a[i]==i){
    cout<<2<<endl;
    goto read;
   }
  }
 
  cout<<1<<endl;
 }
 
    return 0;
}