#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 cout.flush();
 
 ll n;
 cin>>n;
 ll a[n+3][n+3];
 
 for(ll i=1;i<=n;i++){
  ll p=pow(2LL,i-1LL);
  if(!(i%2)) p=0;
  for(ll j=1;j<=n;j++){
   cout.flush();
   cout<<p<<" ";
   a[i][j]=(p!=0);
   p*=2;
  }
  cout.flush();
  cout<<endl;
  a[i][n+1]=(p!=0);
 }
 
 ll q;
 cin>>q;
 
 while(q--){
  ll k;cin>>k;
  ll x=1,y=1;
  for(ll i=0;i<2*n-1;i++){
   cout.flush();
   cout<<x<<" "<<y<<endl;
   if(k&(1LL<<(i+1LL))){
    if(a[x][y+1]) y++;
    else x++;
   }
   else{
    if(!a[x][y+1]) y++;
    else x++;
   }
  }
 }
 
 return 0;
}