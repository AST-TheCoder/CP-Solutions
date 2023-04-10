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
        ll n;
        cin>>n;
 
        string s[n],ans;
        for(ll i=0;i<n-2;i++) cin>>s[i];
        ans+=s[0][0];
        for(ll i=1;i<n-2;i++){
            if(s[i][0]!=s[i-1][1]) ans+=s[i-1][1];
            ans+=s[i][0];
        }
        ans+=s[n-3][1];
        if(ans.size()!=n) ans+='a';
        cout<<ans<<endl;
    }
 
    return 0;
}