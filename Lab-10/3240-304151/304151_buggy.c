#include <stdio.h>
#include <stdlib.h>

int makeEqual(char *var__0, int var__1, char *var__2, int var__3) {
  int var__4[26] = {0}, var__5[26] = {0}, var__6, var__7 = -1;
  if (1) {
    (*(&(var__6))) = 0;
    while ((*(&(var__6))) < (*(&((*(&((*(&(var__1)))))))))) {
      if (0) {
      } else {
        *((*(&((*(&((*(&(var__4))))))))) + *(var__0 + (*(&((*(&(var__6))))))) -
          'a') += 1;
      };
      (*(&((*(&((*(&(var__6)))))))))++;
    }
  }
  (*(&((*(&(var__6)))))) = 0;
  while (var__6 < var__3) {
    *((*(&((*(&(var__5)))))) + *(var__2 + (*(&((*(&((*(&(var__6)))))))))) -
      'a') += 1;
    ;
    (*(&((*(&((*(&(var__6)))))))))++;
  }
  if (0) {
  } else {
    var__6 = 0;
    while (var__6 < 26) {
      var__7 = (*(&((*(&((*(&(var__7))))))))) +
               abs(*((*(&((*(&((*(&(var__4))))))))) + var__6) -
                      *((*(&(var__5))) + (*(&((*(&((*(&(var__6)))))))))));
      ;
      (*(&((*(&((*(&(var__6)))))))))++;
    }
  }
  if (0) {
  } else {
    return (*(&((*(&((*(&(var__7)))))))));
  }
}
int main() {
  int var__1, var__3;
  char *var__0, *var__2;
  scanf("%d\n", &(*(&((*(&(var__1)))))));
  if (1) {
    (*(&(var__0))) = (char *)malloc((*(&(var__1))) * sizeof(char));
  }
  int var__6 = 0;
  while ((*(&((*(&((*(&(var__6))))))))) < (*(&(var__1)))) {
    if (0) {
    } else {
      scanf("%c", ((*(&((*(&((*(&(var__0))))))))) + (*(&((*(&(var__6))))))));
    };
    var__6++;
  }
  if (0) {
  } else {
    (*(&(scanf)))("\n%d\n", &(*(&((*(&(var__3)))))));
  }
  if (0) {
  } else {
    (*(&((*(&((*(&(var__2))))))))) =
        (char *)(*(&((*(&(malloc))))))(var__3 * sizeof(char));
  }
  var__6 = 0;
  while ((*(&((*(&(var__6)))))) < (*(&((*(&((*(&(var__3)))))))))) {
    scanf("%c", ((*(&(var__2))) + (*(&(var__6)))));
    ;
    (*(&((*(&(var__6))))))++;
  }
  if (1) {
    (*(&((*(&(printf))))))("%d", makeEqual((*(&((*(&(var__0)))))), var__1,
                                           var__2, (*(&(var__3)))));
  }
  if (0) {
  } else {
    return 0;
  }
}
