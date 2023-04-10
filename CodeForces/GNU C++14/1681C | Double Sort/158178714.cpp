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
        
        ll n;
        cin>>n;
 
        pair<ll,ll> v[n];
        ll a[n],b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
            v[i]={a[i],b[i]};
        }
 
        sort(v,v+n);
 
        for(ll i=1;i<n;i++){
            if(v[i].second<v[i-1].second){
                cout<<-1<<endl;
                goto read;
            }
        }
        vector<pair<ll,ll>> ans;
        for(ll i=0;i<n;i++){
            ll p=i;
            while(p<n){
                if(a[p]==v[i].first && b[p]==v[i].second) break;
                p++;
            }
            if(i!=p){
                ans.pb({i,p});
                swap(a[p],a[i]);
                swap(b[p],b[i]);
            }
        }
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
 
    return 0;
}