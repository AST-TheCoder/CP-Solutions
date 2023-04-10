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
  string s;
  cin>>s;
  ll x;
  cin>>x;
  string w(s.size(),'0');
 
  for(ll i=0;i<s.size();i++){
   if(s[i]=='1'){
    if(i-x>=0 && (i-2*x<0 || s[i-2*x]=='1')) w[i-x]='1';
    else if(i+x<s.size() && (i+2*x>=s.size() || s[i+2*x]=='1')) w[i+x]='1';
    else{
     cout<<-1<<endl;
     goto read;
    }
   }
  }
  cout<<w<<endl;
 }
 
 return 0;
}