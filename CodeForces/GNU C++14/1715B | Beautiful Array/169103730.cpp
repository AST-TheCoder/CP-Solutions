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
 
    while(t--){
        ll n,k,b,s;
        cin>>n>>k>>b>>s;
 
        if(s<k*b || s>(k*b)+n*(k-1)){
            cout<<-1<<endl;
            continue;
        }
        ll ans[n];
        memset(ans,0,sizeof(ans));
        ans[0]=k*b;
        s-=k*b;
        for(ll i=0;i<n;i++){
            ll v=min(k-1,s);
            ans[i]+=v;
            s-=v;
            cout<<ans[i]<<" ";
        }cout<<endl;
    }
 
    return 0;
}