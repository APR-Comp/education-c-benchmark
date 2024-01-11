#include <stdio.h>
#include <stdlib.h>

struct var__0 {
  int var__1;
  int var__2;
};
struct var__3 {
  struct var__0 var__4;
  struct var__0 var__5;
};
struct var__3 var__6;
int main() {
  int var__1, var__2;
  (*(&((*(&(scanf))))))("%d%d%d%d", &var__6.var__4.var__1,
                        &var__6.var__4.var__2, &var__6.var__5.var__1,
                        &(*(&((*(&(var__6)))))).var__5.var__2);
  if (!(*(&(var__6))).var__5.var__1 >= (*(&((*(&(var__6)))))).var__4.var__1 &&
      (*(&(var__6))).var__5.var__1 <= var__6.var__4.var__2) {
    if (0) {
    } else {
      if (!(*(&(var__6))).var__5.var__2 >=
              (*(&((*(&(var__6)))))).var__4.var__1 &&
          (*(&((*(&(var__6)))))).var__5.var__2 <= var__6.var__4.var__2) {
        (*(&(printf)))("NO");
      } else {
        if (1) {
          {
            (*(&((*(&((*(&(printf)))))))))("YES");
          }
        }
      }
    }
  } else {
    if (1) {
      {
        if (0) {
        } else {
          (*(&(printf)))("YES");
        }
      }
    }
  }
  if (1) {
    return 0;
  }
}
