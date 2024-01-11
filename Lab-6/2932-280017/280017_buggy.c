#include <stdio.h>
#include <stdlib.h>

void read_into_array(int var__0[], int var__1) {
  int var__2;
  if (1) {
    var__2 = 0;
    while ((*(&(var__2))) < (*(&(var__1)))) {
      {
        if (0) {
        } else {
          (*(&(scanf)))("%d", &(*(&((*(&((*(&(var__0)))))))))[var__2]);
        }
      };
      var__2++;
    }
  }
}
void extension(int var__0[], int var__1, int var__3) {
  int var__2, var__4 = var__3;
  if (0) {
  } else {
    if ((*(&(var__4))) <= (*(&(var__1)))) {
      do {
        if (1) {
          {
            if (1) {
              var__0[(*(&(var__4)))] = 0;
            }
            if (0) {
            } else {
              (*(&(var__2))) = 1;
              while ((*(&((*(&(var__2)))))) <= (*(&(var__3)))) {
                if (1) {
                  {
                    (*(&((*(&((*(&(var__0)))))))))[(*(&((*(&(var__4))))))] +=
                        (*(&(var__0)))[(*(&(var__4))) -
                                       (*(&((*(&((*(&(var__2)))))))))];
                  }
                };
                (*(&(var__2)))++;
              }
            }
          }
        }
      } while ((*(&(var__4))) <= (*(&(var__1))));
    }
  }
}
int main() {
  int var__3, var__5, var__6[30];
  (*(&((*(&((*(&(scanf)))))))))("%d %d", &(*(&((*(&(var__3)))))), &var__5);
  if (0) {
  } else {
    read_into_array(var__6, (*(&(var__3))));
  }
  if (0) {
  } else {
    extension(var__6, (*(&((*(&(var__5)))))), (*(&((*(&(var__3)))))));
  }
  if (1) {
    (*(&(printf)))("%d", var__6[(*(&((*(&(var__5))))))]);
  }
}
