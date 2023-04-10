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
  ll n,m,ans=0;
  cin>>n>>m;
  string s[n];
  for(ll i=0;i<n;i++){
   cin>>s[i];
  }
  for(ll i=0;i<n-1;i++){
   if(s[i][m-1]!='D') ans++;
  }
  for(ll j=0;j<m-1;j++){
   if(s[n-1][j]!='R') ans++;
  }
 
  cout<<ans<<endl;
 }
 
 return 0;
}