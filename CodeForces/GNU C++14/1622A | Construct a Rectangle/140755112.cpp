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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]==a[2]) cout<<"YES"<<endl;
        else{
            if((a[0]==a[1] && a[2]%2==0) || (a[0]%2==0 && a[1]==a[2])) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
 
    return 0;
}