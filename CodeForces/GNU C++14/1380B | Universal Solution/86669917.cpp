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
  string str;
  cin>>str;
  ll r=0,p=0,s=0;
 
  for(ll i=0;i<str.size();i++){
   if(str[i]=='R') r++;
   if(str[i]=='P') p++;
   if(str[i]=='S') s++;
  }
 
  if(r>=p && r>=s){
   for(ll i=1;i<=str.size();i++) cout<<'P';
   cout<<endl;
  }
  else if(p>=r && p>=s){
   for(ll i=1;i<=str.size();i++) cout<<'S';
   cout<<endl;
  }
  else{
   for(ll i=1;i<=str.size();i++) cout<<'R';
   cout<<endl;
  }
 }
 
    return 0;
}