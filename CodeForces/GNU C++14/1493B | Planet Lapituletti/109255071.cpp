#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main()
{ 
 
 ll t;
 scanf("%lli",&t);
 
 while(t--){
  ll h,m;
  cin>>h>>m;
  string s;
  string x="015--2--8-";
  cin>>s;
  string hh,mm,n;
  ll ch=h-1;
  while(ch){
   hh+=((char)((ch%10)+'0'));
   ch/=10;
  }
  if(hh.size()==1) hh+='0';
  if(hh.size()==0) hh+="00";
  reverse(all(hh));
  ch=m-1;
  while(ch){
   mm+=((char)((ch%10)+'0'));
   ch/=10;
  }
  if(mm.size()==1) mm+='0';
  if(mm.size()==0) mm+="00";
  reverse(all(mm));
  //cout<<hh<<" "<<mm<<endl;
  n=hh+":"+mm;
  //cout<<n<<endl;
 
  ll ok=0;
  while(ok!=1){
   ll ans=0,p=0;
   for(ll i=0;i<s.size();i++){
    if(s[i]==':') continue;
    if(x[s[i]-'0']=='-'){
     p=1;
     break;
    }
   }
 
   for(ll i=s.size()-1;i>=0 && !p;i--){
    if(s[i]==':'){
     if(ans>=h){
      ans=1000;
      break;
     }
     ans=0;
     //cout<<ans<<endl;
     continue;
    }
    ans=ans*10+((ll)x[s[i]-'0']-'0');
   }
   if(p) ans=1000;
   if(ans<m){
    ok=1;
    break;
   }
   for(ll i=s.size()-1;i>=0;i--){
    if(s[i]==':') continue;
    if(i==4 && s[i]==n[i] && s[i-1]==n[i-1]){
     s[i]='0';
     s[i-1]='0';
     i--;
     continue;
    }
    if(i==1 && s[i]==n[i] && s[i-1]==n[i-1]){
     s[i]='0';
     s[i-1]='0';
     i--;
     continue;
    }
    if(s[i]=='9'){
     s[i]='0';
     continue;
    }
    s[i]+=1;
    break;
   }
   //cout<<ans<<" "<<s<<endl;
  }
 
  cout<<s<<endl;
 }
 
 return 0;
}