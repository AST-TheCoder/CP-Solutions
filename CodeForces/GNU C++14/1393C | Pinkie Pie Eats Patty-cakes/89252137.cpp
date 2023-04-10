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
  ll n;
  cin>>n;
 
  ll a[n+1];
  ll c[n+1],x[n+1];
  memset(c,0,sizeof(c));
  memset(x,0,sizeof(x));
 
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   c[a[i]]++;
   x[c[a[i]]]++;
  }
 
  for(ll i=n;i>=0;i--){
   if(x[i]){
    cout<<(n-x[i])/(i-1)-1<<endl;
    break;
   }
  }
 }
 
 return 0;
}