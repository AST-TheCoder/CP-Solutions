#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 int t;
 cin>>t;
 
 read:
 while(t--){
  ll n,k;
  cin>>n>>k;
 
  ll odd=0,even=0;
  for(ll i=1;i<=n;i++){
   ll p;
   cin>>p;
   if(p%2) odd++;
   else even++;
  }
 
  if(!odd){
   cout<<"No"<<endl;
   goto read;
  }
 
  if(!(odd%2)) odd--;
  if(odd>=k){
   if(k%2) k=0;
   else k=1;
  }
  else k-=odd;
 
  if(k<=even) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
 }
 
 return 0;
}