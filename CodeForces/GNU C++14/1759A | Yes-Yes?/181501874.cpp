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
 
    ll t;;
    cin>>t;
 
    read:
    while(t--){
        
        string s;
        cin>>s;
 
        ll n=s.size();
 
        if(s[0]=='e'){
            s="Y"+s;
            n++;
        }
        else if(s[0]=='s'){
            s="Ye"+s;
            n+=2;
        }
 
        if(s[n-1]=='Y'){
            s+="es";
            n+=2;
        }
        else if(s[n-1]=='e'){
            s+="s";
            n++;
        }
 
        if(n%3){
            cout<<"NO"<<endl;
            goto read;
        }
 
        for(ll i=0;i<n;i+=3){
            if(s[i]=='Y' && s[i+1]=='e' && s[i+2]=='s') continue;
            cout<<"NO"<<endl;
            goto read;
        }
 
        cout<<"YES"<<endl;
 
    }
 
    return 0;
}