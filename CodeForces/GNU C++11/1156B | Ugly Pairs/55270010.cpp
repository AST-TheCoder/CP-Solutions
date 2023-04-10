#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
bool check(string s){
 bool ok = true;
 forn(i, int(s.size()) - 1)
  ok &= (abs(s[i] - s[i + 1]) != 1);
 return ok;
}
 
int main() {
 int T;
 scanf("%d", &T);
 static char buf[120];
 forn(_, T){
  scanf("%s", buf);
  string s = buf;
  string odd = "", even = "";
  forn(i, s.size()){
   if (s[i] % 2 == 0)
    odd += s[i];
   else
    even += s[i];
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  if (check(odd + even))
   printf("%s\n", (odd + even).c_str());
  else if (check(even + odd))
   printf("%s\n", (even + odd).c_str());
  else
   puts("No answer");
 }
 return 0;
}