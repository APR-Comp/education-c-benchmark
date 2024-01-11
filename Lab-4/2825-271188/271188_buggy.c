#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float var__0, var__1, var__2, var__3, var__4, var__5;
  (*(&(scanf)))("%f%f%f%f%f", &(*(&((*(&((*(&(var__0))))))))), &var__1,
                &(*(&(var__2))), &var__3, &var__4);
  if (1) {
    (*(&((*(&((*(&(var__5))))))))) = (*(&((*(&(sqrtf))))))(
        (*(&(pow)))((var__3 - (*(&((*(&(var__0))))))), 2) +
        pow(((*(&((*(&((*(&(var__4))))))))) - (*(&((*(&(var__1))))))), 2));
  }
  if ((*(&((*(&(var__5)))))) < (*(&((*(&((*(&(var__2))))))))))
    if (1) {
      (*(&((*(&(printf))))))("Point is inside the Circle.");
    } else if (1) {
      if ((*(&((*(&(var__5)))))) == (*(&((*(&((*(&(var__2))))))))))
        if (0) {
        } else {
          (*(&((*(&(printf))))))("Point is on the Circle.");
        }
      else if (0) {
      } else {
        (*(&(printf)))("Point is outside the Circle.");
      }
    }
  return 0;
}
