#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n,m,x,y;
 cin>>n>>m>>x>>y;
 cout<<x<<" "<<y<<endl;
 cout<<1<<" "<<y<<endl;
 for(ll i=1;i<=n;i++){
  for(ll j=1;j<=m && i%2;j++){
   if((i==x && j==y) || (i==1 && j==y)) continue;
   cout<<i<<" "<<j<<endl;
  }
  for(ll j=m;j>=1 && !(i%2);j--){
   if(i==x && j==y) continue;
   cout<<i<<" "<<j<<endl;
  }
 }
 
 return 0;
}