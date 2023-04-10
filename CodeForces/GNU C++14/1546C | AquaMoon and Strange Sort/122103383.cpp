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
 
        vector<ll> a;
        ll id[100007][2];
        memset(id,0,sizeof(id));
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            a.pb(x);
            id[x][i%2]++;
        }
        sort(all(a));
 
        for(ll i=0;i<n;i++){
            if(id[a[i]][i%2]) id[a[i]][i%2]--;
            else{
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}