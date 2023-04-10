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
        for(ll i=1;i<=m;i++){
            if(i%2) cout<<1;
            else cout<<0;
        }
        cout<<endl;
        for(ll i=2;i<n;i++){
            for(ll j=1;j<=m;j++){
                if(j==1 || j==m){
                    if(i%2) cout<<1;
                    else cout<<0;
                }
                else cout<<0;
            }
            cout<<endl;
        }
        for(ll i=1;i<=m;i++){
            if(i==1 || (i>=m-1 && i%2)){
                if(n%2) cout<<1;
                else cout<<0; 
            }
            else if(i%2) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
 
    return 0;
}