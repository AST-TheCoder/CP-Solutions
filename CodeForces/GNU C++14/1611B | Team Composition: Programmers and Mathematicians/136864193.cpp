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
        ll a,b;
        cin>>a>>b;
 
        ll ans=0;
        if(a<b) swap(a,b);
        while(a-b>1 && a && b && a+b>=4){
            ll y=(a-b)/2+((a-b)%2);
            if(3*y>a) y=a/3;
            if(y>b) y=b;
            ans+=y;
            b-=y;
            a-=3*y;
            if(a<b) swap(a,b);
        }
        ans+=(b/2);
        cout<<ans<<endl;
    }
 
    return 0;
}