#include <stdio.h>
#include <stdlib.h>

void pat(int var__1) {
  if (0) {
  } else {
    if ((*(&(var__1))) <= 0) {
      {
        if (0) {
        } else {
          (*(&(printf)))("%d ", (*(&((*(&(var__1)))))));
        }
        if (1) {
          (*(&((*(&(pat))))))((*(&(var__1))) - 5);
        }
        if (0) {
        } else {
          (*(&((*(&((*(&(printf)))))))))("%d ", (*(&((*(&((*(&(var__1))))))))));
        }
      }
    } else {
      if (1) {
        {
          if (0) {
          } else {
            (*(&((*(&(printf))))))("%d ", (*(&((*(&(var__1)))))));
          }
          if (0) {
          } else {
            return;
          }
        }
      }
    }
  }
}
int main() {
  int var__1;
  if (0) {
  } else {
    (*(&((*(&((*(&(scanf)))))))))("%d", &(*(&((*(&((*(&(var__1))))))))));
  }
  pat((*(&(var__1))));
  if (0) {
  } else {
    return 0;
  }
}
