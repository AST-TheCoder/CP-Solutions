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
        ll n,k;
        cin>>n>>k;
 
        ll x=(n-1)/2+1;
 
        if(x<k){
            cout<<-1<<endl;
            continue;
        }
 
        string s[n];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++) s[i]+='.';
        }
        for(ll i=0,j=0,c=0;c<k;c++){
            s[i][j]='R';
            i+=2;
            j+=2;
        }
        for(ll i=0;i<n;i++) cout<<s[i]<<endl;
    }
 
    return 0;
}