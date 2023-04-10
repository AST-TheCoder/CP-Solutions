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
        ll n,k;
        cin>>n>>k;
 
        pair<ll,ll> a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i+1;
        }
 
        ll ans=0;
        sort(a,a+n);
        for(ll i=0;i<k;i++){
            if(a[i].second>k) ans++;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}