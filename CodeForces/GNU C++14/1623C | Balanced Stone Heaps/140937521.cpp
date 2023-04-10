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
 
        ll a[n],l=1,r=0,ans=1;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            r+=a[i];
        }
        r/=n;
        while(l<=r){
            ll m=(l+r)/2;
            //cout<<l<<" "<<m<<" "<<r<<endl;
            ll temp[n],chk=Max;
            for(ll i=0;i<n;i++) temp[i]=0;
            for(ll i=n-1;i>=0;i--){
                temp[i]+=a[i];
                if(temp[i]<m){
                    chk=-1;
                    break;
                }
                if(i>=2){
                    ll v=temp[i]-m;
                    v=min(v,a[i]);
                    ll d=v/3;
                    temp[i-2]+=2*d;
                    temp[i-1]+=d;
                }
            }
            if(chk==-1) r=m-1;
            else{
                ans=m;
                l=m+1;
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}