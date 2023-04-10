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
 
ll a[200007],node[800007];
void build(ll n,ll l,ll r){
 if(l==r){
  node[n]=a[l];
  return;
 }
 build(n*2,l,(l+r)/2);
 build(n*2+1,(l+r)/2+1,r);
 node[n]=max(node[2*n],node[2*n+1]);
}
 
ll query(ll n,ll l,ll r,ll i,ll j){
 if(i>r || j<l) return 0;
 if(l>=i && r<=j) return node[n];
 return max(query(2*n,l,(l+r)/2,i,j),query(2*n+1,(l+r)/2+1,r,i,j));
}
 
int main()
{
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,k,ans=0;
  cin>>n>>k;
  ll x[n+1],y[n+1];
  for(ll i=1;i<=n;i++) cin>>x[i];
  for(ll i=1;i<=n;i++) cin>>y[i];
 
  for(ll i=1;i<=4*n;i++) node[i]=0;
 
  sort(x+1,x+n+1);
  for(ll i=1;i<=n;i++){
   //cout<<x[i]<<" ";
   ll c=upper_bound(x+1,x+n+1,x[i]+k)-x;
   a[i]=c-i;
   //cout<<a[i]<<" ";
  }//cout<<endl;
 
  build(1,1,n);
  for(ll i=1;i<=n;i++){
   ll c1=upper_bound(x+1,x+n+1,x[i]+k)-x;
   ll c2=lower_bound(x+1,x+n+1,x[i]-k)-x;
   c2--;
   ll p=0,q=0;
   if(c2>0) p=query(1,1,n,1,c2);
   if(c1<=n) q=query(1,1,n,c1,n);
   //cout<<i<<" "<<c1<<" "<<c2<<" "<<p<<" "<<q<<" "<<a[i]<<endl;
   ans=max(ans,a[i]+max(p,q));
  }
  cout<<ans<<endl;
 }
 
 return 0;
}