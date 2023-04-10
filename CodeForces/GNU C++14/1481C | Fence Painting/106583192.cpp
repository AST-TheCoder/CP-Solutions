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
 
 read:
 while(t--){
  ll n,m;
  scanf("%lli %lli",&n,&m);
 
  ll a[n+1],b[n+1],c[m+1];
  for(ll i=1;i<=n;i++){
   scanf("%lli",&a[i]);
  }for(ll i=1;i<=n;i++){
   scanf("%lli",&b[i]);
  }
  ll cnt[n+1];
  memset(cnt,0,sizeof(cnt));
  for(ll i=1;i<=m;i++){
   scanf("%lli",&c[i]);
   cnt[c[i]]++;
  }
 
  queue<ll> q[n+1];
  ll ok[n+1],pp=-1;
  memset(ok,-1,sizeof(ok));
 
  for(ll i=1;i<=n;i++){
   ok[b[i]]=i;
   if(a[i]!=b[i]){
    q[b[i]].push(i);
   }
  }
 
  for(ll i=1;i<=n;i++){
   if((ll)q[i].size()>cnt[i]){
    printf("NO\n");
    goto read;
   }
  }
 
  ll ans[m+1];
  memset(ans,-1,sizeof(ans));
  if(cnt[c[m]] && ok[c[m]]!=-1){
   if((ll)q[c[m]].size()) pp=q[c[m]].back();
   else pp=ok[c[m]];
   ans[m]=pp;
  }
 
  for(ll i=1;i<=m;i++){
   if(ok[c[i]]==-1){
    if(pp==-1){
     printf("NO\n");
     goto read;
    }
    ans[i]=pp;
   }
  }
  printf("YES\n");
  for(ll i=1;i<=m;i++){
   if(ans[i]!=-1) continue;
   if((ll)q[c[i]].size()){
    ll x=q[c[i]].front();
    q[c[i]].pop();
    ans[i]=x;
   }
   else if(ok[c[i]]!=-1){
    ans[i]=ok[c[i]];
   }
  }
  for(ll i=1;i<=m;i++) printf("%lli ",ans[i]);
  printf("\n");
 }
 
 return 0;
}