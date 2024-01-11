#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
  float var__0, var__1, var__2, var__3, var__4, var__5;
  if (1) {
    (*(&((*(&((*(&(scanf)))))))))(
        "%f %f %f %f %f", &(*(&((*(&((*(&(var__0))))))))), &var__1,
        &(*(&(var__4))), &(*(&((*(&((*(&(var__2))))))))), &(*(&(var__3))));
  }
  var__5 = (*(&((*(&(sqrtf))))))(
      (((*(&(var__0))) - (*(&(var__2)))) * (var__0 - var__2)) +
      (((*(&((*(&(var__1)))))) - (*(&((*(&(var__3))))))) *
       (var__1 - (*(&((*(&((*(&(var__3))))))))))));
  if (1) {
    if (var__5 > (*(&(var__4))))
      if (0) {
      } else {
        {
          if (0) {
          } else {
            (*(&((*(&(printf))))))("Point is outside the Circle.");
          }
        }
      }
    else if (0) {
    } else {
      if ((*(&(var__5))) == var__4)
        if (0) {
        } else {
          {
            if (1) {
              (*(&((*(&(printf))))))("Point is on the Circle");
            }
          }
        }
      else if (0) {
      } else {
        {
          if (1) {
            (*(&((*(&((*(&(printf)))))))))("Point is inside the Circle.");
          }
        }
      }
    }
  }
  if (1) {
    return 0;
  }
}
