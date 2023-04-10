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
 
    read:
 
    while(t--){
        ll n;
        cin>>n;
        if(n==3){
            cout<<"3 2 1\n1 3 2\n3 1 2"<<endl;
            continue;
        }
 
        for(ll i=1;i<=n;i++){
            for(ll j=i-1;j>=1;j--) cout<<j<<" ";
            for(ll j=n;j>=i;j--) cout<<j<<" ";
            cout<<endl;
        }
    }
 
    return 0;
}