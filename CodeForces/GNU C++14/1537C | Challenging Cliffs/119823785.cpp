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
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        ll ans[n],id,d=Max;
 
        for(ll i=1;i<n;i++){
            if(a[i]-a[i-1]<d){
                d=a[i]-a[i-1];
                id=i-1;
            }
        }
 
        ans[0]=a[id];
        ans[n-1]=a[id+1];
 
        if(!id){
            for(ll i=2;i<n;i++)
                ans[i-1]=a[i];
        }
        else{
            ll j=1;
            for(ll i=id+2;i<n;i++,j++){
                ans[j]=a[i];
            }
            for(ll i=0;i<id;i++,j++){
                ans[j]=a[i];
            }
        }
 
        for(ll i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }cout<<endl;
 
    }  
 
    return 0;
}