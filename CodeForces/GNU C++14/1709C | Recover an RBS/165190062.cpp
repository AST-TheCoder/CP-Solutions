#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{   
    
    ll t;
    cin>>t;
 
    read:
    while(t--){
        string s;
        cin>>s;
 
        ll n=s.size();
        if(n%2){
            cout<<"NO"<<endl;
            goto read;
        }
 
        queue<ll> id1,id2;
        for(ll i=0,c=0;i<n;i++){
            if(s[i]=='(') c++;
            else if(s[i]==')') c--;
            else id1.push(i);
 
            if(c<0){
                if(id1.empty()){
                    cout<<"NO"<<endl;
                    goto read;
                }
                ll x=id1.front();
                id1.pop();
 
                s[x]='(';
                c++;
            }
        }
        for(ll i=n-1,c=0;i>=0;i--){
            if(s[i]==')') c++;
            else if(s[i]=='(') c--;
            else id2.push(i);
 
            if(c<0){
                if(id2.empty()){
                    cout<<"NO"<<endl;
                    goto read;
                }
                ll x=id2.front();
                id2.pop();
 
                s[x]=')';
                c++;
            }
        }
 
        vector<ll> id;
        for(ll i=0;i<n;i++)
            if(s[i]=='?') id.pb(i);
 
        ll ok=0;
        if(id.size()){
            ll cnt=0;
            for(ll i=0;i<id[0];i++){
                if(s[i]=='(') cnt++;
                else cnt--;
            }
            if(!cnt) ok=1;
            for(ll i=id[0]+1;i<id[1];i++){
                if(s[i]=='(') cnt++;
                else cnt--;
 
                if(cnt<=0){
                    ok=1;
                    break;
                }
            }
        }
        if(id.size()>2 || (id.size() && !ok)){
            cout<<"NO"<<endl;
            goto read;
        }
 
        cout<<"YES"<<endl;
    }
 
    return 0;
}