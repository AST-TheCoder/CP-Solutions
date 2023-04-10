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
        string s;
        cin>>s;
        ll c=count(all(s),'2');
        if(c && c<3){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        ll a[n];
        memset(a,-1,sizeof(a));
        for(ll i=0;i<n;i++){
            ll ok=0;
            for(ll j=0;j<n;j++){
                if(i==j) cout<<"X";
                else if(s[i]=='1' || s[j]=='1') cout<<'=';
                else{
                    if(i<j && !ok){
                        cout<<"+";
                        ok=1;
                        a[j]=i;
                    }
                    else{
                        if(a[i]==j || i<j) cout<<"-";
                        else cout<<'+';
                    }
                }
            }
            cout<<endl;
        }
    }
 
    return 0;
}