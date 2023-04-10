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
 
 ll a,b,k;
 cin>>a>>b>>k;
 
 if(k==0){
  cout<<"Yes"<<endl;
  for(ll i=1;i<=b;i++) cout<<1;
  for(ll i=1;i<=a;i++) cout<<0;cout<<endl;
  for(ll i=1;i<=b;i++) cout<<1;
  for(ll i=1;i<=a;i++) cout<<0;cout<<endl;
  return 0;   
 }
 
 if(k>a+b-2 || !a || b<2){
  cout<<"No"<<endl;
  return 0;
 }
 
 cout<<"Yes"<<endl;
 
 ll x[1+b+a],y[1+b+a],s[1+b+a];
 
 memset(x,0,sizeof(x));
 memset(y,0,sizeof(y));
 memset(s,0,sizeof(s));
 
 y[a+b]=1;
 for(ll i=b-1;i>=1;i--) y[i]=1;
 
 for(ll i=b-1;i>=1 && k;i--,k--) s[i]=1;
 
 ll j=b;
 while(k){
  s[j]=1;
  j++;
  k--;
 }
 
 ll ok=1;
 
 for(ll i=1;i<=a+b;i++){
  if(y[i]==1 && s[i]==0){
   x[i]=1;
   continue;
  }
  if(y[i]==1 && s[i]==1){
   if(ok){
    x[i]=0;
    ok=0;
   }
   else x[i]=1;
  }
  else if(s[i]==1) x[i]=0;
  else if(s[i-1]==1) x[i]=1;
  else x[i]=0;
 }
 
 for(ll i=a+b;i>=1;i--) cout<<x[i];cout<<endl;
 for(ll i=a+b;i>=1;i--) cout<<y[i];cout<<endl;
 
 return 0;
}