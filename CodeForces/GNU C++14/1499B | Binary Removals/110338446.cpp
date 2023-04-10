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
 
 int t;
 scanf("%lli",&t);
 
 while(t--){
  string s;
  cin>>s;
  ll ok=1;
  for(ll i=1;i<s.size();i++){
   if(s[i]-'0'==ok && s[i-1]-'0'==ok) ok--;
  }
  if(ok==-1) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
 }
 
 
 return 0;
}