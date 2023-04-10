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
 
 read:
 while(t--){
  ll n,ss=0;
  cin>>n;
  string s;
  cin>>s;
 
  vector<ll> ans;
  for(ll i=0,o=0,z=0;i<n;i++){
   if(s[i]=='1'){
    o++;
    if(z){
     ans.pb(z);
     z--;
    }
    else ans.pb(o);
   }
   else{
    z++;
    if(o) o--;
    ans.pb(z);
   }
   ss=max(ss,max(o,z));
  }
 
  cout<<ss<<endl;
  for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
  cout<<endl;
 }
 
 return 0;
}