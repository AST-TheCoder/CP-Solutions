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
 
ll dv[1000007];
 
int main()
{   
    
    
    ll n;
    cin>>n;
 
    for(ll i=1;i<=n;i++){
     for(ll j=i;j<=n;j+=i){
      dv[j]++;
     }
    }
 
    ll s[n+1],d[n+1];
    s[1]=d[1]=1;
    for(ll i=2;i<=n;i++){
     d[i]=s[i-1]+dv[i];
     d[i]%=998244353;
     s[i]=s[i-1]+d[i];
     s[i]%=998244353;
    }
 
    cout<<d[n]<<endl;
 
    return 0;
}