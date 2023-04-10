#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{
 
    ll t;
    cin>>t;
 
    read:
 
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
 
        string a,b,c;
        for(ll i=0;i<n-2;i++){
            for(ll j=i+1;j<n-1;j++){
                a.clear();
                for(ll k=0;k<=i;k++) a+=s[k];
                b.clear();
                for(ll k=i+1;k<=j;k++) b+=s[k];
                c.clear();
                for(ll k=j+1;k<n;k++) c+=s[k];
                if((b>=a && b>=c) || (b<=a && b<=c)){
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    goto read;
                }
            }
        }
        cout<<":("<<endl;
    }
 
    return 0;
}