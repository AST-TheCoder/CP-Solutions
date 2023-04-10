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
 
ll n;
ll q1(ll i,ll j){
 ll x;
 cout<<"?"<<" "<<1<<" "<<i<<" "<<j<<" "<<n-1<<endl;
 cin>>x;
 if(x==n-1){
  cout<<"?"<<" "<<1<<" "<<j<<" "<<i<<" "<<n-1<<endl;
  cin>>x;
 }
 return x;
}
 
ll q2(ll i,ll j){
 ll x;
 cout<<"?"<<" "<<2<<" "<<i<<" "<<j<<" "<<1<<endl;
 cin>>x;
 return x;
}
 
 
int main()
{   
 
 ll t;
 cin>>t;
 
 while(t--){
  cin>>n;
  ll a,b;
  cout<<"?"<<" "<<1<<" "<<1<<" "<<2<<" "<<n-1<<endl;
  cin>>a;
  cout<<"?"<<" "<<1<<" "<<2<<" "<<1<<" "<<n-1<<endl;
  cin>>b;
 
  ll mx=max(a,b);
  cout<<"?"<<" "<<2<<" "<<1<<" "<<2<<" "<<1<<endl;
  cin>>a;
  cout<<"?"<<" "<<2<<" "<<2<<" "<<1<<" "<<1<<endl;
  cin>>b;
 
  ll mn=min(a,b);
 
  cout<<"?"<<" "<<1<<" "<<1<<" "<<3<<" "<<n-1<<endl;
  cin>>a;
  cout<<"?"<<" "<<1<<" "<<3<<" "<<1<<" "<<n-1<<endl;
  cin>>b;
 
  ll mxx=max(a,b);
  cout<<"?"<<" "<<2<<" "<<1<<" "<<3<<" "<<1<<endl;
  cin>>a;
  cout<<"?"<<" "<<2<<" "<<3<<" "<<1<<" "<<1<<endl;
  cin>>b;
 
  ll mnn=min(a,b);
 
  ll ans[n+1];
  if(mxx==mx || mnn==mx) ans[1]=mx;
  else ans[1]=mn;
  for(ll i=2;i<=n;i++){
   if(ans[1]<=n/2){
    ll x=q1(i,1);
    if(x==ans[1])
     x=q2(i,1);
    ans[i]=x;
   }
   else{
    ll x=q2(i,1);
    if(x==ans[1])
     x=q1(i,1);
    ans[i]=x;
   }
  }
  cout<<"! ";
  for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
  cout<<endl;
 }
 
    return 0;
}