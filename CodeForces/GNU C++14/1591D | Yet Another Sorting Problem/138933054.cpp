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
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
 
        if(n==1) cout<<"YES"<<endl;
        if(n==2){
            if(a[0]<=a[1]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        if(n>=4){
            pair<ll,ll> b[n];
            ll x[n];
            for(ll i=0;i<n;i++){
                b[i].first=a[i];
                b[i].second=i;
                x[i]=a[i];
            }
            sort(b,b+n);
            sort(x,x+n);
            for(ll i=0;i<n;i++){
                if(i && b[i].first==b[i-1].first){
                    cout<<"YES"<<endl;
                    goto read;
                }
                if(b[i].second!=i && i<n-3){
                    if(b[i].second!=n-1){
                        b[lower_bound(x,x+n,a[i])-x].second=n-1;
                        b[lower_bound(x,x+n,a[n-1])-x].second=b[i].second;
                        swap(a[i],a[b[i].second]);
                        swap(a[n-1],a[b[i].second]);
                        b[i].second=i;
                    }
                    else{
                        b[lower_bound(x,x+n,a[i])-x].second=i+1;
                        b[lower_bound(x,x+n,a[i+1])-x].second=b[i].second;
                        swap(a[i],a[i+1]);
                        swap(a[n-1],a[i]);
                        b[i].second=i;
                    }
                }
            }
            a[0]=a[n-3];
            a[1]=a[n-2];
            a[2]=a[n-1];
            n=3;
        }
 
        if(n==3){
            ll b[9];
            for(ll i=0;i<9;i++){
                b[i]=a[i%3];
                //cout<<b[i]<<" ";
            }//cout<<endl;
            for(ll i=0;i<7;i++){
                if(b[i]<=b[i+1] && b[i+1]<=b[i+2]){
                    cout<<"YES"<<endl;
                    goto read;
                }
            }
            cout<<"NO"<<endl;
        }
    }
 
    return 0;
}