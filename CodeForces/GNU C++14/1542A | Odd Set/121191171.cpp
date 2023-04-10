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
        ll n;
        cin>>n;
        ll o=0,e=0;
        for(ll i=0;i<2*n;i++){
            ll x;
            cin>>x;
            if(x%2) o++;
            else e++;
        }
 
        if(o==e) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
 
    return 0;
}