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
 
    int t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+1][6];
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=5;j++)
                cin>>a[i][j];
        }
 
        ll ans=1;
        for(ll i=2;i<=n;i++){
            ll c=0;
            for(ll j=1;j<=5;j++){
                if(a[ans][j]>a[i][j]) c++;
            }
            if(c>=3) ans=i;
        }
        for(ll i=1;i<=n;i++){
            ll c=0;
            for(ll j=1;j<=5;j++){
                if(a[ans][j]>a[i][j]) c++;
            }
            if(c>=3){
                cout<<-1<<endl;
                goto read;
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}