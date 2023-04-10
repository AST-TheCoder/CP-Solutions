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
        ll a[n+1];
        memset(a,-1,sizeof(a));
        for(ll i=1;i<=n;i++){
            if(a[i]!=-1) continue;
            ll chk;
            vector<ll> v;
            cout<<"?"<<" "<<i<<endl;
            cin>>chk;
            v.pb(chk);
            while(1){
                cout<<"?"<<" "<<i<<endl;
                cin>>chk;
                if(v[0]==chk) break;
                v.pb(chk);
            }
            ll sz=v.size(),j;
            for(j=0;j<sz;j++){
                v.pb(v[j]);
                if(v[j]==i) break;
            }j++;
            for(;j<v.size();j++){
                a[v[j-1]]=v[j];
            }
        }
        cout<<"!";
        for(ll i=1;i<=n;i++) cout<<" "<<a[i];cout<<endl;
    }
 
    return 0;
}