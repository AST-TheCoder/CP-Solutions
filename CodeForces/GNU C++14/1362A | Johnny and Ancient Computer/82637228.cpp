#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll a,b,ans=0;
  cin>>a>>b;
  if(a>b) swap(a,b);
 
  while(a<b){
   if(a*8<=b) a*=8;
   else if(a*4<=b) a*=4;
   else if(a*2<=b) a*=2;
   else break;
   ans++;
  }
  if(a!=b) cout<<-1<<endl;
  else cout<<ans<<endl;
 }
 
 return 0;
}