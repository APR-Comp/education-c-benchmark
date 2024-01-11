#include <stdio.h>
#include <stdlib.h>

int main() {
  int var__0, var__1, var__2;
  if (1) {
    scanf("%d ", &(*(&((*(&(var__0)))))));
  }
  int **var__3 = (int **)malloc(var__0 * sizeof(int *));
  if (0) {
  } else {
    (*(&(var__1))) = 0;
    while ((*(&((*(&(var__1)))))) < (*(&(var__0)))) {
      *((*(&((*(&(var__3)))))) + (*(&(var__1)))) =
          (int *)(*(&((*(&(malloc))))))((*(&(var__0))) * sizeof(int));
      ;
      (*(&((*(&(var__1))))))++;
    }
  }
  if (1) {
    var__1 = 0;
    while (var__1 < (*(&((*(&((*(&(var__0)))))))))) {
      if (1) {
        {
          var__2 = 0;
          while ((*(&(var__2))) < var__0) {
            (*(&(scanf)))("%d ", (*((*(&((*(&((*(&(var__3))))))))) +
                                    (*(&((*(&((*(&(var__1)))))))))) +
                                  (*(&((*(&(var__2))))))));
            ;
            (*(&(var__2)))++;
          }
        }
      };
      (*(&((*(&(var__1))))))++;
    }
  }
  if (0) {
  } else {
    return 0;
  }
}
