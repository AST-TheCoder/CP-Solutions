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
        ll n,k,ans=0;
        cin>>n>>k;
 
        vector<ll> a,b;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
 
            if(x<0) b.pb(x);
            if(x>0) a.pb(x);
        }
 
        sort(all(a));
        sort(all(b),greater<ll>());
        for(ll i=0;i<a.size();i++){
            ll m=(ll)a.size()%k;
            if((i-m+1)%k==0){
                ans+=a[i];
                if(i+1!=a.size()) ans+=a[i];
            }
        }
        for(ll i=0;i<b.size();i++){
            ll m=(ll)b.size()%k;
            if((i-m+1)%k==0){
                ans+=(-b[i]);
                if(i+1!=b.size()) ans+=(-b[i]);
            }
        }
 
        ll x=0,y=0;
        if(b.size()) x=-b[b.size()-1];
        if(a.size()) y=a[a.size()-1];
 
        ans+=min(x,y);
        cout<<ans<<endl;
    }
 
    return 0;
}