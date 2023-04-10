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
        ll n,s=0;
        cin>>n;
 
        priority_queue<ll> x,y;
        for(ll i=0;i<n;i++){
            ll v;
            cin>>v;
 
            x.push(v);
            s+=v;
        }
        y.push(s);
        while(!x.empty()){
            ll v=y.top();
            y.pop();
 
            if(v==x.top()){
                x.pop();
                continue;
            }
 
            if(v<x.top()){
                cout<<"NO"<<endl;
                goto read;
            }
            ll p=v/2;
            ll q=v-p;
            if(q==x.top()) x.pop();
            else y.push(q);
            if(p==x.top()) x.pop();
            else y.push(p);
        }
        if(y.size()!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
 
    return 0;
}