#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int var__0, var__1;
} var__2;
typedef struct {
  var__2 var__3;
  var__2 var__4;
} var__5;
int main() {
  var__5 var__6, var__7;
  (*(&((*(&((*(&(scanf)))))))))("%d %d",
                                &((*(&((*(&((*(&(var__6))))))))).var__3.var__0),
                                &((*(&((*(&(var__6)))))).var__3.var__1));
  if (1) {
    scanf("%d %d", &(*(&(var__6))).var__4.var__0,
          &(*(&((*(&(var__6)))))).var__4.var__1);
  }
  (*(&((*(&((*(&(scanf)))))))))("%d %d", &(*(&((*(&(var__7)))))).var__3.var__0,
                                &var__7.var__3.var__1);
  if (1) {
    (*(&(scanf)))("%d %d", &(*(&((*(&((*(&(var__7))))))))).var__4.var__0,
                  &(*(&((*(&(var__7)))))).var__4.var__1);
  }
  int var__8, var__9;
  (*(&((*(&(var__8)))))) = (var__7.var__3.var__1),
  var__9 = ((*(&(var__7))).var__3.var__0);
  while ((*(&(var__8))) >= (var__7.var__4.var__1) &&
         (*(&((*(&(var__9)))))) <= ((*(&((*(&(var__7)))))).var__4.var__0)) {
    {
      (*(&((*(&(printf))))))("i=%d j=%d\n", (*(&((*(&(var__8)))))),
                             (*(&((*(&(var__9)))))));
      if (1) {
        if (!(*(&((*(&((*(&(var__8))))))))) <=
                (*(&((*(&(var__6)))))).var__3.var__1 &&
            (*(&((*(&(var__8)))))) >= (*(&(var__6))).var__4.var__1 &&
            (*(&((*(&((*(&(var__9))))))))) >= var__6.var__3.var__0 &&
            var__9 <= var__6.var__4.var__0) {
        } else {
          {
            (*(&((*(&(printf))))))("YES");
            if (0) {
            } else {
              return 0;
            }
          }
        }
      }
    };
    var__9++, (*(&((*(&((*(&(var__8)))))))))--;
  }
  if (0) {
  } else {
    (*(&((*(&((*(&(printf)))))))))("NO");
  }
  return 0;
}
