#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll n,m,k;
  cin>>n>>m>>k;
  ll p=n/k;
  if(p>=m) cout<<m<<endl;
  else{
   m-=p;
   ll q=(m/(k-1))+(m%(k-1)!=0);
   cout<<p-q<<endl;
  }
 }
 
 return 0;
}