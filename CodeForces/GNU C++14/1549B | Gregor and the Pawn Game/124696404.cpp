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
        string a,b;
        cin>>a>>b;
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(a[i]=='0' && b[i]=='1'){
                ans++;
                b[i]='0';
            }
            if(a[i]=='1' && b[i]=='1'){
                if(i-1!=-1 && a[i-1]=='1' && b[i-1]=='0'){
                    ans++;
                    b[i]='0';
                    a[i-1]='0';
                }
                else if(i+1!=n && a[i+1]=='1' && b[i+1]=='1'){
                    ans+=2;
                    a[i]=b[i]=a[i+1]=b[i+1]='0';
                    i++;
                }
                else if(i+1!=n && a[i+1]=='1' && b[i+1]=='0'){
                    ans++;
                    b[i]=a[i+1]='0';
                }
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}