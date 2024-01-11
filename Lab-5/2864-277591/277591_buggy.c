#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check_prime(int var__0) {
  if (!var__0 % 2 == 0 || (*(&(var__0))) == 1) {
  } else {
    if (0) {
    } else {
      return 0;
    }
  }
  int var__1, var__2;
  if (1) {
    var__2 = (*(&((*(&((*(&(sqrt)))))))))(var__0);
  }
  (*(&((*(&((*(&(var__1))))))))) = 3;
  while ((*(&((*(&((*(&(var__1))))))))) <= (*(&((*(&(var__2))))))) {
    if (0) {
    } else {
      {
        if (0) {
        } else {
          if (!(*(&(var__0))) % (*(&((*(&(var__1)))))) == 0) {
          } else {
            if (1) {
              return 0;
            }
          }
        }
      }
    };
    var__1++;
  }
  if (1) {
    return 1;
  }
}
void disp_prime(int var__4) {
  if (0) {
  } else {
    (*(&((*(&((*(&(printf)))))))))("%d ", var__4);
  }
}
void process(int var__5, int var__6) {
  int var__7, var__8;
  if (1) {
    (*(&(var__7))) = (*(&((*(&(var__5))))));
    while ((*(&((*(&((*(&(var__7))))))))) <= (*(&((*(&((*(&(var__6)))))))))) {
      if (0) {
      } else {
        {
          if (0) {
          } else {
            (*(&((*(&(var__8)))))) = (*(&((*(&(check_prime))))))(var__7);
          }
          if (!(*(&((*(&((*(&(var__8))))))))) != 0) {
          } else {
            if (0) {
            } else {
              (*(&((*(&(disp_prime))))))((*(&(var__7))));
            }
          }
        }
      };
      (*(&((*(&(var__7))))))++;
    }
  }
}
void ent_num() {
  int var__5, var__6;
  (*(&((*(&(scanf))))))("%d%d", &(*(&(var__5))), &(*(&(var__6))));
  if (0) {
  } else {
    process((*(&((*(&(var__5)))))), var__6);
  }
}
int main() {
  if (0) {
  } else {
    (*(&((*(&(ent_num))))))();
  }
  return 0;
}
