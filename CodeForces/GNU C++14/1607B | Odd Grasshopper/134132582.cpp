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
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll x,n;
        cin>>x>>n;
        ll r=(n+1)/4;
        if(x%2) x-=4*r;
        else x+=4*r;
        for(ll i=4*r;i<=n;i++){
            if(abs(x)%2) x+=i;
            else x-=i;
        }
        cout<<x<<endl;
    }
 
    return 0;
}