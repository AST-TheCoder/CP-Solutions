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
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+2];
        vector<pair<ll,ll>> v;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            v.pb({a[i],i});
        }
 
        sort(all(v),greater<pair<ll,ll>>());
        set<ll> x,p,q;
        ll l[n+2],r[n+2];
        for(ll i=0,j=0;j<n;j++){
            //cout<<v[j].first<<" "<<v[j].second<<endl;
            if(v[i].first!=v[j].first){
                while(i<j){
                    x.insert(v[i].second);
                    i++;
                }
            }
            if(x.size()==0){
                l[v[j].second]=0;
                r[v[j].second]=n+1;
                continue;
            }
            set<ll>::iterator it=x.upper_bound(v[j].second);
            if(it==x.end()){
                r[v[j].second]=n+1;
            }else r[v[j].second]=*it;
            if(it==x.begin()){
                l[v[j].second]=0;
            }else{
                it--;
                l[v[j].second]=*it;
            }
            //cout<<v[j].second<<" "<<l[v[j].second]<<" "<<r[v[j].second]<<endl;
        }
        v.clear();
        for(ll i=1,s=0;i<=n;i++){
            s+=a[i];
            v.pb({s,i});
        }
        sort(all(v),greater<pair<ll,ll>>());
        for(ll i=0,j=0;j<n;j++){
            //if(a[v[j].second]<=0) continue;
            if(v[i].first!=v[j].first){
                while(i<j){
                    p.insert(v[i].second);
                    i++;
                }
            }
            if(!p.size()) continue;
            set<ll>::iterator it=p.upper_bound(v[j].second);
            if(it!=p.end() && *it<r[v[j].second]){
                cout<<"NO"<<endl;
                goto read;
            }
        }
 
        v.clear();
        for(ll i=n,s=0;i>=1;i--){
            s+=a[i];
            v.pb({s,i});
        }
        sort(all(v),greater<pair<ll,ll>>());
        for(ll i=0,j=0;j<n;j++){
            //if(a[v[j].second]<=0) continue;
            if(v[i].first!=v[j].first){
                while(i<j){
                    q.insert(v[i].second);
                    i++;
                }
            }
            if(!q.size()) continue;
            set<ll>::iterator it=q.upper_bound(v[j].second);
            if(it==q.begin()) continue;
            it--;
            if(*it>l[v[j].second]){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}