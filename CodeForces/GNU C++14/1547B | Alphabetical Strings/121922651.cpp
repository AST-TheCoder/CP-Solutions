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
        string s;
        cin>>s;
 
        ll id=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='a'){
                id=i;
                break;
            }
        }
        char ch='a';
        for(ll i=id,j=id+1,c=0;c<s.size();c++,ch++){
            if(i>=0 && s[i]==ch) i--;
            else if(j<s.size() && s[j]==ch) j++;
            else{
                cout<<"NO"<<endl;
                goto read;
            }
        }
 
        cout<<"YES"<<endl;
    }
 
    return 0;
}