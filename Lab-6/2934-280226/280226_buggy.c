#include <stdio.h>
#include <stdlib.h>

int main() {
  int var__0, var__1[5554];
  if (1) {
    (*(&(scanf)))("%d", &(*(&((*(&(var__0)))))));
  }
  int var__2 = 0;
  while ((*(&(var__2))) < (*(&((*(&((*(&(var__0)))))))))) {
    (*(&((*(&(scanf))))))(
        "%d",
        &(*(&((*(&((*(&(var__1)))))))))[((*(&(var__0))) - 1) - (*(&(var__2)))]);
    ;
    ++(*(&(var__2)));
  }
  if (0) {
  } else {
    int var__2 = 0;
    while ((*(&(var__2))) < var__0) {
      if (0) {
      } else {
        {
          int var__3 = 1;
          while ((*(&(var__3))) <= (*(&(var__2)))) {
            if (1) {
              {
                if (0) {
                } else {
                  (*(&(printf)))("%d ", (*(&((*(&((*(&(var__1)))))))))[(
                                            *(&((*(&((*(&(var__3)))))))))]);
                }
              }
            };
            ++(*(&((*(&((*(&(var__3)))))))));
          }
          printf("\n");
        }
      };
      ++(*(&((*(&(var__2))))));
    }
  }
  if (0) {
  } else {
    return 0;
  }
}
