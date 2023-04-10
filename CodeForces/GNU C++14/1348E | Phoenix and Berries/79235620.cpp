//Solution 1
#include <bits/stdc++.h>
using namespace std;
 
int N,K;
int a[505],b[505];
bool dp[505][505];  //number of shrubs considered, "extra" red berries
 
int main(){
  cin>>N>>K;
  long long totA=0,totB=0;
  for (int i=1;i<=N;i++){
    cin>>a[i]>>b[i];
    totA+=a[i];
    totB+=b[i];
  }
  dp[0][0]=true;
  for (int i=1;i<=N;i++){
    for (int j=0;j<K;j++){
      //leave a[i]%K extra red berries
      dp[i][j]=dp[i-1][(j-a[i]%K+K)%K];
      for (int l=0;l<=min(K-1,a[i]);l++){
 //check if we can leave l extra red berries
 if ((a[i]-l)%K+b[i]>=K)
   dp[i][j]|=dp[i-1][(j-l+K)%K];
      }
    }
  }
  long long ans=0;
  for (int i=0;i<K;i++){
    if (dp[N][i])
      ans=max(ans,(totA+totB-i)/K);
  }
  cout<<ans<<endl;
}