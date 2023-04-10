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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,k,o=0,q=0,z=0;
  cin>>n>>k;
  string s;
  cin>>s;
 
  bool x[n];
  memset(x,0,sizeof(x));
 
  for(ll i=0;i<n;i++){
   if(s[i]!='?' && !x[i]){
    for(ll j=i%k;j<n;j+=k){
     if(s[j]!='?' && s[j]!=s[i]){
      cout<<"NO"<<endl;
      goto read;
     }
     s[j]=s[i];
     x[j]=true;
    }
   }
  }
 
  for(ll i=0;i<k;i++){
   if(s[i]=='1') o++;
   else if(s[i]=='?') q++;
   else z++;
  }
 
  if((k/2-o)+(k/2-z)==q && k/2>=o && k/2>=z) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}