#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll tc;
 cin>>tc;
 
 while(tc--){
  ll h,c,t;
  cin>>h>>c>>t;
  ll x;
  if(h+c-2*t) x=(c-t)/(h+c-2*t);
  else x=0;
  ll ans=2;
  double diff=abs((double)t-(((double)h+(double)c)/2.0));
  double chk;
  chk=abs((double)t-((double)x*h+(x-1.0)*c)/(2.0*x-1.0));
  if(chk<diff && x-1>=0){
   ans=2*x-1;
   diff=chk;
  }
  chk=abs((double)t-((double)(x+1.0)*h+x*c)/(2.0*x+1.0));
  if(chk<diff && x>0){
   ans=2*x+1;
   diff=chk;
  }
  cout<<ans<<endl;
 }
 
 return 0;
}