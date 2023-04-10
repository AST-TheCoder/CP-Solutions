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
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,k;
        cin>>n>>k;
 
        pair<ll,ll> a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a,a+n);
        ll s=1;
        for(ll i=1;i<n;i++){
            if(a[i].second-1!=a[i-1].second) s++;
        }
        if(s<=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 
    return 0;
}