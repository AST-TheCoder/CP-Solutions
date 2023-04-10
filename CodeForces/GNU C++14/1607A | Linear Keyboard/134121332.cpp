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
        string s,p;
        cin>>p>>s;
        ll ans=0;
        ll x[200];
        for(ll i=0;i<p.size();i++) x[p[i]]=i;
        for(ll i=1;i<s.size();i++){
            ans+=abs(x[s[i]]-x[s[i-1]]);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}