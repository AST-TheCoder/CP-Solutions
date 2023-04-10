#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 ll t;
 cin>>t;
 read:
 while(t--){
  ll n;
  cin>>n;
 
  ll id[n+1],a[n+1];
  memset(id,0,sizeof(id));
  set<ll> m;
  vector<ll> ans;
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   id[a[i]]++;
  }
  for(ll i=0;i<=n;i++){
   if(!id[i]) m.insert(i);
  }
 
  ll mx=n;
  while(1){
   ll mex=*m.begin();
   m.erase(m.begin());
   id[mex]++;
   if(mex!=mx){
    id[a[mex+1]]--;
    if(!id[a[mex+1]]) m.insert(a[mex+1]);
    a[mex+1]=mex;
    ans.pb(mex+1);
   }
   else{
    if(!mex) break;
    mx--;
    id[a[mex]]--;
    if(!id[a[mex]]) m.insert(a[mex]);
    a[mex]=mex;
    ans.pb(mex);
   }
   if(!mx) break;
  }
 
  cout<<ans.size()<<endl;
  for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;
 }
 
    return 0;
}