#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 vector<long long int> prime;
 bool chk[501];
 pair<long long int,long long int> pf[501];
 long long int pr[200001];
 
 memset(chk,0,sizeof(chk));
 memset(pf,-1,sizeof(pf));
 memset(pr,0,sizeof(pr));
 
 for(long long int i=2;i<=500;i++){
  if(!chk[i]){
   prime.push_back(i);
   for(long long int j=i*i;j<=500;j+=i){
    chk[j]=1;
   }
  }
 }
 
 long long int n;
 cin>>n;
 
 for(long long int i=0;i<n;i++){
  long long int x;
  cin>>x;
  for(long long int j=0;j<prime.size();j++){
   long long int c=0;
   while(x%prime[j]==0){
    c++;
    x/=prime[j];
   }
   if(c<pf[prime[j]].first || pf[prime[j]].first==-1){
    pf[prime[j]].second=pf[prime[j]].first;
    pf[prime[j]].first=c;
   }
   else if(c<pf[prime[j]].second || pf[prime[j]].second==-1){
    pf[prime[j]].second=c;
   }
  }
  pr[x]++;
 }
 
 long long int ans=1;
 for(long long int i=2;i<=200000;i++){
  if(i<=500){
   if(pf[i].second!=-1) ans*=pow(i,pf[i].second);
  }
  else{
   if(pr[i]>=n-1) ans*=i;
  }
 }
 
 cout<<ans<<endl;
 
 return 0;
}