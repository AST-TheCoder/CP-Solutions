#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
    
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,x,team=0;
        cin>>n>>x;
 
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
 
        for(ll i=n,cnt=0;i>=1;i--){
            cnt++;
            if(a[i]*cnt>=x){
                team++;
                cnt=0;
            }
        }
 
        cout<<team<<endl;
    }
 
    return 0;
}