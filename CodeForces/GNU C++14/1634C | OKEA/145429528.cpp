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
    cin>>t;
 
    while(t--){
        ll n,k;
        cin>>n>>k;
 
        if(n%2 && k!=1){
            cout<<"NO"<<endl;
            continue;
        }
 
        cout<<"YES"<<endl;
        for(ll i=1;i<=n*k;i+=2*k){
            for(ll j=1;j<=k;j++){
                cout<<i+(j-1)*2<<" ";
            }cout<<endl;
        }
        for(ll i=2;i<=n*k;i+=2*k){
            for(ll j=1;j<=k;j++){
                cout<<i+(j-1)*2<<" ";
            }cout<<endl;
        }
    }
 
    return 0;
}