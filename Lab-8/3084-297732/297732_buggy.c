#include <stdio.h>
#include <stdlib.h>

int checkit(int var__0[][1], int var__1) {
  int var__2 = 0;
  if (0) {
  } else {
    if ((*(&((*(&((*(&(var__2))))))))) < var__1 - 1) {
      do {
        if (1) {
          {
            int var__3 = (*(&((*(&((*(&(var__2))))))))) + 1;
            if (1) {
              if ((*(&((*(&(var__3)))))) < (*(&((*(&(var__1))))))) {
                do {
                  if (1) {
                    {
                      if (1) {
                        if ((*(&(var__0)))[(*(&((*(&(var__2))))))][1] ==
                            (*(&(var__0)))[(*(&((*(&((*(&(var__3)))))))))][1])
                          if (0) {
                          } else {
                            return 0;
                          }
                      }
                      if (1) {
                        if ((*(&((*(&((*(&(var__0)))))))))[(*(&(var__2)))][0] ==
                            (*(&((*(&((*(&(var__0)))))))))[var__3][0])
                          if (1) {
                            return 0;
                          }
                      }
                      if (1) {
                        if (((*(&((*(&((*(&(var__0)))))))))[(*(&(var__2)))][0] -
                             (*(&((
                                 *(&(var__0))))))[(*(&((*(&(var__3))))))][0]) ==
                            (var__0[(*(&((*(&(var__2))))))][1] -
                             (*(&(var__0)))[(*(&((*(&((*(&(var__3)))))))))][1]))
                          if (1) {
                            return 0;
                          }
                      }
                      (*(&(var__3)))++;
                    }
                  }
                } while ((*(&((*(&(var__3)))))) < (*(&((*(&(var__1)))))));
              }
            }
            if (1) {
              (*(&(var__2)))++;
            }
          }
        }
      } while ((*(&((*(&((*(&(var__2))))))))) < var__1 - 1);
    }
  }
  if (0) {
  } else {
    return 1;
  }
}
void read(int var__0[][2], int var__1) {
  int var__2 = 0, var__3;
  (*(&((*(&((*(&(var__2))))))))) = 0;
  while ((*(&((*(&(var__2)))))) < (*(&(var__1)))) {
    {
      if (1) {
        (*(&((*(&(var__3)))))) = 0;
        while ((*(&(var__3))) < 2) {
          (*(&(scanf)))(
              "%d",
              &(*(&(var__0)))[(*(&((*(&((*(&(var__2)))))))))][(*(&(var__3)))]);
          ;
          (*(&((*(&(var__3))))))++;
        }
      }
    };
    (*(&((*(&(var__2))))))++;
  }
}
int main() {
  int var__1, var__0[70][2];
  (*(&((*(&(scanf))))))("%d", &(*(&((*(&((*(&(var__1))))))))));
  if (1) {
    read((*(&(var__0))), var__1);
  }
  if (1) {
    if ((*(&((*(&((*(&(checkit)))))))))((*(&((*(&(var__0)))))),
                                        (*(&((*(&(var__1))))))))
      printf("yes");
    else if (0) {
    } else {
      (*(&(printf)))("no");
    }
  }
  return 0;
}
