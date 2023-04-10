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
        ll n;
        cin>>n;
 
        string s;
        cin>>s;
 
        ll ans=s.size()+1;
 
        ll r=count(all(s),'R');
        ll d=count(all(s),'D');
 
        if(r && d){
            ll x=n-r-1;
            ll y=n-d-1;
 
            ans+=x*y;
        }
 
        for(ll i=0,x=1,y=1;i<s.size();i++){
            if(s[i]=='D') x++;
            else{
                ll p=d+1;
                p=p-x+1;
                ll q=n-r-1;
                ans+=p*q;
                break;
            }
        }
        for(ll i=0,x=1,y=1;i<s.size();i++){
            if(s[i]=='R') y++;
            else{
                ll p=r+1;
                p=p-y+1;
                ll q=n-d-1;
                ans+=p*q;
                break;
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}