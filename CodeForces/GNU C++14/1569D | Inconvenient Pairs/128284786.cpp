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
 
ll s[1000007];
 
int main()
{
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
        
        ll n,m,k;
        cin>>n>>m>>k;
 
        ll x[n],y[m];
        pair<ll,ll> p[k];
        for(ll i=0;i<n;i++) cin>>x[i];
        for(ll i=0;i<m;i++) cin>>y[i];
 
        for(ll i=0;i<k;i++) cin>>p[i].first>>p[i].second;
 
        sort(p,p+k);
        ll ans=0;
 
        for(ll i=1,l=0,r=0;i<n;i++){
            while(p[l].first<=x[i-1]) l++;
            for(r=l;p[r].first<x[i];r++){
                ans+=(r-l)-s[p[r].second];
                s[p[r].second]++;
            }
            for(r=l;p[r].first<x[i];r++) s[p[r].second]=0;
        }
        for(ll i=0;i<k;i++) swap(p[i].first,p[i].second);
 
        sort(p,p+k);
        for(ll i=1,l=0,r=0;i<m;i++){
            while(p[l].first<=y[i-1]) l++;
            for(r=l;p[r].first<y[i];r++){
                ans+=(r-l)-s[p[r].second];
                s[p[r].second]++;
            }
            for(r=l;p[r].first<y[i];r++) s[p[r].second]=0;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}