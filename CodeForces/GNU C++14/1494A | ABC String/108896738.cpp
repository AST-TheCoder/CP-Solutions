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
 scanf("%lli",&t);
 
 while(t--){
  string s;
  cin>>s;
 
  ll a=0,b=0,c=0;
  char x='A',y='B',z='C';
 
  for(ll i=0;i<s.size();i++){
   if(s[i]=='A') a++;
   if(s[i]=='B') b++;
   if(s[i]=='C') c++;
  }
 
  if(s[0]=='B'){
   swap(a,b);
   swap(x,y);
  }
  if(s[0]=='C'){
   swap(a,c);
   swap(x,z);
  }
 
   for(ll i=0;i<s.size();i++){
    if(s[i]==x) s[i]='(';
   }
   if(b>c){
    for(ll i=0;i<s.size();i++){
     if(s[i]==y) s[i]=')';
    }
    if(b+c==a){
     for(ll i=0;i<s.size();i++){
      if(s[i]==z) s[i]=')';
     }
    }
    else if(a+c==b){
     for(ll i=0;i<s.size();i++){
      if(s[i]==z) s[i]='(';
     }
    }
    else{
     cout<<"NO"<<endl;
     continue;
    }
   }
   else{
    for(ll i=0;i<s.size();i++){
     if(s[i]==z) s[i]=')';
    }
    if(b+c==a){
     for(ll i=0;i<s.size();i++){
      if(s[i]==y) s[i]=')';
     }
    }
    else if(a+b==c){
     for(ll i=0;i<s.size();i++){
      if(s[i]==y) s[i]='(';
     }
    }
    else{
     cout<<"NO"<<endl;
     continue;
    }
   }
  ll o=0;
 
  for(ll i=0;i<s.size();i++){
   if(s[i]=='(') o++;
   else o--;
   if(o<0) break;
  }
  //cout<<s<<endl;
  if(o<0) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
 }
 
  
 
 return 0;
}