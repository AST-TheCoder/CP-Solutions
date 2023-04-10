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
  ll n;
  cin>>n;
 
  if(n%2){
   if(n==1) cout<<"FastestFinger"<<endl;
   else cout<<"Ashishgup"<<endl;
  }
  else{
   if(n==2) cout<<"Ashishgup"<<endl;
   else{
    ll c=1;
    while(n%2==0){
     n/=2;
     c*=2;
    }
    if(n==1) cout<<"FastestFinger"<<endl;
    else if(c>=4) cout<<"Ashishgup"<<endl;
    else{
     ll ok=0;
     for(ll i=3;i<=sqrt(n);i+=2){
      if(n%i==0){
       ok=1;
       break;
      }
     }
     if(ok) cout<<"Ashishgup"<<endl;
     else cout<<"FastestFinger"<<endl;
    }
   }
  }
 }
 
    return 0;
}