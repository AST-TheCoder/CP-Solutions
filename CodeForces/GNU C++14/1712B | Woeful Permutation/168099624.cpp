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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
ll node[3000000];
 
int main()
{   
    
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll ans[n+1];
        for(ll i=1;i<=n;i++) ans[i]=i;
        for(ll i=n;i>=2;i-=2){
            swap(ans[i],ans[i-1]);
        }
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}