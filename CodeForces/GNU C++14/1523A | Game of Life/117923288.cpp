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
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<ll> v;
        v.pb(-2*m-1);
        for(ll i=0;i<n;i++){
            if(s[i]=='1') v.pb(i);
        }v.pb(n+2*m+1);
        ll c=0;
        for(ll i=0;i<v.size()-1;i++){
            for(ll j=1;j<=m && v[i]+j<v[i+1]-j && v[i]+j<n && v[i+1]-j>=0 && ((v[i]>=0 && v[i]<n) || (v[i+1]>=0 && v[i+1]<n));j++){
                if(v[i]+j>=0 && v[i]+j<n) s[v[i]+j]='1';
                if(v[i+1]-j>=0 && v[i+1]-j<n) s[v[i+1]-j]='1';
                c++;
            }
        }
        cout<<s<<endl;
        //cout<<c<<endl;
    }
 
    return 0;
}