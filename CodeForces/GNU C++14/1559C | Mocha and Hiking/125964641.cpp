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
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        if(a[1]==1){
            cout<<n+1;
            for(ll i=1;i<=n;i++) cout<<" "<<i;
            cout<<endl;
        }
        else{
            for(ll i=1,ok=0;i<=n;i++){
                if(a[i]==1){
                    if(!ok){
                        cout<<" "<<n+1;
                        ok=1;
                    }
                }
                if(i!=1) cout<<" "<<i;
                else cout<<i;
                if(i==n && !ok) cout<<" "<<n+1;
            }
            cout<<endl;
        }
    }
 
    return 0;
}