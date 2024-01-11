#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float var__0, var__1, var__2, var__3, var__4;
  (*(&((*(&((*(&(scanf)))))))))("%f %f %f %f %f", &(*(&(var__0))),
                                &(*(&(var__1))), &(*(&(var__2))), &var__3,
                                &(*(&((*(&((*(&(var__4))))))))));
  float var__5 =
      ((*(&((*(&((*(&(var__0))))))))) - (*(&((*(&(var__3))))))) *
          (var__0 - var__3) +
      ((*(&((*(&((*(&(var__1))))))))) - var__4) * (var__1 - (*(&(var__4))));
  float var__6 = sqrtf((*(&(var__5))));
  if (1) {
    if ((*(&((*(&((*(&(var__6))))))))) == (*(&((*(&((*(&(var__2))))))))))
      if (0) {
      } else {
        {
          if (1) {
            printf("Point is on the circle.");
          }
        }
      }
    else if (var__6 > (*(&((*(&((*(&(var__2))))))))))
      if (0) {
      } else {
        {
          if (1) {
            (*(&((*(&(printf))))))("Point is outside the circle.");
          }
        }
      }
    else if (0) {
    } else {
      if (var__6 < (*(&((*(&((*(&(var__2))))))))))
        if (1) {
          {
            if (0) {
            } else {
              printf("Point is inside the circle.");
            }
          }
        }
    }
  }
  if (0) {
  } else {
    return 0;
  }
}
