#include <stdio.h>
#include <stdlib.h>

int main() {
  int var__0, var__1;
  int var__2;
  if (1) {
    (*(&((*(&((*(&(scanf)))))))))("%d", &(*(&(var__2))));
  }
  if (1) {
    (*(&((*(&(var__0)))))) = 1;
    while ((*(&((*(&((*(&(var__0))))))))) <= (*(&(var__2)))) {
      if (1) {
        {
          var__1 = (*(&((*(&(var__2))))));
          while (var__1 >= 1) {
            {
              if (0) {
              } else {
                if ((*(&((*(&((*(&(var__0))))))))) == var__1)
                  printf("*");
                else if (1) {
                  printf("%d ", (*(&((*(&((*(&(var__1))))))))));
                }
              }
            };
            (*(&(var__1)))--;
          }
          (*(&((*(&((*(&(printf)))))))))("\n");
        }
      };
      var__0++;
    }
  }
  return 0;
}
