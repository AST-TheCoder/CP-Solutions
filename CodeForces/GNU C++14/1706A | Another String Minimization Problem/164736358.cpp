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
 
ll n,k,l,m;
 
int main()
{   
    
    ll t;
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        string s;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<m;i++) s+='B';
        for(ll i=0;i<n;i++){
            ll x=a[i]-1;
            ll y=m-a[i];
            if(x>y) swap(x,y);
 
            if(s[x]=='B') s[x]='A';
            else s[y]='A';
        }
        cout<<s<<endl;
    }
 
    return 0;
}