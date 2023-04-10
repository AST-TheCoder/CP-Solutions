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
        ll n,a,b;
        cin>>n>>a>>b;
        string s,x="";
        cin>>s;
        x+=s[0];
        for(ll i=1;i<n;i++){
            if(s[i]!=s[i-1]) x+=s[i];
        }
        ll o=count(all(x),'0'),z=count(all(x),'1');
        ll ans=n*a;
        if(b>=0) ans+=(n*b);
        else{
            ans+=(min(o,z)+1)*b;
        }
        cout<<ans<<endl;
    }
    return 0;
}