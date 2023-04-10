#include <bits/stdc++.h>
#define N 200005
using namespace std;
 
typedef long long ll;
 
typedef pair < int, pair < int , int > > query;
 
int block_size = sqrt(N);
 
bool cmp(query a, query b)
{
 if(a.first/block_size != b.first/block_size){
  return (a.first/block_size < b.first/block_size);
 }
 return (a.second.first < b.second.first);
}
 
ll ans;
int A[N];
 
ll V[1000005];
 
void add(ll x)
{
 ans -= (V[x]*V[x]*x);
 V[x]++;
 ans += (V[x]*V[x]*x);
}
 
void remove(ll x)
{
 ans -= (V[x]*V[x]*x);
 V[x]--;
 ans += (V[x]*V[x]*x);
}
 
ll resp[N];
 
int main()
{
 ios_base :: sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 scanf("%d %d", &n, &m);
 for (int i=0; i<n; i++)
 {
  scanf("%d", &A[i+1]);
 }
 vector < query > vet;
 for (int i=0; i<m; i++)
 {
  int l, r;
  scanf("%d %d", &l, &r);
  vet.push_back(make_pair(l, make_pair(r, i)));
 }
 sort(vet.begin(), vet.end(), cmp);
 ans = 0;
 int L = 0, R = 0;
 for (int i=0; i<m; i++)
 {
  int l = vet[i].first, r = vet[i].second.first, idx = vet[i].second.second;
  while (L < l){
   remove(A[L]);
   L++;
  }
  while (L > l){
   add(A[L-1]);
   L--;
  }
  while (R <= r){
   add(A[R]);
   R++;
  }
  while (R > r+1){
   remove(A[R-1]);
   R--;
  }
  resp[idx] = ans;
 }
 for (int i=0; i<m; i++) printf("%lli\n", resp[i]);
 
}