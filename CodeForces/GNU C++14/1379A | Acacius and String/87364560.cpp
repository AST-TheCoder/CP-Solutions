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
 
  string s,pat="abacaba";
  cin>>s;
 
  ll ok=-1;
  for(ll i=0;i<n-6;i++){
   string chk=s.substr(i,7);
   if(chk==pat){
    if(ok==-1) ok=n;
    else{
     cout<<"NO"<<endl;
     goto read;
    }
   }
  }
 
  for(ll i=0;i<n-6 && ok==-1;i++){
   string chk=s.substr(i,7);
   for(ll j=0;j<7;j++){
    if(chk[j]=='?') chk[j]=pat[j];
   }
 
   if(pat==chk){
    if(i>=6){
     string chk=s.substr(i-6,7);
     for(ll j=6;j<7;j++){
      if(chk[j]=='?') chk[j]=pat[j];
     }
     if(pat==chk) continue;
    }
    if(i>=4){
     string chk=s.substr(i-4,7);
     for(ll j=4;j<7;j++){
      if(chk[j]=='?') chk[j]=pat[j];
     }
     if(pat==chk) continue;
    }
    if(i<n-10){
     string chk=s.substr(i+4,7);
     for(ll j=0;j<3;j++){
      if(chk[j]=='?') chk[j]=pat[j];
     }
     if(pat==chk) continue;
    }
    if(i<n-12){
     string chk=s.substr(i+6,7);
     for(ll j=0;j<1;j++){
      if(chk[j]=='?') chk[j]=pat[j];
     }
     if(pat==chk) continue;
    }
    ok=i;
    break;
   }
  }
 
  if(ok==-1){
   cout<<"NO"<<endl;
   goto read;
  }
 
  cout<<"YES"<<endl;
  for(ll i=0;i<n;i++){
   if(s[i]=='?'){
    if(i>=ok && i<=ok+6) s[i]=pat[i-ok];
    else s[i]='z';
   }
  }
 
  cout<<s<<endl;
 }
 
 return 0;
}