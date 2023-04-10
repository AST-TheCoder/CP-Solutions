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
 scanf("%lli",&t);
 
 while(t--){
  ll a,b;
  scanf("%lli %lli",&a,&b);
  ll x=sqrt(a)+2;
  ll ans=INT_MAX;
  if(b>a){
   printf("1\n");
   continue;
  }
  if(b>x){
   printf("2\n");
   continue;
  }
  ll c=0;
  if(b==1){
   b++;
   c=1;
  }
  for(ll i=b;i<=x;i++){
   ll q=a,ok=i-b;
   while(q){
    q/=i;
    ok++;
   }
   ans=min(ans,ok);
  }
  printf("%lli\n",ans+c);
 }
 
 return 0;
}