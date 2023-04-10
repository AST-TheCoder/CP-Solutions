#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main(){
 ll a,b,c,d,ans=0;
 cin>>a>>b>>c>>d;
 for(ll i=b;i>=a;i--){
  ll x=max(b,min(c,d-i+1)); ll u=min(x+i,d+1)-c;
  ll y=max(b,c-i+1); ll v=min(y+i,d+1)-c;
 
  ll p=(u+v)*((u-v+1)/2)+((u-v+1)%2?(u+v)/2:0);
  ans+=(p+(c-x)*(d-c+1)); 
 }
 cout<<ans<<endl;
 return 0;
}