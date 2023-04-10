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
 
    ll n;
    cin>>n;
 
    pair<ll,ll> a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;
    }
 
    sort(a,a+n);
    ll ans=0;
    for(ll i=0,j=n-1,c=0;i<=j;){
        if(c>=a[i].first){
            ans+=a[i].second;
            c+=a[i].second;
            a[i].second=0;
            i++;
        }
        else{
            if(a[i].first-c>=a[j].second){
                ans+=(2*a[j].second);
                c+=a[j].second;
                a[j].second=0;
                j--;
            }
            else{
                ll d=a[i].first-c;
                ans+=(2*d);
                c+=d;
                a[j].second-=d;
            }
        }
    }
    cout<<ans<<endl;
 
    return 0;
}