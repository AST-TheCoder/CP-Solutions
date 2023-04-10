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
 
ll mod=1000000007;
ll bigmod(ll n,ll p){
 if(p==0) return 1LL;
 if(p<0) return 0LL;
 if(p==1) return n%mod;
 if(p%2) return (bigmod(n,p-1)*n)%mod;
 ll x=bigmod(n,p/2);
 return (x*x)%mod;
}
 
int main()
{ 
 
 ll n;
 cin>>n;
 
 string s;
 cin>>s;
 
 ll aq[n],a[n],cq[n],c[n];
 aq[0]=(s[0]=='?');
 a[0]=(s[0]=='a');
 cq[n-1]=(s[n-1]=='?');
 c[n-1]=(s[n-1]=='c');
 
 for(ll i=1;i<n;i++) aq[i]=aq[i-1]+(s[i]=='?');
 for(ll i=1;i<n;i++) a[i]=a[i-1]+(s[i]=='a');
 for(ll i=n-2;i>=0;i--) cq[i]=cq[i+1]+(s[i]=='?');
 for(ll i=n-2;i>=0;i--) c[i]=c[i+1]+(s[i]=='c');
 
 ll ans=0;
 for(ll i=1;i<n-1;i++){
  if(s[i]=='?' || s[i]=='b'){
   ans+=((((bigmod(3LL,aq[i-1]+cq[i+1])*a[i-1])%mod)*c[i+1])%mod);
   ans%=mod;
   ll x=(c[i+1]*aq[i-1])%mod;
   ll y=(a[i-1]*cq[i+1])%mod;
   ans+=((bigmod(3LL,aq[i-1]+cq[i+1]-1)*(x+y))%mod);
   ans%=mod;
   ll z=(bigmod(3LL,cq[i+1]-1)*cq[i+1])%mod;
   ans+=((((bigmod(3LL,aq[i-1]-1)*aq[i-1])%mod)*z)%mod);
   ans%=mod;
  }
 }
 
 cout<<ans<<endl;
 
 return 0;
}