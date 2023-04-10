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
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll ans[n];
        for(ll i=0;i<=n;i++) ans[i]=i;
 
        for(ll i=ans[n-1];i>=0;){
            ll r=sqrt(ans[i]);
            if(r*r!=ans[i]) r++;
            r*=r;
            ll k=r-ans[i],j=i;
            i=k-1;
            for(;k<=j;k++,j--) swap(ans[k],ans[j]);
        }
        for(ll i=0;i<n;i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}