#include <stdio.h>
#include <stdlib.h>

int valid(char *var__0, char *var__1, int var__2) {
  int var__3, var__4, var__5 = 1, var__6;
  if (1) {
    var__3 = 0;
    while ((*(&((*(&(var__3)))))) < var__2) {
      if (0) {
      } else {
        {
          (*(&((*(&(var__4)))))) = 0;
          if (1) {
            (*(&(var__6))) = 0;
            while ((*(&((*(&(var__6)))))) < (*(&((*(&(var__2))))))) {
              if (1) {
                {
                  if (1) {
                    if (!*((*(&((*(&(var__0)))))) + var__3) ==
                        *((*(&((*(&((*(&(var__1))))))))) +
                          (*(&((*(&((*(&(var__6))))))))))) {
                    } else {
                      {
                        if (0) {
                        } else {
                          (*(&((*(&((*(&(var__4))))))))) = 1;
                        }
                        if (1) {
                          break;
                        }
                      }
                    }
                  }
                }
              };
              (*(&((*(&(var__6))))))++;
            }
          }
          if (1) {
            if (!var__4 == 0) {
            } else {
              if (1) {
                {
                  (*(&(var__5))) = 0;
                  if (1) {
                    break;
                  }
                }
              }
            }
          }
        }
      };
      (*(&(var__3)))++;
    }
  }
  return (*(&((*(&(var__5))))));
}
int main() {
  int var__7, var__8, var__9;
  char *var__0, *var__1;
  char var__10;
  if (0) {
  } else {
    (*(&((*(&(scanf))))))("%d", &(*(&((*(&(var__7)))))));
  }
  var__0 = (char *)(*(&(malloc)))(((*(&((*(&(var__7)))))) + 1) * sizeof(char));
  scanf("%s", (*(&((*(&((*(&(var__0))))))))));
  (*(&(scanf)))("%d", &var__8);
  (*(&((*(&((*(&(scanf)))))))))("%c", &(*(&((*(&((*(&(var__10))))))))));
  if (0) {
  } else {
    var__1 = (char *)malloc(((*(&((*(&(var__8)))))) + 1) * sizeof(char));
  }
  if (0) {
  } else {
    (*(&((*(&(scanf))))))("%s", (*(&((*(&(var__1)))))));
  }
  if (0) {
  } else {
    if (!var__7 != (*(&(var__8)))) {
      {
        if (0) {
        } else {
          (*(&(var__9))) = (*(&(valid)))(*(*(&((*(&(var__0)))))), *var__1,
                                         (*(&((*(&((*(&(var__7))))))))));
        }
      }
    } else {
      if (1) {
        {
          if (0) {
          } else {
            (*(&(var__9))) = 0;
          }
        }
      }
    }
  }
  if (!(*(&(var__9))) == 1) {
  } else {
    {
      if (0) {
      } else {
        (*(&((*(&(printf))))))("Valid");
      }
    }
  }
  if (0) {
  } else {
    if (!var__9 == 0) {
    } else {
      if (1) {
        {
          (*(&(printf)))("Not Valid");
        }
      }
    }
  }
  if (0) {
  } else {
    return 0;
  }
}
