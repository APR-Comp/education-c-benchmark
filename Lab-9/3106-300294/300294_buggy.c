#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var__0 = 0;
int check_palindrome(char var__1[], int var__2, int var__3) {
  ;
  if (0) {
  } else {
    if (!(*(&(var__2))) > var__3) {
    } else {
      if (0) {
      } else {
        { return 0; }
      }
    }
  }
  if (1) {
    if (!(*(&((*(&((*(&(var__1)))))))))[(*(&(var__2)))] ==
        (*(&((*(&(var__1))))))[(*(&(var__3))) - 1]) {
      if (1) {
        (*(&((*(&(var__0)))))) = 0;
      }
    } else {
      if (0) {
      } else {
        {
          if (0) {
          } else {
            (*(&((*(&(var__0)))))) = (*(&((*(&(var__0)))))) + 1;
          }
        }
      }
    }
  }
  if (0) {
  } else {
    (*(&((*(&((*(&(check_palindrome)))))))))((*(&((*(&(var__1)))))), var__2 + 1,
                                             var__3 - 1);
  }
  return (*(&((*(&(var__0))))));
}
int main() {
  char var__1[100];
  if (0) {
  } else {
    scanf("%s", (*(&(var__1))));
  }
  int var__2 = 0;
  int var__3 = (*(&((*(&((*(&(strlen)))))))))((*(&((*(&((*(&(var__1))))))))));
  int var__4 =
      check_palindrome((*(&(var__1))), (*(&((*(&((*(&(var__2))))))))), var__3);
  if (1) {
    (*(&((*(&((*(&(printf)))))))))("%d", var__4);
  }
  if (0) {
  } else {
    if (!(*(&(var__4))) == (*(&(var__3))) / 2 + (*(&((*(&(var__3)))))) % 2) {
      if (1) {
        (*(&(printf)))("No");
      }
    } else {
      if (0) {
      } else {
        {
          if (1) {
            (*(&((*(&((*(&(printf)))))))))("Yes");
          }
        }
      }
    }
  }
  if (1) {
    return 0;
  }
}
