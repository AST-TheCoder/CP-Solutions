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
 
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    string s;
    cin>>s;
    a[0]=0;
    for(ll i=1;i<=n;i++){
        a[i]=a[i-1]+(ll)(s[i-1]-'a'+1);
    }
 
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;
    }
 
    return 0;
}