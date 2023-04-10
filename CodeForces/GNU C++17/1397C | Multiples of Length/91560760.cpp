#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{
 
 ll n;
 cin>>n;
 
 ll a[n];
 for(ll i=0;i<n;i++) cin>>a[i];
 
 cout<<1<<" "<<1<<endl;
 cout<<n-a[0]<<endl;
 a[0]+=(n-a[0]);
 if(!(n-1)){
  cout<<1<<" "<<1<<endl;
  cout<<0<<endl;
 }
 else{
  cout<<2<<" "<<n<<endl;
  for(ll i=1;i<n;i++){
   cout<<(n-1)*a[i]<<" ";
   a[i]+=((n-1)*a[i]);
  }
  cout<<endl;
 }
 
 cout<<1<<" "<<n<<endl;
 for(ll i=0;i<n;i++) cout<<-a[i]<<" ";cout<<endl;
 
 return 0;
}