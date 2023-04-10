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
  ll x,y,z;
  cin>>x>>y>>z;
 
  if(x>=y && x>=z && y>=x && y>=z) cout<<"YES"<<endl<<x<<" "<<z<<" "<<z<<endl;
  else if(y>=x && y>=z && z>=x && z>=y) cout<<"YES"<<endl<<x<<" "<<x<<" "<<z<<endl;
  else if(x>=y && x>=z && z>=x && z>=y) cout<<"YES"<<endl<<y<<" "<<x<<" "<<y<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}