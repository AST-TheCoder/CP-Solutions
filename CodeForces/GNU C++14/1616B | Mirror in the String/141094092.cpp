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
        ll n;
        cin>>n;
 
        string s;
        cin>>s;
 
        if(s.size()>=2 && s[0]==s[1]){
            cout<<s[0]<<s[1]<<endl;
            continue;
        }
 
        string x;
        x+=s[0];
        for(ll i=1;i<s.size();i++){
            if(s[i]<=s[i-1]) x+=s[i];
            else break;
        }
        string sna,ans;
        for(ll i=0;i<x.size();i++){
            ans+=x[i];
            //if(x[i]==x[x.size()-1]) break;
        }
        sna=ans;
        reverse(all(sna));
        ans+=sna;
        cout<<ans<<endl;
    }
 
    return 0;
}