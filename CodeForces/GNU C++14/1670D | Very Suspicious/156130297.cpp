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
    ll x[]={0, 0, 0};
    vector<ll> v,lines;
    for(ll i=1,ans=0;;i++){
        sort(x,x+3);
        x[0]++;
        ans+=2*(x[1]+x[2]);
        v.pb(ans);
        lines.pb(i);
        if(ans>1000000000) break;
    }
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll idx=lower_bound(all(v),n)-v.begin();
        cout<<lines[idx]<<endl;
    }
 
    return 0;
}