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
 
 ll n,k,ans=0;
 cin>>n>>k;
 
 vector<ll> v[n];
 for(ll i=0;i<n;i++){
  for(ll j=0;j<k;j++){
   ll x;
   cin>>x;
   v[i].pb(x);
  }
 }
 
 sort(v,v+n);
 string s[n];
 for(ll i=0;i<n;i++){
  for(ll j=0;j<k;j++){
   s[i]+=(char)(v[i][j]+'0');
  }
 }
 ll cnt[n];
 memset(cnt,0,sizeof(cnt));
 
 for(ll i=0;i<n;i++){
  for(ll j=0;j<n;j++){
   if(i==j || s[i]>s[j]) continue;
   string temp;
   for(ll l=0;l<k;l++){
    if(s[i][l]==s[j][l]) temp+=s[i][l];
    else{
     if(s[i][l]!='0' && s[j][l]!='0') temp+='0';
     else if(s[i][l]!='1' && s[j][l]!='1') temp+='1';
     else temp+='2';
    }
   }
   if(temp<=s[j] || temp<=s[i]) continue;
   ll id=lower_bound(s,s+n,temp)-s;
   if(id>=n || s[id]!=temp) continue;
   cnt[i]++;
   cnt[j]++;
   cnt[id]++; 
  }
  //cout<<s[i]<<" "<<cnt[i]<<endl;
  ans+=(cnt[i]-1)*cnt[i];
 }
 cout<<ans/2<<endl;
 
 
 return 0;
}