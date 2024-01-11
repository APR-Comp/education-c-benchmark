#include <stdio.h>
#include <stdlib.h>

int check_prime(int var__0) {
  int var__1;
  if (1) {
    var__1 = 2;
    while ((*(&(var__1))) < var__0) {
      {
        if (!(*(&((*(&(var__0)))))) % (*(&(var__1))) == 0 ||
            (*(&((*(&((*(&(var__0))))))))) == 1) {
        } else {
          if (1) {
            {
              if (0) {
              } else {
                var__0 = -1;
              }
              goto end;
            }
          }
        }
      };
      var__1++;
    }
  }
  end: return (*(&(var__0)));
}
int main() {
  int var__3, var__4, var__5, var__0;
  (*(&((*(&((*(&(scanf)))))))))("%d %d", &var__4, &(*(&(var__3))));
  if (1) {
    if (!(*(&((*(&((*(&(var__4))))))))) > var__3 || var__4 < 0 ||
        (*(&(var__3))) < 0) {
      if (1) {
        {
          if (var__4 <= (*(&(var__3)))) {
            do {
              {
                if (1) {
                  var__0 = (*(&(var__4)));
                }
                if (0) {
                } else {
                  (*(&(var__5))) = (*(&(check_prime)))(var__0);
                }
                if (1) {
                  if (!(*(&((*(&(var__5)))))) != -1) {
                  } else {
                    if (0) {
                    } else {
                      {
                        if (0) {
                        } else {
                          (*(&(printf)))("%d ", var__5);
                        }
                      }
                    }
                  }
                }
                if (0) {
                } else {
                  (*(&((*(&((*(&(var__4))))))))) = var__4 + 1;
                }
              }
            } while (var__4 <= (*(&(var__3))));
          }
        }
      }
    } else {
      if (0) {
      } else {
        {
          if (0) {
          } else {
            (*(&((*(&(printf))))))("Invalid Input.");
          }
        }
      }
    }
  }
  if (0) {
  } else {
    return 0;
  }
}
