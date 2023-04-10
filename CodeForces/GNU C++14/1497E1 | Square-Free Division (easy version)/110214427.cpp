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
 
#define range 10000007
ll status[(ll)(range/64+5)];
ll Check(ll n,ll i){return (n&(1LL<<i));}
ll Set(ll n,ll i){return (n|(1LL<<i));}
vector<ll> primes;void sieve(){for(ll i=3;i<=sqrt(range);i+=2){if(Check(status[i/64],i%64)==0){for(ll j=i*i;j<range;j+=2*i){status[j/64]=Set(status[j/64],j%64);}}}primes.pb(2);for(ll i=3;i<range;i+=2)if(Check(status[i/64],i%64)==0)primes.pb(i);}
 
int main()
{ 
 
 sieve();
 
 ll t;
 scanf("%lli",&t);
 
 while(t--){
  ll n,k;
  cin>>n>>k;
  ll a[n];
  for(ll i=0;i<n;i++){
   cin>>a[i];
   ll x=a[i],p=1;
   for(ll j=0;j<primes.size() && primes[j]*primes[j]<=x;j++){
    ll k=0;
    while(x%primes[j]==0){
     k++;
     x/=primes[j];
    }
    if(k%2) p*=primes[j];
   }
   if(x-1) p*=x;
   a[i]=p;
  }
  //for(ll i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
  ll ans=1;
  set<ll> x;
  x.insert(a[0]);
  for(ll i=1;i<n;i++){
   ll s=x.size();
   x.insert(a[i]);
   if(x.size()==s){
    x.clear();
    ans++;
    x.insert(a[i]);
   }
  }
  cout<<ans<<endl;
 }
 
 
 return 0;
}