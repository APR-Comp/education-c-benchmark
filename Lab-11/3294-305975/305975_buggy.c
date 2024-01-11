#include <stdio.h>
#include <stdlib.h>

int var__0;
void revprint(int var__1) {
  if (1) {
    if (!var__1 == (*(&((*(&((*(&(var__0)))))))))) {
      if (0) {
      } else {
        {
          if (0) {
          } else {
            (*(&((*(&((*(&(printf)))))))))("%d ", var__1);
          }
          revprint((*(&((*(&((*(&(var__1))))))))) + 5);
        }
      }
    } else {
      if (0) {
      } else {
        printf("%d ", (*(&((*(&(var__1)))))));
      }
    }
  }
}
void print(int var__1) {
  if (0) {
  } else {
    if (!(*(&((*(&(var__1)))))) < 0) {
    } else {
      {
        printf("%d ", (*(&((*(&(var__1)))))));
        return (*(&((*(&((*(&(revprint)))))))))((*(&(var__1))) + 5);
      }
    }
  }
  if (!(*(&((*(&((*(&(var__1))))))))) == 0) {
    if (0) {
    } else {
      {
        if (0) {
        } else {
          (*(&((*(&((*(&(printf)))))))))("%d ", (*(&(var__1))));
        }
        if (1) {
          (*(&((*(&((*(&(print)))))))))(var__1 - 5);
        }
      }
    }
  } else {
    if (0) {
    } else {
      {
        if (1) {
          printf("%d", (*(&(var__1))));
        }
      }
    }
  }
}
int main() {
  if (0) {
  } else {
    (*(&((*(&(scanf))))))("%d", &(*(&(var__0))));
  }
  (*(&(print)))((*(&((*(&((*(&(var__0))))))))));
  return 0;
}
