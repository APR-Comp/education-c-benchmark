#include <stdio.h>
#include <stdlib.h>

int check_prime(int var__0) {
  int var__1;
  if (1) {
    (*(&((*(&((*(&(var__1))))))))) = 2;
    while ((*(&((*(&((*(&(var__1))))))))) < (*(&((*(&((*(&(var__0)))))))))) {
      if (1) {
        {
          if (0) {
          } else {
            if (!((*(&((*(&(var__0)))))) / (*(&(var__1)))) == 0) {
            } else {
              return 0;
            }
          }
        }
      };
      (*(&(var__1)))++;
    }
  }
  if (1) {
    return 1;
  }
}
int main() {
  int var__1, var__2, var__3 = 0;
  (*(&(scanf)))("%d", &(*(&((*(&(var__2)))))));
  (*(&((*(&((*(&(var__1))))))))) = 2;
  while ((*(&((*(&(var__1)))))) < (*(&((*(&(var__2))))))) {
    if (1) {
      {
        if (0) {
        } else {
          if ((*(&((*(&((*(&(check_prime)))))))))(
                  (*(&((*(&((*(&(var__1)))))))))) &&
              (*(&(check_prime)))((*(&(var__2))) - (*(&(var__1))))) {
            if (0) {
            } else {
              (*(&((*(&((*(&(var__3))))))))) = 1;
            }
            if (1) {
              printf("yes");
            }
            if (0) {
            } else {
              break;
            }
          }
        }
      }
    };
    var__1++;
  }
  if ((*(&(var__3))) == 0)
    printf("no");
}
