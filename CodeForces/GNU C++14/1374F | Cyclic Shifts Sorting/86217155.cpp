#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
ll a[507],n,c[507];
vector<ll> ans,x;
 
void loop(ll l)
{
 ll temp=c[l+2];
 c[l+2]=c[l+1];
 c[l+1]=c[l];
 c[l]=temp;
}
 
void shift(ll plc,ll des)
{
 if(plc>=des){
  while(plc-2>=des){
   plc-=2;
   ans.pb(plc);
   loop(plc);
  }
  if(plc==des) return;
  ans.pb(plc-1);ans.pb(plc-1);
  loop(plc-1);loop(plc-1);
  return;
 }
 while(plc+2<=des){
  ans.pb(plc);
  loop(plc);
  plc++;
 }
 if(plc==des) return;
 ans.pb(plc-1);
 loop(plc-1);
}
 
void left(ll r)
{
 for(ll i=1;i<=r;i++){
  ll id;
  for(ll j=i;j<=n;j++){
   if(x[i]==c[j]){
    id=j;
    break;
   }
  }
  shift(id,i);
 }
}
 
void right(ll l)
{
 for(ll i=n;i>=l;i--){
  ll id;
  for(ll j=l-3;j<=i;j++){
   if(x[i]==c[j]){
    id=j;
    break;
   }
  }
  shift(id,i);
 }
}
 
int main()
{
 
 ll t;
 cin>>t;
 
 while(t--){
  x.clear();
  cin>>n;
 
  x.pb(-1LL);
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   x.pb(a[i]);
   c[i]=0;
  }
 
  sort(all(x));
 
  ll l=-1;
  for(ll i=1;i<=n-2;i++){
   ans.clear();
   for(ll j=1;j<=n;j++){
    c[j]=a[j];
   }
   left(i-1);
   right(i+3);
   for(ll j=1;j<=3;j++){
    if(x[i]==c[i] && x[i+1]==c[i+1] && x[i+2]==c[i+2]){
     l=i;break;
    }
    loop(i);
    ans.pb(i);
   }
   if(l!=-1) break;
  }
 
  if(l==-1){
   cout<<-1<<endl;
   continue;
  }
 
  cout<<ans.size()<<endl;
  for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
  cout<<endl;
 
 }
 
    return 0;
}