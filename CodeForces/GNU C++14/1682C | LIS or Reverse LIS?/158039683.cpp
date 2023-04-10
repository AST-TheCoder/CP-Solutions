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
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
 
        sort(a,a+n);
        vector<ll> x,y,z;
        for(ll i=0,l=0;i<n;i++){
            if(i>=2 && a[i]==a[i-2]){
                z.pb(a[i]);
                l=-1;
            }
            else x.pb(a[i]);
        }
        cout<<(x.size()+1)/2<<endl;
    }
 
    return 0;
}