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
 read:
 while(t--){
  ll n;
  cin>>n;
  ll s=0,p=0,ok=0;
  for(ll i=1;i<=n;i++){
   ll x;
   cin>>x;
   s+=x;
   p+=(i-1);
   if(s<p && !ok){
    cout<<"NO"<<endl;
    ok=1;
   }
  }
  if(ok) continue;
  //cout<<n<<" "<<s<<" "<<(n*(n-1))/2<<endl;
  if(s<(n*(n-1))/2) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
 }
 
 return 0;
}