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
        ll n,a,b;
        cin>>n>>a>>b;
        swap(a,b);
 
        if(abs(a-b)>1 || a+b>n-2){
            cout<<-1<<endl;
            continue;
        }
 
        ll ans[n+1];
        for(ll i=0;i<=n;i++) ans[i]=i;
 
        if(a>b){
            for(ll i=1,c=0;c<a;i+=2,c++){
                swap(ans[i],ans[i+1]);
            }
        }
        if(a<b){
            for(ll i=n,c=0;c<b;i-=2,c++){
                swap(ans[i],ans[i-1]);
            }
        }
        if(a==b && a){
            swap(ans[n],ans[n-1]);
            for(ll i=1,c=0;c<a;i+=2,c++){
                swap(ans[i],ans[i+1]);
            }
        }
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}