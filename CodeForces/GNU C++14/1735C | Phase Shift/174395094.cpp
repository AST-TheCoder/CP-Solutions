#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n;
  cin>>n;
 
  string s;
  cin>>s;
 
  char x='a';
  ll p[26],q[26];
  memset(p,0,sizeof(p));
  memset(q,0,sizeof(q));
 
  for(ll i=0;i<n;i++){
   if(p[s[i]-'a']) continue;
   set<ll> v;
   for(ll j=0;j<26;j++){
    if(!q[j] && s[i]-'a'!=j) v.insert(j+'a');
   }
   if(!v.size()) break;
   char temp=s[i];
   while(q[temp-'a']!=0) temp=q[temp-'a'];
   if(v.size()>1) v.erase((ll)temp);
   p[s[i]-'a']=*v.begin();
   q[*v.begin()-'a']=s[i];
  }
 
  for(ll i=0;i<n;i++) s[i]=p[s[i]-'a'];
  cout<<s<<endl;
 }
 
 
 return 0;
}