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
  ll n,u,r,l,d;
  cin>>n>>u>>r>>d>>l;
 
  ll uu=n,rr=n,dd=n,lll=n;
 
  //cout<<uu<<" "<<lll<<" "<<rr<<" "<<dd<<endl;
  if(u==1){
   if(lll-l>rr-r) lll--;
   else rr--;
  }
  if(u==0){
   lll--;
   rr--;
  }
  //cout<<uu<<" "<<lll<<" "<<rr<<" "<<dd<<endl;
 
  if(d==1){
   if(lll-l>rr-r) lll--;
   else rr--;
  }
  if(d==0){
   lll--;
   rr--;
  }
  //cout<<uu<<" "<<lll<<" "<<rr<<" "<<dd<<endl;
 
  if(l==1){
   if(dd-d>uu-u) dd--;
   else uu--;
  }
  if(l==0){
   dd--;
   uu--;
  }
  //cout<<uu<<" "<<lll<<" "<<rr<<" "<<dd<<endl;
  if(r==1){
   if(dd-d>uu-u) dd--;
   else uu--;
  }
  if(r==0){
   dd--;
   uu--;
  }
  //cout<<uu<<" "<<lll<<" "<<rr<<" "<<dd<<endl;
  if(u<=uu && l<=lll && r<=rr && d<=dd){
   cout<<"YES"<<endl;
  }else cout<<"NO"<<endl;
 
 
 }
 
  
 
 return 0;
}