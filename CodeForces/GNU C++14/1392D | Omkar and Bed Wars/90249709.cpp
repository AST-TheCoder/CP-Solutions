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
  ll n,ans=0;
  string s;
  cin>>n>>s;
 
  for(ll i=0;i<n;i++){
   if(s[n-1]!=s[0]) break;
   s+=s[0];
   s.erase(s.begin());
  }
  
  ll c=1;
  for(ll i=1;i<n;i++){
   if(s[i]!=s[i-1]) ans+=(c/3),c=1;
   else c++;
  }ans+=(c/3);
  if(c==n) ans+=(c%3!=0);
 
  cout<<ans<<endl;
 }
 
 return 0;
}