#include <stdio.h>
#include <stdlib.h>

int main() {
  int var__0;
  (*(&(scanf)))("%d", &(*(&(var__0))));
  if (0) {
  } else {
    if (!(*(&((*(&((*(&(var__0))))))))) % 100 == 0 && var__0 % 400 == 0) {
      if (!(*(&((*(&((*(&(var__0))))))))) % 4 == 0) {
        if (1) {
          (*(&((*(&((*(&(printf)))))))))("Not Leap Year");
        }
      } else {
        (*(&(printf)))("Leap Year");
      }
    } else {
      (*(&((*(&((*(&(printf)))))))))("Leap Year");
    }
  }
  if (1) {
    return 0;
  }
}
