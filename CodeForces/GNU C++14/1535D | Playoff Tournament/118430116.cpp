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
    
    ll k;
    cin>>k;
 
    string s;
    cin>>s;
    s+="1";
    reverse(all(s));
    ll ans[s.size()];
    for(ll i=s.size()-1;i>=1;i--){
        if(2*i+1>=s.size()){
            if(s[i]!='?') ans[i]=1;
            else ans[i]=2;
        }
        else{
            if(s[i]=='?') ans[i]=ans[2*i]+ans[2*i+1];
            if(s[i]=='0') ans[i]=ans[2*i+1];
            if(s[i]=='1') ans[i]=ans[2*i];
        }
    }
 
    ll q;
    cin>>q;
    while(q--){
        ll p;
        char c;
        cin>>p>>c;
        p=s.size()-p;
        s[p]=c;
        while(p){
            if(2*p+1>=s.size()){
                if(s[p]!='?') ans[p]=1;
                else ans[p]=2;
            }
            else{
                if(s[p]=='?') ans[p]=ans[2*p]+ans[2*p+1];
                if(s[p]=='0') ans[p]=ans[2*p+1];
                if(s[p]=='1') ans[p]=ans[2*p];
            }
            p/=2;
        }
        cout<<ans[1]<<endl;
    }
 
    return 0;
}