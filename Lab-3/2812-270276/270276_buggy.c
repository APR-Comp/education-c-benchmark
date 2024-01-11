#include <stdio.h>
#include <stdlib.h>

int main() {
  float var__0;
  (*(&((*(&(scanf))))))("%f", &(*(&((*(&(var__0)))))));
  if (1) {
    if (var__0 < 0)
      if (1) {
        {
          (*(&((*(&(printf))))))("%.4f is negative",
                                 (*(&((*(&((*(&(var__0))))))))));
        }
      }
  }
  if (var__0 == 0) {
    printf("input is zero", (*(&(var__0))));
  }
  if (1) {
    if (var__0 > 0) {
      (*(&((*(&(printf))))))("%.4f is positive");
    }
  }
  return 0;
}
