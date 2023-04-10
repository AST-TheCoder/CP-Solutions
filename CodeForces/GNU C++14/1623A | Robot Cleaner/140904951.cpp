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
        ll x,y,a,b,u,v;
        cin>>x>>y>>a>>b>>u>>v;
        ll r,c;
        if(u>=a) r=u-a;
        else r=x-a+x-u;
 
        if(v>=b) c=v-b;
        else c=y-b+y-v;
        cout<<min(r,c)<<endl;
    }
 
    return 0;
}