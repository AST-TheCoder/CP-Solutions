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
 
 while(t--){
  ll x1,y1,z1;
  cin>>x1>>y1>>z1;
  ll x2,y2,z2;
  cin>>x2>>y2>>z2;
 
  if(y1>x2){
   y1-=x2;
   x2=0;
  }
  else{
   x2-=y1;
   y1=0;
  }
  if(y1>y2){
   y1-=y2;
   y2=0;
  }
  else{
   y2-=y1;
   y1=0;
  }
 
  ll ans=-2*y1;
  z2-=y1;
  y1=0;
 
  if(z1>y2){
   ans+=(2*y2);
   z1-=y2;
   y2=0;
  }
  else{
   ans+=(2*z1);
   y2-=z1;
   z1=0;
  }
  cout<<ans<<endl;
 }
 
 return 0;
}