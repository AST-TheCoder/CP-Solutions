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
  ll n;
  cin>>n;
  string a,b;
  vector<ll> ans;
  cin>>a>>b;
 
  for(ll i=1;i<n;i++){
   if(a[i]!=a[i-1]){
    ans.pb(i);
    if(a[0]=='0') a[0]='1';
    else a[0]='0';
   }
  }
 
  for(ll i=n-1;i>=0;i--){
   if(b[i]!=a[0]){
    ans.pb(i+1);
    if(a[0]=='0') a[0]='1';
    else a[0]='0';
   } 
  }
  cout<<ans.size();
  for(ll i=0;i<ans.size();i++) cout<<" "<<ans[i];
  cout<<endl;
 }
 
 return 0;
}