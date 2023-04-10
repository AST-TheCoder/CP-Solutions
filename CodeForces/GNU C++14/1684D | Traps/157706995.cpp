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
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll ans=0,n,k;
        cin>>n>>k;
 
        pair<ll,ll> a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i].second;
 
            a[i].first=a[i].second-(n-i);
            ans+=a[i].second;
        }
        sort(a+1,a+n+1,greater<pair<ll,ll>>());
 
        ll temp=ans;
        for(ll i=1;i<=k;i++){
            temp-=(a[i].first+i-1);
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}