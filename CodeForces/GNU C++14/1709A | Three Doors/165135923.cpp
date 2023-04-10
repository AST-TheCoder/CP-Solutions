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
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll x;
        cin>>x;
 
        ll a[4],c=0;
        for(ll i=1;i<=3;i++) cin>>a[i];
 
        while(x){
            x=a[x];
            c++;
        }
        if(c==3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 
    return 0;
}