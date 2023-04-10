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
  string s;
  cin>>s;
 
  ll cnt[200],chk[200];
  priority_queue<pair<char,ll>> x;
  ll id=-1;
  memset(cnt,0,sizeof(cnt));
  memset(chk,0,sizeof(chk));
 
  for(ll i=0;i<s.size();i++) cnt[s[i]]++;
 
  ll i,j;
  for(i=0,j=0;i<s.size();i=j+1,j++){
   while(j<s.size() && (cnt[s[j]]>1 || chk[s[j]])){
    cnt[s[j]]--;
    j++;
   }
   if(j>=s.size()){
    break;
   }
 
   //chk[s[j]]=1;
 
   for(ll k=j;k>=i;k--){
    if(chk[s[k]]){
     s[k]='-';
     continue;
    }
    x.push({s[k],-k});
    //cout<<k<<" "<<s[k]<<" "<<id[s[k]-'a']<<endl;
   }
   char p=s[j];
   while(!x.empty()){
    pair<char,ll> c=x.top();
    c.second*=-1;
    //cout<<c.first<<" "<<c.second<<endl;
    x.pop();
    if(chk[c.first]) s[c.second]='-';
    else if(c.second>id && c.first>=p){
     id=c.second;
     chk[c.first]=1;
    }
    else if(c.first<p){
     x.push({c.first,-c.second});
     break;
    }
    else s[c.second]='-';
   }
  }
  while(!x.empty()){
   pair<char,ll> c=x.top();
   c.second*=-1;
   //cout<<c.first<<" "<<c.second<<endl;
   x.pop();
   s[c.second]='-';
  }
 
  for(ll k=j-1;k>=i;k--){
   if(chk[s[k]]){
    s[k]='-';
    continue;
   }
  }
 
  for(ll i=0;i<s.size();i++) if(s[i]!='-') cout<<s[i];cout<<endl;
 
 }
 return 0;
}