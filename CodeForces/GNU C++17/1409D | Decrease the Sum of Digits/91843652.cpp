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
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,s;
  cin>>n>>s;
 
  for(ll i=1;;i*=10){
   ll x=n/i,p=(i!=1);
   while(x){
    p+=(x%10);
    x/=10;
   }
   if(p<=s){
    cout<<(n/i+(i!=1))*i-n<<endl;
    goto read;
   }
  }
 }
 
 return 0;
}