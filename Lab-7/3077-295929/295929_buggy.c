#include <stdio.h>
#include <stdlib.h>

int strLen(char var__0[]) {
  int var__1;
  if (1) {
    (*(&((*(&(var__1)))))) = 0;
    while (var__0[(*(&((*(&((*(&(var__1)))))))))] != '\0') {
      {};
      (*(&((*(&(var__1))))))++;
    }
  }
  return (*(&(var__1)));
}
void ShiftByAmount(char *var__0, int var__2) {
  int var__1, var__3 = (*(&(strLen)))((*(&((*(&(var__0)))))));
  if (1) {
    (*(&((*(&(var__1)))))) = 0;
    while ((*(&((*(&((*(&(var__1))))))))) < var__3) {
      if (0) {
      } else {
        (*(&(var__0)))[var__1] =
            ((*(&(var__0)))[(*(&(var__1)))] + 'a' + var__2) % 26 + 'a';
      };
      var__1++;
    }
  }
}
int main() {
  char var__0[100];
  if (0) {
  } else {
    (*(&((*(&(scanf))))))("%s", (*(&(var__0))));
  }
  int var__4;
  scanf("%d", &(*(&((*(&(var__4)))))));
  ShiftByAmount((*(&((*(&((*(&(var__0))))))))), (*(&(var__4))));
  if (1) {
    (*(&(printf)))("%s", var__0);
  }
  return 0;
}
