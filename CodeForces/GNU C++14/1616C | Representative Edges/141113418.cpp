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
 
        ll a[n],ans=n;
        for(ll i=0;i<n;i++) cin>>a[i];
 
        for(ll i=0;i<n;i++){
            vector<double> x;
            for(ll j=i+1;j<n;j++){
                double temp=(double)(a[i]-a[j])/(double)(j-i);
                x.pb(temp);
            }
            sort(all(x));
            ll c=1;
            for(ll i=1;i<x.size();i++){
                if(x[i]==x[i-1]) c++;
                else{
                    ans=min(ans,n-c-1);
                    c=1;
                }
            }
            if(n>1) ans=min(ans,n-c-1);
            else ans=0;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}