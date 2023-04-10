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
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll prev,p,q;
        vector<ll> ans;
        cout<<"?"<<" "<<1<<" "<<2<<" "<<3<<endl;
        cin>>prev;
 
        for(ll i=2;;i++){
            ll x;
            cout<<"?"<<" "<<i<<" "<<i+1<<" "<<i+2<<endl;
            cin>>x;
 
            if(prev!=x){
                p=i-1,q=i+2;
                if(!prev) ans.pb(i-1);
                else ans.pb(i+2);
                break;
            }
        }
 
        for(ll i=1;i<=n;i++){
            if(i==p || i==q) continue;
            ll x;
            cout<<"?"<<" "<<p<<" "<<q<<" "<<i<<endl;
            cin>>x;
            if(!x) ans.pb(i);
        }
        cout<<"!"<<" "<<ans.size();
        for(ll i=0;i<ans.size();i++) cout<<" "<<ans[i];
        cout<<endl;
    }
 
    return 0;
}