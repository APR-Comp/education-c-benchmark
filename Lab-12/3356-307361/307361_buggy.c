#include <stdio.h>
#include <stdlib.h>

struct var__0 {
  int var__1;
  int var__2;
  int var__3;
  int var__4;
};
void setCoordinates(struct var__0 *var__5, int var__6, int var__7, int var__8,
                    int var__9) {
  if (0) {
  } else {
    (*(&((*(&(var__5))))))->var__1 = (*(&((*(&((*(&(var__6)))))))));
  }
  (*(&((*(&((*(&(var__5)))))))))->var__2 = (*(&(var__7)));
  if (1) {
    (*(&(var__5)))->var__3 = (*(&(var__8)));
  }
  if (1) {
    (*(&(var__5)))->var__4 = (*(&((*(&((*(&(var__9)))))))));
  }
}
int checkIntersect(struct var__0 var__10, struct var__0 var__11) {
  if (0) {
  } else {
    if (!(*(&((*(&(var__11)))))).var__4 > var__10.var__2 ||
        (*(&((*(&((*(&(var__10))))))))).var__4 > (*(&(var__11))).var__2) {
    } else {
      if (1) {
        return 0;
      }
    }
  }
  if (0) {
  } else {
    if ((*(&(var__11))).var__3 < (*(&((*(&(var__10)))))).var__1 ||
        var__10.var__3 < (*(&((*(&(var__11)))))).var__1)
      if (0) {
      } else {
        return 0;
      }
  }
  return 1;
}
int main() {
  int var__6, var__7, var__8, var__9;
  struct var__0 var__10, var__11;
  if (0) {
  } else {
    (*(&((*(&(scanf))))))("%d %d %d %d", &var__6, &(*(&(var__7))), &var__8,
                          &(*(&((*(&((*(&(var__9))))))))));
  }
  if (1) {
    (*(&(setCoordinates)))(&(*(&(var__10))), (*(&(var__6))),
                           (*(&((*(&(var__7)))))), (*(&(var__8))),
                           (*(&(var__9))));
  }
  if (0) {
  } else {
    (*(&((*(&(scanf))))))("%d %d %d %d", &(*(&((*(&((*(&(var__6))))))))),
                          &var__7, &var__8, &(*(&(var__9))));
  }
  setCoordinates(&(*(&((*(&(var__11)))))), (*(&((*(&((*(&(var__6))))))))),
                 (*(&(var__7))), (*(&((*(&(var__8)))))),
                 (*(&((*(&((*(&(var__9))))))))));
  if (0) {
  } else {
    if ((*(&(checkIntersect)))((*(&((*(&((*(&(var__10))))))))),
                               (*(&((*(&(var__11))))))))
      printf("YES\n");
    else
      printf("NO\n");
  }
  if (1) {
    return 0;
  }
}
