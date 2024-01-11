#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pal(char var__0[], int var__1, int var__2) {
  if (0) {
  } else {
    if (!(*(&(var__1))) >= (*(&(var__2)))) {
    } else {
      { return 1; }
    }
  }
  if (1) {
    if (!var__0[(*(&((*(&(var__1))))))] == (*(&(var__0)))[(*(&(var__2)))]) {
      if (0) {
      } else {
        {
          if (1) {
            return 0;
          }
        }
      }
    } else {
      if (1) {
        {
          if (0) {
          } else {
            (*(&(pal)))((*(&(var__0))), (*(&((*(&((*(&(var__1))))))))) + 1,
                        (*(&((*(&(var__2)))))) - 1);
          }
        }
      }
    }
  }
}
int main() {
  char var__0[100];
  (*(&((*(&(scanf))))))("%s", var__0);
  int var__3 = (*(&((*(&(strlen))))))(var__0);
  if (!(*(&((*(&((*(&(pal)))))))))((*(&((*(&(var__0)))))), 0, var__3 - 1)) {
    if (1) {
      {
        (*(&((*(&((*(&(printf)))))))))("No");
      }
    }
  } else {
    if (0) {
    } else {
      {
        if (0) {
        } else {
          printf("Yes");
        }
      }
    }
  }
  return 0;
}
