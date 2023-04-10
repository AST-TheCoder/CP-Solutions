#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
      if(i==n){
        a[n]=n;
        break;
      }
      ll id;
      cout<<"?";
      for(ll j=1;j<n;j++) cout<<" "<<i;
      cout<<" "<<n<<endl;
      cin>>id;
      if(id){
        a[n]=i;
        break;
      }
    }
 
    for(ll i=1;i<=n;i++){
      if(i==a[n]) continue;
      ll id;
      cout<<"?";
      for(ll j=1;j<n;j++) cout<<" "<<n-i+1;
      cout<<" "<<n-a[n]+1<<endl;
      cin>>id;
      a[id]=i;
    }
    cout<<"!";
    for(ll i=1;i<=n;i++) cout<<" "<<a[i];
    cout<<endl;
 
    return 0;
}
/*
3 2 1 5 4
*/