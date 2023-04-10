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
 
ll v[300001];
int main()
{   
 
    ll t;
    cin>>t;
 
    for(ll i=1;i<=300000;i++) v[i]=v[i-1]^i;
 
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll x=v[a-1];
        if(x==b){
            cout<<a<<endl;
            continue;
        }
        ll y=b^x;
        if(y==a) cout<<a+2<<endl;
        else cout<<a+1<<endl;
    }
 
    return 0;
}