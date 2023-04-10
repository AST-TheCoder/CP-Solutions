#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
ll count(string s,string pat){
 ll k=0;
 for(ll i=0;i<s.length();i++)
  if(s.substr(i,pat.length())==pat)
   k++;
 return k;
}
 
int main()
{
 ll t;
 cin>>t;
 read:
 while(t--){
  ll n;
  cin>>n;
 
  string s,pat="abacaba";
  cin>>s;
 
  for(ll i=0;i+pat.size()<=n;i++){
   string ss=s;
   ll ok=1;
   for(ll j=0;j<pat.size();j++){
    if(ss[i+j]!='?' && ss[i+j]!=pat[j]){
     ok=0;
     break;
    }
    ss[i+j]=pat[j];
   }
   if(ok && count(ss,pat)==1){
    for(i=0;i<n;i++){
     if(ss[i]=='?') ss[i]='d';
    }
    cout<<"YES"<<endl<<ss<<endl;
    goto read;
   }
  }
  cout<<"NO"<<endl;
 }
 
 return 0;
}