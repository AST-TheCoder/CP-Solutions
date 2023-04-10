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
    
    ll x=1;
    vector<string> c;
    while(x<=2000000000000000000){
        ll p=x;
        x*=2;
        string s;
        while(p){
            char c=(char)(p%10+'0');
            p/=10;
            s+=c;
        }
        reverse(all(s));
        c.pb(s);
    }
 
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll ans=Max;
        for(ll i=0;i<c.size();i++){
            ll j=0,k=0,temp=0;
            for(;j<c[i].size() && k<s.size();k++){
                if(c[i][j]==s[k]) j++;
                else temp++;
            }
            temp+=(c[i].size()-j)+(s.size()-k);
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}