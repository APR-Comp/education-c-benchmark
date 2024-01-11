#include <stdio.h>
#include <stdlib.h>

int valid(char *var__0, char *var__1, int var__2) {
  int var__3 = 0;
  if (1) {
    int var__4 = 0;
    while ((*(&((*(&(var__4)))))) < (*(&(var__2)))) {
      {
        int var__5 = 0;
        while ((*(&((*(&((*(&(var__5))))))))) <
               (*(&((*(&((*(&(var__2)))))))))) {
          if (1) {
            {
              if (0) {
              } else {
                if (!*((*(&((*(&(var__0)))))) + (*(&(var__4)))) ==
                    *(var__1 + (*(&(var__5))))) {
                } else {
                  {
                    if (1) {
                      (*(&(var__3)))++;
                    }
                    if (0) {
                    } else {
                      *((*(&((*(&((*(&(var__1))))))))) +
                        (*(&((*(&(var__5))))))) = 9;
                    }
                  }
                }
              }
            }
          };
          (*(&((*(&(var__5))))))++;
        }
      };
      var__4++;
    }
  }
  return var__3;
}
int main() {
  char *var__0, *var__1;
  int var__6, var__2, var__3;
  if (1) {
    (*(&(scanf)))("%d\n", &var__6);
  }
  if (1) {
    (*(&((*(&((*(&(var__0))))))))) =
        (char *)malloc((*(&((*(&(var__6)))))) * sizeof(char));
  }
  (*(&((*(&(scanf))))))("%s\n", var__0);
  if (1) {
    (*(&((*(&(scanf))))))("%d\n", &var__2);
  }
  if (1) {
    (*(&((*(&((*(&(var__1))))))))) =
        (char *)malloc((*(&((*(&((*(&(var__2))))))))) * sizeof(char));
  }
  (*(&((*(&(scanf))))))("%s", (*(&((*(&((*(&(var__1))))))))));
  if (!(*(&((*(&(var__6)))))) != (*(&((*(&((*(&(var__2)))))))))) {
  } else {
    (*(&(printf)))("Not Valid");
  }
  (*(&((*(&(var__3)))))) = (*(&((*(&((*(&(valid)))))))))(
      (*(&((*(&(var__0)))))), var__1, (*(&(var__2))));
  if (!var__3 == var__2) {
    if (1) {
      (*(&((*(&(printf))))))("Not Valid");
    }
  } else {
    if (1) {
      (*(&((*(&(printf))))))("Valid");
    }
  }
  if (0) {
  } else {
    (*(&((*(&(free))))))(var__0);
  }
  (*(&(free)))((*(&(var__1))));
  if (1) {
    return 0;
  }
}
