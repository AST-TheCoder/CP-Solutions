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
 
        ll b[n],ans[n];
        pair<ll,ll> a[n];
        for(ll i=0;i<n;i++){
            ans[i]=0;
            cin>>a[i].first;
            a[i].second=i;
        }
        for(ll i=0;i<n;i++) cin>>b[i];
 
        sort(a,a+n);
        for(ll i=n-1,j=n-1,v=-1;i>=0;i--){
            if(i==n-1){
                v=b[a[i].second];
                ans[a[i].second]=1;
                continue;
            }
            if(b[a[i].second]>v){
                while(j){
                    j--;
                    ans[a[j].second]=1;
                    v=min(v,b[a[j].second]);
                    if(i==j) break;
                }
            }
        }
        for(ll i=0;i<n;i++) cout<<ans[i];cout<<endl;
    }
 
    return 0;
}