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
        ll a,b;
        cin>>a>>b;
        ll c,d;
        cin>>c>>d;
        ll p,q;
        cin>>p>>q;
 
        ll ans=abs(a-c)+abs(b-d);
        if((a==c && a==p && q>=min(b,d) && q<=max(b,d)) || (b==d && b==q && p>=min(a,c) && p<=max(a,c)))
            ans+=2;
        cout<<ans<<endl;
    }
 
    return 0;
}