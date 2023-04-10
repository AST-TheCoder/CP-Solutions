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
 
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a<b) swap(a,b);
        ll am=(a+b+1)/2,bm=(a+b)/2;
        set<ll> s;
        ll mn,mx;
        mn=a-am;
        mx=(a+b)-mn;
        for(ll i=mn;i<=mx;i+=2) s.insert(i);
        if((a+b)%2){
            mn=a-bm;
            mx=(a+b)-mn+1;
            for(ll i=mn;i<=mx;i+=2) s.insert(i);
        }
        cout<<s.size()<<endl;
        for(auto x:s) cout<<x<<" ";
        cout<<endl;
    }
 
    return 0;
}