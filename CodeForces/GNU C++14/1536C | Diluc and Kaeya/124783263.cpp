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
        ll n;
        cin>>n;
        string s;
        cin>>s;
 
        map<pair<ll,ll>,ll> c;
        for(ll i=0,d=0,k=0;i<n;i++){
            if(s[i]=='D') d++;
            else k++;
            ll g=__gcd(d,k);
            cout<<++c[{d/g,k/g}]<<" ";
        }cout<<endl;
    }
 
    return 0;
}