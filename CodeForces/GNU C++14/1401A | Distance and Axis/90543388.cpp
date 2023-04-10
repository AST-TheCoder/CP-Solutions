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
  ll n,k;
  cin>>n>>k;
 
  if(n<=k) cout<<k-n<<endl;
  else{
   ll x=n-k;
   if(x%2) cout<<1<<endl;
   else cout<<0<<endl;
  }
 }
 
 return 0;
}