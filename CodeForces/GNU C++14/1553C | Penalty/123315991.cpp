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
    
    ll tc;
    cin>>tc;
 
    read:
    while(tc--){
        string s;
        cin>>s;
 
        for(ll i=0;i<10;i++){
            ll m1=0,n1=0,m2=0,n2=0,k1=0,k2=0;
            for(ll j=0;j<=i;j++){
                if(j%2){
                    if(s[j]=='?') m2++;
                    if(s[j]=='1'){
                        m2++;
                        n2++;
                    }
                    k2++;
                }
                else{
                    if(s[j]=='?') m1++;
                    if(s[j]=='1'){
                        m1++;
                        n1++;
                    }
                    k1++;
                }
            }
            k1=5-k1;
            k2=5-k2;
            if(m1>n2 && m1>n2+k2){
                cout<<i+1<<endl;
                goto read;
            }
            if(m2>n1 && m2>n1+k1){
                cout<<i+1<<endl;
                goto read;
            }
        }
        cout<<10<<endl;
    }
 
    return 0;
}