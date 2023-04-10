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
 
  ll id[n+1],a[n+1];
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   id[a[i]]=i;
  }
 
  for(ll i=n,l=1,r=n;i>=1;i--){
   if(id[i]==l) l++;
   else if(id[i]==r) r--;
   else{
    cout<<"YES"<<endl;
    for(ll j=1;j<id[i];j++){
     if(a[j]<a[id[i]]){
      cout<<j<<" ";
      break;
     }
    }
    cout<<id[i]<<" ";
    for(ll j=id[i]+1;j<=n;j++){
     if(a[j]<a[id[i]]){
      cout<<j<<endl;
      break;
     }
    }
    goto read;
   }
  }
  cout<<"NO"<<endl;
 }
 
    return 0;
}