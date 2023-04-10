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
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        string s;
        cin>>s;
 
        ll p=n/2-1;
        if(n%2==0) p--;
 
        ll ans=1;
        for(ll i=p;i>=0;i--){
            if(s[i]==s[i+1]) ans++;
            else break;
        }
        ans*=2;
        if(n%2) ans--;
        cout<<ans<<endl;
    }
 
    return 0;
}