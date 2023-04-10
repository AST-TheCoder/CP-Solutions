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
        ll n,l,r,ans=0;
        cin>>n>>l>>r;
        vector<ll> x;
        for(ll i=0;i<n;i++){
            ll p;
            cin>>p;
            x.pb(p);
        }
        sort(all(x));
        //for(ll i=0;i<n;i++) cout<<x[i]<<" ";cout<<endl;
        for(ll i=0;i<n;i++){
            ll p=lower_bound(all(x),l-x[i])-x.begin();
            if(p<=i) p=i+1;
            ll q=upper_bound(all(x),r-x[i])-x.begin();
            if(q<=i) q=i+1;
            //cout<<i<<" "<<p<<" "<<q<<endl;
            ans+=q-p;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}