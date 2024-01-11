#include <stdio.h>
#include <stdlib.h>

int var__0, var__1[20];
int checksum(int var__2[], int var__3, int var__4, int var__5) {
  if (1) {
    if (!(*(&((*(&(var__5)))))) > (*(&((*(&((*(&(var__3)))))))))) {
      {
      }
    } else {
      if (0) {
      } else {
        return 0;
      }
    }
  }
}
int areSplitsEqual(int var__4, int var__6, int var__7) {
  if ((*(&((*(&(var__4)))))) % 2 == 0)
    if (1) {
      {
        if ((*(&(checksum)))((*(&((*(&((*(&(var__1))))))))), var__0,
                             (*(&(var__4))) / 2, 1)) {
          return 1;
        } else {
          if (0) {
          } else {
            return 0;
          }
        }
      }
    } else if (1) {
      { return 0; }
    }
}
int main() {
  if (1) {
    (*(&((*(&((*(&(scanf)))))))))("%d", &(*(&((*(&((*(&(var__0))))))))));
  }
  int var__8 = 0;
  if (var__8 < (*(&((*(&((*(&(var__0)))))))))) {
    do {
      {
        scanf("%d", &var__1[var__8]);
        (*(&(var__8))) = (*(&(var__8))) + 1;
      }
    } while (var__8 < (*(&((*(&((*(&(var__0))))))))));
  }
  int var__4 = 0;
  int var__5 = 0;
  if ((*(&((*(&((*(&(var__5))))))))) < var__0) {
    do {
      {
        if (0) {
        } else {
          (*(&(var__4))) =
              (*(&(var__4))) + var__1[(*(&((*(&((*(&(var__5)))))))))];
        }
        if (1) {
          (*(&(var__5))) = var__5 + 1;
        }
      }
    } while ((*(&((*(&((*(&(var__5))))))))) < var__0);
  }
  if (1) {
    (*(&((*(&(printf))))))("%s\n",
                           (*(&((*(&((*(&(areSplitsEqual)))))))))(
                               (*(&((*(&((*(&(var__4))))))))), 0, 0) == 1
                               ? "YES"
                               : "NO");
  }
}
