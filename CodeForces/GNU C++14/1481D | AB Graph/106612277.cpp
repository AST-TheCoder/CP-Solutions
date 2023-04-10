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
  cin>>n>>m;
  string s[n];
  for(ll i=0;i<n;i++){
   cin>>s[i];
  }
 
  if(n==2 && s[0][1]!=s[1][0] && m%2==0){
   cout<<"NO"<<endl;
   continue;
  }
  cout<<"YES"<<endl;
  for(ll i=0;i<n;i++){
   for(ll j=0;j<n;j++){
    if(i==j) continue;
    if(s[i][j]==s[j][i]){
     for(ll k=0;k<=m;k++){
      if(k%2) cout<<i+1<<" ";
      else cout<<j+1<<" ";
     }cout<<endl;
     goto read;
    }
   }
  }
  if(m%2==1){
   for(ll i=0;i<=m;i++){
    if(i%2) cout<<1<<" ";
    else cout<<2<<" ";
   }cout<<endl;
   goto read;
  }
  for(ll k=0;k<n;k++){
   ll x=count(all(s[k]),'a');
   if(n-x-1 && x){
    if((m/2)%2==0){
     ll p,q=k+1,r;
     for(ll i=0;i<n;i++){
      if(s[k][i]=='a') p=i+1;
      else if(s[k][i]=='b') r=i+1;
     }
     cout<<q<<" ";
     for(ll i=1;i<=m/2;i++){
      if(i%2) cout<<p<<" ";
      else cout<<q<<" ";
     }for(ll i=1;i<=m/2;i++){
      if(i%2) cout<<r<<" ";
      else cout<<q<<" ";
     }cout<<endl;
     //cout<<(m/2)%2<<endl;
     goto read;
    }
    else{
     ll p=k+1,q,r;
     for(ll i=0;i<n;i++){
      if(s[k][i]=='a') q=i+1;
      else if(s[k][i]=='b') r=i+1;
     }
     cout<<q<<" ";
     for(ll i=1;i<=m/2;i++){
      if(i%2) cout<<p<<" ";
      else cout<<q<<" ";
     }for(ll i=1;i<=m/2;i++){
      if(i%2) cout<<r<<" ";
      else cout<<p<<" ";
     }cout<<endl;
     goto read;
    }
   }
  }
 }
 
 return 0;
}