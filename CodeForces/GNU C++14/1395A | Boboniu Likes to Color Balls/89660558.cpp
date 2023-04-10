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
  ll r,g,b,w;
  cin>>r>>g>>b>>w;
  if((r%2)+(g%2)+(b%2)+(w%2)<=1) cout<<"YES"<<endl;
  else if(r && g && b && (r-1)%2+(g-1)%2+(b-1)%2+(w+3)%2<=1) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}