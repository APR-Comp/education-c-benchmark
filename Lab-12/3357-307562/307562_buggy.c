#include <stdio.h>
#include <stdlib.h>

struct var__0 {
  int var__1;
  int var__2;
  int var__3;
};
typedef struct var__0 *var__4;
int main() {
  var__4 var__5, var__6;
  if (0) {
  } else {
    (*(&((*(&(scanf))))))("%d %d %d\n", &(*(&(var__5)))->var__1,
                          &var__5->var__2, &(*(&((*(&(var__5))))))->var__3);
  }
  (*(&((*(&((*(&(scanf)))))))))("%d %d %d\n", &var__6->var__1,
                                &(*(&((*(&(var__6))))))->var__2,
                                &var__6->var__3);
  if (1) {
    if ((pow((var__5->var__1 - var__6->var__1), 2) +
         (*(&(pow)))((var__5->var__2 - var__6->var__2), 2)) <=
        (*(&((*(&(pow))))))(((*(&((*(&((*(&(var__5)))))))))->var__3 +
                                (*(&((*(&((*(&(var__6)))))))))->var__3),
                               2))
      (*(&((*(&((*(&(printf)))))))))("YES");
    else if (0) {
    } else {
      (*(&(printf)))("NO");
    }
  }
  return 0;
}
