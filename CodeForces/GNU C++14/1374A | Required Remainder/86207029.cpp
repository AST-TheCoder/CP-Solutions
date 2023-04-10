#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll x,y,n;
  cin>>x>>y>>n;
 
  ll k=n-y;
  k-=(k%x);
  k+=y;
  
  cout<<k<<endl;
 }
    return 0;
}