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
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll c[26][m];
        memset(c,0,sizeof(c));
 
        for(ll i=0;i<n;i++){
            string x;
            cin>>x;
            for(ll j=0;j<m;j++){
                c[x[j]-'a'][j]++;
            }
        }
        for(ll i=0;i<n-1;i++){
            string x;
            cin>>x;
            for(ll j=0;j<m;j++){
                c[x[j]-'a'][j]--;
            }
        }
 
        for(ll i=0;i<m;i++){
            for(ll j=0;j<26;j++){
                if(c[j][i]){
                    cout<<(char)(j+'a');
                    break;
                }
            }
        }cout<<endl;
    }
 
    return 0;
}