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
        string s;
        cin>>s;
        ll n=s.size();
        sort(all(s));
        if(s[0]==s[n-1]){
            cout<<s<<endl;
            continue;
        }
        ll c[26];
        memset(c,0,sizeof(c));
        for(ll i=0;i<n;i++){
            c[s[i]-'a']++;
        }
        ll ok=0;
        for(ll i=0;i<26;i++){
            if(c[i]==1){
                ok=1;
                cout<<(char)(i+'a');
                c[i]=0;
                for(i=0;i<26;i++){
                    while(c[i]--){
                        cout<<(char)(i+'a');
                    }
                }
                cout<<endl;
                break;
            }
        }
        if(ok) continue;
        ll idx;
        for(ll i=0;i<26;i++){
            if(c[i]){
                idx=i;
                break;
            }
        }
        if(n-c[idx]>=c[idx]-2){
            cout<<(char)(idx+'a');
            c[idx]--;
            for(ll i=idx+1;i<26;){
                if(!c[i]){
                    i++;
                    continue;
                }
                if(c[idx]){
                    cout<<(char)(idx+'a');
                    c[idx]--;
                }
                cout<<(char)(i+'a');
                c[i]--;
            }
            if(c[idx]) cout<<(char)(idx+'a');
            cout<<endl;
        }
        else{
            cout<<(char)(idx+'a');
            c[idx]--;
            ok=0;
            for(ll i=idx+1;i<26;i++){
                if(c[i] && !ok){
                    c[i]--;
                    cout<<(char)(i+'a');
                    ok=-1;
                }
                else if(c[i]){
                    ok=i;
                    break;
                }
            }
            if(ok!=-1){
                while(c[idx]--) cout<<(char)(idx+'a');
                cout<<(char)(ok+'a');
                c[ok]--;
                for(ll i=idx+1;i<26;i++){
                    while(c[i]--){
                        cout<<(char)(i+'a');
                    }
                }
                cout<<endl;
            }
            else{
                for(ll i=idx+1;i<26;i++){
                    while(c[i]--){
                        cout<<(char)(i+'a');
                    }
                }
                while(c[idx]--) cout<<(char)(idx+'a');
                cout<<endl;
            }
        }
    }
 
    return 0;
}