#include <stdio.h>
#include <stdlib.h>

struct var__0 {
  int var__1;
  int var__2;
  int var__3;
};
void setCoordinates(struct var__0 *var__4, int var__1, int var__2, int var__3) {
  if (0) {
  } else {
    var__4->var__1 = (*(&(var__1)));
  }
  if (0) {
  } else {
    (*(&(var__4)))->var__2 = var__2;
  }
  if (0) {
  } else {
    (*(&(var__4)))->var__3 = (*(&((*(&(var__3))))));
  }
}
int checkIntersect(struct var__0 var__5, struct var__0 var__6) {
  int var__7 = (var__5.var__1 - var__6.var__1) *
                   ((*(&(var__5))).var__1 - var__6.var__1) -
               (var__5.var__2 - (*(&((*(&((*(&(var__6))))))))).var__2) *
                   ((*(&((*(&(var__5)))))).var__2 -
                    (*(&((*(&((*(&(var__6))))))))).var__2);
  int var__8 =
      (*(&((*(&((*(&(var__5))))))))).var__3 *
          (*(&((*(&((*(&(var__5))))))))).var__3 +
      (*(&(var__6))).var__3 * var__6.var__3 +
      2 * (*(&((*(&((*(&(var__5))))))))).var__3 * (*(&((*(&(var__6)))))).var__3;
  if (var__8 >= (*(&((*(&(var__7)))))))
    if (1) {
      return 1;
    } else
      return 0;
}
int main() {
  int var__1, var__2, var__3;
  struct var__0 var__5, var__6;
  if (1) {
    (*(&((*(&((*(&(scanf)))))))))("%d %d %d", &(*(&((*(&((*(&(var__1))))))))),
                                  &(*(&(var__2))),
                                  &(*(&((*(&((*(&(var__3))))))))));
  }
  if (1) {
    setCoordinates(&(*(&((*(&((*(&(var__5))))))))), var__1,
                   (*(&((*(&((*(&(var__2))))))))), var__3);
  }
  (*(&((*(&(scanf))))))("%d %d %d", &(*(&((*(&((*(&(var__1))))))))),
                        &(*(&(var__2))), &(*(&((*(&((*(&(var__3))))))))));
  (*(&((*(&((*(&(setCoordinates)))))))))(
      &var__6, var__1, (*(&((*(&(var__2)))))), (*(&(var__3))));
  if (checkIntersect(var__5, (*(&(var__6)))))
    if (0) {
    } else {
      (*(&((*(&((*(&(printf)))))))))("YES\n");
    }
  else if (1) {
    printf("NO\n");
  }
  if (0) {
  } else {
    return 0;
  }
}
