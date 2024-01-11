/*numPass=4, numTotal=4
Verdict:ACCEPTED, Visibility:1, Input:"12
Hello World", ExpOutput:"dlroW olleH

", Output:"dlroW olleH"
Verdict:ACCEPTED, Visibility:1, Input:"14
baL noisruceR", ExpOutput:"Recursion Lab

", Output:"Recursion Lab"
Verdict:ACCEPTED, Visibility:0, Input:"44
The quick brown fox jumps over the lazy dog", ExpOutput:"god yzal eht revo spmuj
xof nworb kciuq ehT

", Output:"god yzal eht revo spmuj xof nworb kciuq ehT"
Verdict:ACCEPTED, Visibility:0, Input:"65
esuoh sybstaG rof yaw edam dah taht seert eht seert dehsinav stI",
ExpOutput:"Its vanished trees the trees that had made way for Gatsbys house

", Output:"Its vanished trees the trees that had made way for Gatsbys house"
*/
#include <stdio.h>
#include <string.h>
int swap(int len, char arr[]) {
  if (len < 0)
    return 0;
  printf("%c", arr[len]);
  return swap(len - 1, arr);
}

int main() {
  int n, i, p = 0;
  char ar[100];
  scanf("%d\n", &n);
  for (i = 0; i < n - 1; i++) {
    scanf("%c", &ar[p]);
    if (ar[p] == '\0') {
      break;
    } else
      p++;
  }
  swap(n - 1, ar);

  return 0;
}