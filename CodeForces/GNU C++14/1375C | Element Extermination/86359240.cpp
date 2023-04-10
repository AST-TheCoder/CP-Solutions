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
  ll n,m;
  cin>>n;
 
  ll id[n+1];
  for(ll i=1;i<=n;i++){
   ll x;
   cin>>x;
   id[x]=i;
  }
 
  for(ll i=n;i>=1;i--){
   if(id[i]==n){
    cout<<"YES"<<endl;
    goto read;
   }
   if(id[i]==1){
    cout<<"NO"<<endl;
    goto read;
   }
  }
 }
 
    return 0;
}