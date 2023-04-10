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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 cout.flush();
 ll n;
 cin>>n;
 
 ll a[n+1];
 memset(a,-1,sizeof(a));
 
 for(ll i=1,j=2;i<=n && j<=n;){
  ll x,y;
  cout<<"? "<<i<<" "<<j<<endl;
  cin>>x;
  cout<<"? "<<j<<" "<<i<<endl;
  cin>>y;
 
  if(x>y){
   a[i]=x;
   while(i<=n && (a[i]!=-1 || i==j)) i++;
  }
  else{
   a[j]=y;
   while(j<=n && (a[j]!=-1 || i==j)) j++;
  }
 }
 
 cout<<"! ";
 for(ll i=1;i<=n;i++){
  if(a[i]==-1){
   cout<<n<<" ";
   continue;
  }
  cout<<a[i]<<" ";
 }cout<<endl;
 
 return 0;
}