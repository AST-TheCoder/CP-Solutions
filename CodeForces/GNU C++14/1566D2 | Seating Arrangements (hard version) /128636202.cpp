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
        ll n,m;
        cin>>n>>m;
        ll a[n*m+1];
        ll ans=0;
        pair<ll,ll> p[n*m+1],q[n*m+1];
        for(ll i=1;i<=n*m;i++){
            cin>>a[i];
            p[i]={a[i],i};
        }
        sort(p+1,p+(n*m+1));
        for(ll i=1,r=1;i<=n*m;i+=m,r++){
            for(ll j=i+m-1;j>=i;j--) p[j].second*=-1;
            sort(p+i,p+(i+m));
            for(ll j=i+m-1,c=m;j>=i;j--,c--){
                q[-p[j].second]={r,c};
            }
        }
        ordered_set<ll> s[n+1];
        for(ll i=1;i<=n*m;i++){
            s[q[i].first].insert(q[i].second);
            ans+=s[q[i].first].order_of_key(q[i].second);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}