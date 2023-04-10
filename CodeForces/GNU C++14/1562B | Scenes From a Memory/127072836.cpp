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
        ll k;
        cin>>k;
 
        string s;
        cin>>s;
        for(ll i=0;i<s.size();i++){
            if(s[i]!='2' && s[i]!='3' && s[i]!='5' && s[i]!='7'){
                cout<<1<<endl<<s[i]<<endl;
                goto read;
            }
        }
        string x=s;
        sort(all(x));
        for(ll i=0;i<s.size()-1;i++){
            if(x[i]==x[i+1]){
                cout<<2<<endl<<x[i]<<x[i+1]<<endl;
                goto read;
            }
        }
        cout<<2<<endl;
        vector<string> p;
        p.pb("27");
        p.pb("25");
        p.pb("35");
        p.pb("57");
        p.pb("32");
        p.pb("52");
        p.pb("72");
        p.pb("75");
        for(ll i=0;i<p.size();i++){
            x=p[i];
            for(ll j=0,l=0;j<s.size();j++){
                if(s[j]==x[l]) l++;
                if(l==2){
                    cout<<x<<endl;
                    goto read;
                }
            }
        }
    }
 
    return 0;
}