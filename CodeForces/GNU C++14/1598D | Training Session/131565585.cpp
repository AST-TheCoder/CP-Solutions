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
    read:
    while(t--){
        ll n;
        cin>>n;
        ll a[n+1],b[n+1];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
 
        vector<ll> v[n+1];
        set<ll> s;
        for(ll i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            a[x]++;
            b[y]++;
            v[x].pb(y);
            s.insert(x);
        }
        ll l=s.size();
        ll ans=(n*(n-1)*(n-2))/6;
        for(auto x:s){
            ans-=(a[x]*(a[x]-1)*(a[x]-2))/6;
            ans-=(a[x]*(a[x]-1)*(n-a[x]))/2;
        }
        for(auto x:s){
            //cout<<x<<" "<<a[x]<<endl;
            ll sum=0;
            for(ll i=0;i<v[x].size();i++){
                sum+=(a[x]-1)*(b[v[x][i]]-1);
            }
            sum=(a[x]*(a[x]-1))/2*(n-a[x])-sum;
            ans+=sum;
            ans+=(a[x]*(a[x]-1)*(a[x]-2))/6;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}