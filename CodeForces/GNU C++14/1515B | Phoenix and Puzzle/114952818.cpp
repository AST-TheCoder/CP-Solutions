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
  ll n;
  cin>>n;
 
  ll x=sqrt(n),y=sqrt(2*n);
  if(n%2==0 && (x*x==n || y*y==2*n)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 
    return 0;
}