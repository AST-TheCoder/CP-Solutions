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
    read:
    while(t--){
        ll n;
        cin>>n;
        ll a[n][5];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<5;j++){
                cin>>a[i][j];
            }
        }
        if(n%2){
            cout<<"NO"<<endl;
            continue;
        }
        for(ll p=0;p<5;p++){
            for(ll q=0;q<5;q++){
                if(p==q) continue;
                vector<pair<ll,ll>> temp;
                for(ll i=0;i<n;i++){
                    if(a[i][p]) temp.pb({i,1});
                    if(a[i][q]) temp.pb({i,2});
                }
                sort(all(temp));
                ll l=0,m=0,r=0;
                for(ll i=0;i<temp.size();i++){
                    if(i+1<temp.size() && temp[i].first==temp[i+1].first){
                        m++;
                        i++;
                    }
                    else if(temp[i].second==1) l++;
                    else r++;
                }
                if(l>n/2 || m<n/2-l || r>n/2 || l+m+r!=n) continue;
                m-=(n/2-l);
                if(r+m==n/2){
                    //cout<<p<<" "<<q<<endl;
                    cout<<"YES"<<endl;
                    goto read;
                }
            }
        }
        cout<<"NO"<<endl;
    }
 
    return 0;
}