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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        if(n%2){
            if((n/2)%2==0) cout<<n/2-1<<" "<<n/2+1<<" "<<1<<endl;
            else cout<<n/2-2<<" "<<n/2+2<<" "<<1<<endl;
        }
        else cout<<2<<" "<<n-3<<" "<<1<<endl;
    }
 
    return 0;
}