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
        string s;
        cin>>s;
 
        if(s[0]!='?'){
            for(ll i=0;i<s.size();i++){
                if(s[i]!='?') cout<<s[i];
                else{
                    if(s[i-1]=='B'){
                        s[i]='R';
                    }
                    else s[i]='B';
                    cout<<s[i];
                }
            }
        }
        else{
            ll len=0,i=0;
            while(i<s.size() && s[i]=='?'){
                len++;
                i++;
            }
            if(len==n){
                for(ll i=0;i<s.size();i++){
                    if(i%2) cout<<"B";
                    else cout<<"R";
                }
            }
            else{
                if(s[len]=='B'){
                    if(len%2) s[0]='R';
                    else s[0]='B';
                }
                else{
                    if(len%2) s[0]='B';
                    else s[0]='R';
                }
                for(ll i=0;i<s.size();i++){
                    if(s[i]!='?') cout<<s[i];
                    else{
                        if(s[i-1]=='B') s[i]='R';
                        else s[i]='B';
                        cout<<s[i];
                    }
                }
            }
        }
        cout<<endl;
    }
 
    return 0;
}