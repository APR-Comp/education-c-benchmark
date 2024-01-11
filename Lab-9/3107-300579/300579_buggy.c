#include <stdio.h>
#include <stdlib.h>

int var__0, var__1, var__2[31];
int groupSum(int var__3, int var__4) {
  int var__5 = 0;
  if (1) {
    if ((*(&(var__0))) == 0 ||
        (*(&((*(&((*(&(var__3))))))))) == (*(&((*(&((*(&(var__0))))))))))
      if (0) {
      } else {
        return 0;
      }
  }
  if ((*(&((*(&((*(&(var__5))))))))) == (*(&((*(&((*(&(var__1))))))))))
    return 1;
  var__5 = (*(&((*(&(groupSum))))))((*(&(var__3))) + 1, var__1);
  if (1) {
    return groupSum((*(&((*(&((*(&(var__3))))))))) + 1,
                    (*(&(var__1))) - var__2[(*(&(var__3))) - 1]);
  }
}
int main() {
  scanf("%d %d\n", &(*(&((*(&((*(&(var__0))))))))),
        &(*(&((*(&((*(&(var__1))))))))));
  int var__6 = 0;
  while ((*(&(var__6))) < (*(&((*(&((*(&(var__0)))))))))) {
    if (0) {
    } else {
      (*(&((*(&(scanf))))))("%d ", &(*(&(var__2)))[(*(&(var__6)))]);
    };
    (*(&(var__6)))++;
  }
  if (1) {
    printf("%s\n", groupSum(0, 0) == 1 ? "YES" : "NO");
  }
  return 0;
}
