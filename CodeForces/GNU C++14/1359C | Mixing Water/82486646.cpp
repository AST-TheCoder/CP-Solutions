#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll tc;
 cin>>tc;
 
 while(tc--){
  ll h,c,t,x,ans=2;
  cin>>h>>c>>t;
 
  if(h+c-2*t) x=(c-t)/(h+c-2*t);
  else x=0;
 
  double diff=abs((double)t-((h+c)/2.0)),chk;
 
  chk=abs((double)t-(x*h+(x-1.0)*c)/(2.0*x-1.0));
  if(chk<diff && x-1>=0){
   ans=2*x-1;
   diff=chk;
  }
  
  chk=abs((double)t-((x+1.0)*h+x*c)/(2.0*x+1.0));
  if(chk<diff && x>0){
   ans=2*x+1;
   diff=chk;
  }
  cout<<ans<<endl;
 }
 
 return 0;
}