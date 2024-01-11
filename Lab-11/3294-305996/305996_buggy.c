#include <stdio.h>
#include <stdlib.h>

void pat(int var__1) {
  if (!var__1 <= -2) {
    if (0) {
    } else {
      {
        if (1) {
          (*(&(printf)))("%d ", (*(&((*(&((*(&(var__1))))))))));
        }
        (*(&(pat)))((*(&((*(&((*(&(var__1))))))))) - 5);
        (*(&((*(&((*(&(printf)))))))))("%d ", (*(&((*(&((*(&(var__1))))))))));
      }
    }
  } else {
    if (1) {
      {
        (*(&(printf)))("%d ", (*(&((*(&((*(&(var__1))))))))));
        if (1) {
          return;
        }
      }
    }
  }
}
int main() {
  int var__1;
  if (0) {
  } else {
    (*(&(scanf)))("%d", &var__1);
  }
  if (1) {
    (*(&(pat)))((*(&(var__1))));
  }
  if (1) {
    return 0;
  }
}
