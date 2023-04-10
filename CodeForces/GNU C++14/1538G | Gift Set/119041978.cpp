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
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        if(a>b) swap(a,b);
 
        ll d=b-a;
        if(!d){
            cout<<x/a<<endl;
            continue;
        }
        ll m=(y-x)/d;
        if(x/a<m || y/b<m){
            cout<<min(x/a,y/b)<<endl;
            continue;
        }
        x-=m*a;
        y-=m*b;
        ll ans=m;
        m=min(x/(a+b),y/(a+b));
        ans+=2*m;
        x-=m*(a+b);
        y-=m*(a+b);
        if(x>=a && y>=b) ans++;
        cout<<ans<<endl;
    }
 
    return 0;
}