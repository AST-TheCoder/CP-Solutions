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
 
 string s;
 cin>>s;
 
 for(ll i=2;i<s.size();i++){
  if(s[i]!=(char)((s[i-1]-'A'+s[i-2]-'A'+1)%26)+'A'-1){
   cout<<"NO"<<endl;
   return 0;
  }
 }
 
 cout<<"YES"<<endl;
 
 return 0;
}