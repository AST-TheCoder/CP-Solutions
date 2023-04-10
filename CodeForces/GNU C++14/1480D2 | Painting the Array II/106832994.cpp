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
 
 ll n;
 cin>>n;
 vector<ll> x;
 for(ll i=0;i<n;i++){
  ll p;
  cin>>p;
  if((ll)x.size()==0 || x[(ll)x.size()-1]!=p) x.pb(p);
 }
 
 n=(ll)x.size();
 if(n<=2){
  cout<<n<<endl;
  return 0;
 }
 ll idx[n+1];
 memset(idx,-1,sizeof(idx));
 ll ans=n,a=n-1,b=n-2;
 idx[x[n-2]]=n-2;
 idx[x[n-1]]=n-1;
 
 for(ll i=n-3;i>=0;i--){
  if((idx[x[i]]<(max(a,b)) && idx[x[i]]!=-1) || x[a]==x[i] || x[b]==x[i]){
   ans--;
   a=i;
   b=i+1;
  }
  idx[x[i]]=i;
 }
 
 cout<<ans<<endl;
 
 return 0;
}