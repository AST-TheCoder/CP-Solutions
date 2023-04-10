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
 
    ll n,k,ans=0,x;
    cin>>n>>k;
 
    if(n%2 && k%2==0){
        cout<<-1<<endl;
        return 0;
    }
    if(n%2==0 && k%2 && n-k<k){
        //if((n%(n-k))%2) cout<<-1<<endl;
        //else{
            ll l=1,d=n-k,c=n/(n-k);
            if((n%(n-k))%2) c--;
            for(ll i=1;i<=c;i++){
                cout<<"?";
                for(ll j=1;j<=n;j++){
                    if(j>=l && j<l+d) continue;
                    cout<<" "<<j;
                }
                cout<<endl;
                cin>>x;
                ans^=x;
                l+=d;
            }
 
            ll f=(n-c*(n-k))/2;
            if(f){
                cout<<"?";
                for(ll i=1;i<=k-f;i++) cout<<" "<<i;
                for(ll i=n-f+1;i<=n;i++) cout<<" "<<i;
                cout<<endl;
                cin>>x;
                ans^=x;
 
                cout<<"?";
                for(ll i=1;i<=k-f;i++) cout<<" "<<i;
                for(ll i=n-2*f+1;i<=n-f;i++) cout<<" "<<i;
                cout<<endl;
                cin>>x;
                ans^=x;
            }
 
            cout<<"! "<<ans<<endl;
        //}
        return 0;
    }
 
    ll d=n/k;
    if((n-d*k)%2 || (k%2==0 && n%k && d>1)) d--;
 
    for(ll i=0;i<d;i++){
        cout<<"?";
        for(ll j=i*k+1;j<=(i+1)*k;j++) cout<<" "<<j;
        cout<<endl;
        cin>>x;
        ans^=x;
    }
 
    ll f=n-(d*k);
    f/=2;
    if(f){
        cout<<"?";
        for(ll i=1;i<=k-f;i++) cout<<" "<<i;
        for(ll i=d*k+1;i<=d*k+f;i++) cout<<" "<<i;
        cout<<endl;
        cin>>x;
        ans^=x;
 
        cout<<"?";
        for(ll i=1;i<=k-f;i++) cout<<" "<<i;
        for(ll i=d*k+f+1;i<=n;i++) cout<<" "<<i;
        cout<<endl;
        cin>>x;
        ans^=x;
    }
    cout<<"! "<<ans<<endl;
 
    return 0;
}