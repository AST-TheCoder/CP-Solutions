/******************************************************/
/******************************************************/
/**            BISMILLAHIR RAHMANIR RAHIM            **/
/**         Al-Shahriar Tonmoy - Red_Sparkle         **/
/**  Department of Computer Science and Engineering  **/
/**               Barisal University                 **/
/**               It's time to bloom.                **/
/******************************************************/
/******************************************************/
 
#include<bits/stdc++.h>
using namespace std;
 
#define     ll              long long int
#define     ul              unsigned long long int
#define     dob             double
#define     st              string
#define     ch              char
#define     pairl           pair<ll,ll>
#define     pairs           pair<string,int>
#define     pairi           pair<int,string>
#define     pairss          pair<string,string>
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     fr              first
#define     T               true
#define     F               false
#define     se              second
#define     sqr(x)          pow(x,2)
#define     all(v)          v.begin(),v.end()
#define     maxi            1000000000000014
#define     mini            -1000000000000014
#define     mod             1000000007
#define     an              1000000
#define     maps            map<string,int>
#define     mapi            map<int,int>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     nu              100005
 
int parent[nu],n,m,a,s,ranks[nu],i,k,b,j;
 
int find_root(int x){
 if(x==parent[x])return x;
 return parent[x] = find_root(parent[x]);
}
 
int main() {
 
    for(i=1;i<nu;i++) parent[i]=i;
 
 cin>>n>>m;
 
 for(i=0;i<n;i++){
 
  cin>>k;
 
  if(k>0) cin>>a,ranks[a]++;
  else s++;
 
  for(j=2;j<=k;j++){
 
   cin>>b;
 
   ranks[b]++;
 
   parent[find_root(a)]=find_root(b);
   parent[find_root(b)]=find_root(a);
  }
 }
 if(s==n) s++;
 
 for(i=1;i<=m;i++){
  if(parent[i]==i && ranks[i]>0)
   s++;
 }
 
 cout<<s-1;
 
    return 0;
}
/*****************  ALHAMDULILLAH  *****************/