#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
ll n,a[200007],t[200007],c[200007],v[200007],cc[200007],sp[200007][18],len[200007][18];
 
int main()
{   
 
 cin>>n;
 for(ll i=1;i<=n;i++) cin>>a[i];
 ll ans=0;
 for(ll i=1;i<=n;i++){
  if(a[i]<=t[i-1]){
   t[i]=a[i];
   v[i]=t[i-1]-t[i]+1;
  }
  else t[i]=t[i-1]+1;
  ans+=t[i];
  c[i]=c[i-1]+t[i];
 }
 for(ll i=1,j=0,s=1;i<=n;i++,s++){
  s=min(s,a[i]);
  if(v[i]){
   j=i;
   s=t[i-1]+1;
   cc[i]=s;
   continue;
  }
  else{
   v[j]-=t[i];
   v[j]+=s;
   cc[i]=cc[i-1]+s;
  }
 }
 
 memset(sp,-1,sizeof(sp));
 for(ll i=0,p=1;i<18;i++,p*=2){
  for(ll j=1;j<=n && j+p-1<=n;j++){
   if(p==1){
    sp[j][i]=a[j];
    len[j][i]=j;
    continue;
   }
   sp[j][i]=min(sp[j][i-1],sp[j+p/2][i-1]);
   len[j][i]=j+p-1;
  }
 }
 
 ll q;
 cin>>q;
 while(q--){
  ll idx,val;
  ll temp=ans;
  cin>>idx>>val;
  if(val<t[idx]){
   ll p=idx+1;
   while(1){
    ll ok=0;
    for(ll i=17;i>=0;i--){
     if(sp[p][i]==-1) continue;
     if(sp[p][i]>=val+len[p][i]-idx){
      ok=1;
      p=len[p][i]+1;
      break;
     }
    }
    if(!ok) break;
   }
   p--;
   temp-=(c[p]-c[idx-1]);
   p=val+p-idx;
   temp+=((val+p)*(p-val+1))/2;
  }
  else if(val>t[idx] && t[idx]<=t[idx-1]){
   temp+=v[idx];
   if(val<=t[idx-1]){
    ll p=idx+1;
    while(1){
     ll ok=0;
     for(ll i=17;i>=0;i--){
      if(sp[p][i]==-1) continue;
      if(sp[p][i]>=val+len[p][i]-idx){
       ok=1;
       p=len[p][i]+1;
       break;
      }
     }
     if(!ok) break;
    }
    p--;
    temp-=cc[p];
    p=val+p-idx;
    temp+=((val+p)*(p-val+1))/2;
   }
  }
  cout<<temp<<endl;
 }
 
 return 0;
}