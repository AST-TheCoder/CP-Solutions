#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n;
 cin>>n;
 
 ll cnt[100007],c[10];
 memset(cnt,0,sizeof(cnt));
 memset(c,0,sizeof(c));
 
 for(ll i=0;i<n;i++){
  ll x;
  cin>>x;
  cnt[x]++;
  if(cnt[x]<10) c[cnt[x]]++;
 }
 
 ll q;
 cin>>q;
 
 while(q--){
  char ch;
  ll x;
  cin>>ch>>x;
  if(ch=='+'){
   cnt[x]++;
   if(cnt[x]<10) c[cnt[x]]++;
  }
  else{
   if(cnt[x]<10) c[cnt[x]]--;
   cnt[x]--;
  }
 
  if(c[8]) cout<<"YES"<<endl;
  else if(c[4]>=2) cout<<"YES"<<endl;
  else if(c[4]){
   if(c[2]>=3) cout<<"YES"<<endl;
   else if(c[2]>=2 && c[6]) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
  }
  else cout<<"NO"<<endl;
 }
 
 return 0;
}