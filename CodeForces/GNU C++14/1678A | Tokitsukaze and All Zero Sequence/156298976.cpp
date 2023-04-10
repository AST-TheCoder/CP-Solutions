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
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n],cnt=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]) cnt++;
        }
        sort(a,a+n);
        if(!a[0]){
            cout<<cnt<<endl;
            continue;
        }
        for(ll i=1;i<n;i++){
            if(a[i]==a[i-1]){
                cout<<n<<endl;
                goto read;
            }
        }
        cout<<n+1<<endl;
    }
 
    return 0;
}