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
 
 ll n,m;
 cin>>n>>m;
 
 string s[n];
 for(ll i=0;i<n;i++) cin>>s[i];
 
 ll ans=(s[0][0]=='*');
 ll i=0,j=0;
 while(i+1!=n || j+1!=m){
  if(j+1<m && s[i][j+1]=='*') ans++,j++;
  else if(i+1<n && s[i+1][j]=='*') ans++,i++;
  else if(j+1<m) j++;
  else i++;
  //cout<<i<<" "<<j<<" "<<ans<<endl;
 }
 
 cout<<ans<<endl;
 
 return 0;
}