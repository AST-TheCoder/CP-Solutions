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
 
    ll n,m;
    cin>>n>>m;
    string s[n];
    for(ll i=0;i<n;i++) cin>>s[i];
    ll a[m];
    memset(a,0,sizeof(a));
    for(ll i=1;i<n;i++){
        for(ll j=1;j<m;j++){
            if((s[i-1][j]=='X' || s[i-1][j]=='N') && (s[i][j-1]=='X' || s[i][j-1]=='N')){
                //s[i][j]='N';
                a[j]=1;
            }
        }
    }
    for(ll i=1;i<m;i++) a[i]+=a[i-1];
    ll q;
    cin>>q;
    //cout<<q<<endl;
    while(q--){
    //cout<<q<<endl;
        ll x,y;
        cin>>x>>y;
        x--,y--;
        if(a[y]-a[x]) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
 
    return 0;
}
/*
4 5
..XXX
...X.
...X.
...X.
5
1 3
3 3
4 5
5 5
1 5
*/