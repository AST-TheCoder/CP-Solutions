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
 
    read:
    while(t--){
        ll n,x;
        cin>>n>>x;
        pair<ll,ll> a[n],b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
            b[i].first=a[i].first;
        }
        sort(a,a+n);
        for(ll i=n-x;i<x;i++){
            if(a[i].first!=b[i].first){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}