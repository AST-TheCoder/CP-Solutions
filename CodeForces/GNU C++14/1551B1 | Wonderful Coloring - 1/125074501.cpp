#include<cstdio>
using namespace std;
int main(){
 int T;scanf("%d",&T);
 while(T--){
  char s[51];
  scanf("%s",s);
  int c[26]={},t=0;
  for(int i=0;s[i];++i){
   ++c[s[i]-'a'];
   if(c[s[i]-'a']<3)++t;
  }
  printf("%d\n",t/2);
 }
}