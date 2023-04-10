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
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        string s[n];
        for(ll i=0;i<n;i++) cin>>s[i];
 
        ll x=Max,y=Max;
 
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(s[i][j]=='R'){
                    x=min(i,x);
                    y=min(j,y);
                }
            }
        }
        if(x==Max || y==Max || s[x][y]!='R') cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
 
    return 0;
}