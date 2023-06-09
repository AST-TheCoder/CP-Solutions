#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
 
    ll t;;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+1];
        set<ll> s;
        for(ll i=1;i<=n;i++) s.insert(i);
 
        for(ll i=1;i<=n/2;i++){
            cin>>a[2*i];
            s.erase(a[2*i]);
        }
 
        for(ll i=n;i>=1;i-=2){
            set<ll>::iterator it=s.upper_bound(a[i]);
            if(it==s.begin()){
                cout<<-1<<endl;
                goto read;
            }
            it--;
            a[i-1]=*it;
            s.erase(it);
        }
        if(s.size()){
            cout<<-1<<endl;
            goto read;
        }
        for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
 
    }
 
    return 0;
}