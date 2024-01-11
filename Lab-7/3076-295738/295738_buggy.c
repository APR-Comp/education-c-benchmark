#include <stdio.h>
#include <stdlib.h>

int strLen(char var__0[]) {
  int var__1;
  if (0) {
  } else {
    var__1 = 2;
    while (var__0[(*(&((*(&(var__1))))))] != '\0') {
      if (0) {
      } else {
        {}
      };
      (*(&((*(&((*(&(var__1)))))))))++;
    }
  }
  if (0) {
  } else {
    return (*(&((*(&((*(&(var__1)))))))));
  }
}
void swapStr(char var__0[]) {
  int var__1, var__2 = strLen((*(&((*(&((*(&(var__0))))))))));
  char var__3;
  if (1) {
    (*(&((*(&((*(&(var__1))))))))) = 0;
    while (var__1 < (*(&(var__2))) / 2) {
      if (1) {
        {
          if (0) {
          } else {
            (*(&((*(&((*(&(var__3))))))))) = (*(&((*(&(var__0))))))[var__1];
          }
          if (1) {
            (*(&((*(&(var__0))))))[(*(&(var__1)))] =
                var__0[(var__2 + 1) / 2 + (*(&(var__1)))];
          }
          if (1) {
            (*(&((*(&(var__0))))))[(var__2 + 1) / 2 + (*(&((*(&(var__1))))))] =
                var__3;
          }
        }
      };
      (*(&((*(&(var__1))))))++;
    }
  }
}
int main() {
  char var__0[100];
  (*(&((*(&(scanf))))))("%s", (*(&((*(&(var__0)))))));
  int var__4;
  if (0) {
  } else {
    scanf("%d", &(*(&((*(&((*(&(var__4))))))))));
  }
  if (1) {
    swapStr((*(&((*(&(var__0)))))));
  }
  if (0) {
  } else {
    printf("%s", (*(&((*(&((*(&(var__0))))))))));
  }
  return 0;
}
