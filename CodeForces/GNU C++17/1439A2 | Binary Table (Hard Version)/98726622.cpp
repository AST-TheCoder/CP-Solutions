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
 cin>>t;
 while(t--){
  ll n,m,k=0,tr=0;
  cin>>n>>m;
  string s[max(n,m)];
  vector<ll> ans;
  for(ll i=0;i<n;i++) cin>>s[i];
  if(n<m){
   tr=1;
   string t[m];
   for(ll j=0;j<m;j++){
    for(ll i=0;i<n;i++){
     t[j]+=s[i][j];
    }
   }
   for(ll i=0;i<m;i++) s[i]=t[i];
   swap(n,m);
  }
  //for(ll i=0;i<n;i++) cout<<s[i]<<endl;
  for(ll i=0;i<n-1;i++){
   for(ll j=0;j<m;j++){
    if(j+1!=m && s[i][j]=='1' && s[i][j+1]=='1'){
     k++;
     s[i][j]='0';
     s[i][j+1]='0';
     ans.pb(i);
     ans.pb(j);
     ans.pb(i);
     ans.pb(j+1);
     if(s[i+1][j+1]=='1'){
      ans.pb(i+1);
      ans.pb(j+1);
      s[i+1][j+1]='0';
     }
     else{
      if(s[i+1][j]=='0') s[i+1][j]='1';
      else s[i+1][j]='0';
      ans.pb(i+1);
      ans.pb(j);
     }
    }
    else if(s[i][j]=='1'){
     k++;
     ans.pb(i);
     ans.pb(j);
     s[i][j]='0';
     if(s[i+1][j]=='0') s[i+1][j]='1';
     else s[i+1][j]='0';
     ans.pb(i+1);
     ans.pb(j);
     if(j+1==m){
      if(s[i+1][j-1]=='0') s[i+1][j-1]='1';
      else s[i+1][j-1]='0';
      ans.pb(i+1);
      ans.pb(j-1);
     }
     else{
      if(s[i+1][j+1]=='0') s[i+1][j+1]='1';
      else s[i+1][j+1]='0';
      ans.pb(i+1);
      ans.pb(j+1);
     }
    }
   }
  }
  for(ll j=0,i=n-1;j<m;j++){
   if(s[i][j]=='1'){
    if(j+2==m && s[i][j+1]=='0'){
     k+=3;
     s[i][j]='0';
     ans.pb(i);
     ans.pb(j);
     ans.pb(i-1);
     ans.pb(j);
     ans.pb(i-1);
     ans.pb(j+1);
     ans.pb(i);
     ans.pb(j);
     ans.pb(i);
     ans.pb(j+1);
     ans.pb(i-1);
     ans.pb(j+1);
     ans.pb(i-1);
     ans.pb(j);
     ans.pb(i);
     ans.pb(j);
     ans.pb(i);
     ans.pb(j+1);
    }
    else if(j+1==m){
     k+=3;
     ans.pb(i);
     ans.pb(j);
     ans.pb(i-1);
     ans.pb(j);
     ans.pb(i-1);
     ans.pb(j-1);
     ans.pb(i);
     ans.pb(j);
     ans.pb(i);
     ans.pb(j-1);
     ans.pb(i-1);
     ans.pb(j-1);
     ans.pb(i);
     ans.pb(j-1);
     ans.pb(i);
     ans.pb(j);
     ans.pb(i-1);
     ans.pb(j);
     s[i][j]='0';
    }
    else{
     k+=2;
     ans.pb(i);
     ans.pb(j);
     ans.pb(i-1);
     ans.pb(j);
     ans.pb(i-1);
     ans.pb(j+1);
     ans.pb(i);
     ans.pb(j+1);
     ans.pb(i-1);
     ans.pb(j+1);
     ans.pb(i-1);
     ans.pb(j);
     s[i][j]='0';
     if(s[i][j+1]=='0') s[i][j+1]='1';
     else s[i][j+1]='0';
    }
   }
  }
  cout<<k<<endl;
  for(ll i=0;i<ans.size();i+=2){
   for(ll j=1;j<=3;j++,i+=2){
    if(!tr) cout<<ans[i]+1<<" "<<ans[i+1]+1<<" ";
    else cout<<ans[i+1]+1<<" "<<ans[i]+1<<" ";
   }cout<<endl;
   i-=2;
  }
 }
 
 return 0;
}