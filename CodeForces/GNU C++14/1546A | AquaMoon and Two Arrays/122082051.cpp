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
        ll n;
        cin>>n;
 
        ll a[n],b[n],x=0,y=0;
        vector<ll> p,q;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        for(ll i=0;i<n;i++){
            if(a[i]<b[i]){
                p.pb(i);
                x+=(b[i]-a[i]);
            }
            if(a[i]>b[i]){
                q.pb(i);
                y+=(a[i]-b[i]);
            }
        }
 
        if(x!=y){
            cout<<-1<<endl;
            continue;
        }
 
        //for(ll i=0;i<p.size();i++) cout<<p[i]<<" ";cout<<endl;
        //for(ll i=0;i<q.size();i++) cout<<q[i]<<" ";cout<<endl;
 
        cout<<x<<endl;
        for(ll i=0,j=0;i<p.size() && j<q.size();){
            a[p[i]]++;
            a[q[j]]--;
            cout<<q[j]+1<<" "<<p[i]+1<<endl;
            if(a[p[i]]==b[p[i]]) i++;
            if(a[q[j]]==b[q[j]]) j++;
        }
    }
 
    return 0;
}