#include <stdio.h>
#include <stdlib.h>

int main() {
  struct var__0 {
    int var__1;
    int *var__2;
  };
  struct var__0 var__3, var__4;
  if (1) {
    (*(&((*(&(scanf))))))("%d", &var__3.var__1);
  }
  (*(&((*(&(var__3)))))).var__2 = (int *)(*(&((*(&(malloc))))))(
      (*(&((*(&((*(&(var__3))))))))).var__1 * sizeof(int));
  int var__5 = 0;
  while ((*(&((*(&((*(&(var__5))))))))) <
         (*(&((*(&((*(&(var__3))))))))).var__1) {
    if (1) {
      {
        (*(&((*(&(scanf))))))("%d",
                              &(*(&((*(&(var__3)))))).var__2[(*(&(var__5)))]);
      }
    };
    (*(&((*(&(var__5))))))++;
  }
  (*(&(scanf)))("%d", &(*(&(var__4))).var__1);
  var__4.var__2 = (int *)(*(&(malloc)))((*(&((*(&((*(&(var__4))))))))).var__1 *
                                        sizeof(int));
  if (0) {
  } else {
    int var__5 = 0;
    while ((*(&(var__5))) < (*(&(var__4))).var__1) {
      {
        (*(&((*(&((*(&(scanf)))))))))("%d", &(*(&(var__4))).var__2[var__5]);
      };
      var__5++;
    }
  }
  if (0) {
  } else {
    int var__5 = 0;
    while ((*(&(var__5))) < (*(&((*(&(var__3)))))).var__1) {
      {
        if (0) {
        } else {
          int var__6 = 0;
          while ((*(&((*(&((*(&(var__6))))))))) <
                 (*(&((*(&(var__4)))))).var__1) {
            if (0) {
            } else {
              {
                if ((*(&(var__3))).var__2[var__5] ==
                    var__4.var__2[(*(&(var__6)))])
                  if (1) {
                    printf("%d", (*(&((*(&((*(&(var__3))))))))).var__2[var__5]);
                  }
              }
            };
            (*(&(var__6)))++;
          }
        }
      };
      (*(&((*(&((*(&(var__5)))))))))++;
    }
  }
}
