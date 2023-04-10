#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n;
  cin>>n;
 
  string s;
  ll cnt[26];
  memset(cnt,0,sizeof(cnt));
 
  for(ll i=0;i<n;i++){
   cin>>s;
   for(ll j=0;j<s.size();j++){
    cnt[s[j]-'a']++;
   }
  }
 
  for(ll i=0;i<26;i++){
   if(cnt[i]%n){
    cout<<"NO"<<endl;
    goto read;
   }
  }
 
  cout<<"YES"<<endl;
 }
 
 return 0;
}