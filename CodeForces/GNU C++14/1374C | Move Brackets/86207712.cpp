#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll n,cnt=0;
  string s;
  cin>>n>>s;
 
  for(ll i=0;i<n;i++){
   if(s[i]==')' && cnt) cnt--;
   if(s[i]=='(') cnt++;
  }
 
  cout<<cnt<<endl;
 }
    return 0;
}