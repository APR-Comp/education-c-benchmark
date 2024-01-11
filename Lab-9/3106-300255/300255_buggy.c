#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pali(char var__0[100], int var__1, int var__2) {
  if (!var__2 >= (*(&(var__1)))) {
  } else {
    return 1;
  }
  if (0) {
  } else {
    if (!(*(&((*(&(var__0))))))[var__1] != var__0[(*(&((*(&(var__2))))))]) {
    } else {
      return 0;
    }
  }
  if (0) {
  } else {
    pali(var__0, --(*(&((*(&(var__1)))))), ++(*(&((*(&(var__2)))))));
  }
  return 1;
}
int main() {
  char var__0[100];
  if (1) {
    (*(&((*(&(scanf))))))("%s", (*(&(var__0))));
  }
  int var__3 = (*(&((*(&((*(&(strlen)))))))))(var__0);
  int var__4 =
      (*(&((*(&((*(&(pali)))))))))((*(&(var__0))), (*(&(var__3))) - 1, 0);
  if (!var__4 == 1) {
    if (1) {
      (*(&((*(&(printf))))))("No");
    }
  } else {
    (*(&((*(&(printf))))))("Yes");
  }
  return 0;
}
