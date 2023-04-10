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
 
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll c[6][n+1];
    for(ll i=0;i<6;i++){
        string t;
        if(i==0) t="abc";
        if(i==1) t="acb";
        if(i==2) t="bac";
        if(i==3) t="bca";
        if(i==4) t="cab";
        if(i==5) t="cba";
        c[i][0]=0;
        for(ll j=0,cnt=0;j<s.size();j++){
            if(t[j%3]!=s[j]) cnt++;
            c[i][j+1]=cnt;
        }
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ans=Max;
        for(ll i=0;i<6;i++){
            ans=min(ans,c[i][r]-c[i][l-1]);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}