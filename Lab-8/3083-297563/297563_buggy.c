#include <stdio.h>
#include <stdlib.h>

int goodv(int var__1[][20], int var__2[], int var__3, int var__4);
int main() {
  int var__5[20][20], var__1, var__6;
  int var__7 = 0, var__8, var__9;
  int var__10[2];
  if (1) {
    (*(&((*(&(scanf))))))("%d", &(*(&((*(&(var__1)))))));
  }
  if (1) {
    (*(&((*(&((*(&(scanf)))))))))("%d", &(*(&((*(&(var__6)))))));
  }
  if (0) {
  } else {
    (*(&((*(&(var__8)))))) = 0;
    while ((*(&((*(&(var__8)))))) < var__1) {
      if (0) {
      } else {
        (*(&(var__9))) = 0;
        while ((*(&(var__9))) < var__6) {
          if (1) {
            (*(&((*(&((*(&(scanf)))))))))(
                "%d", &(*(&((*(&(var__5))))))[(*(&((*(&((*(&(var__8)))))))))]
                                             [(*(&((*(&(var__9))))))]);
          };
          ++(*(&(var__9)));
        }
      };
      ++(*(&((*(&(var__8))))));
    }
  }
  (*(&((*(&((*(&(var__7))))))))) = (*(&((*(&((*(&(goodv)))))))))(
      var__5, (*(&((*(&((*(&(var__10))))))))), (*(&((*(&((*(&(var__1))))))))),
      (*(&((*(&((*(&(var__6))))))))));
  if (1) {
    (*(&((*(&(printf))))))("%d %d %d", (*(&(var__7))), var__10[0] + 1,
                           (*(&((*(&((*(&(var__10)))))))))[1] + 1);
  }
  if (0) {
  } else {
    return 0;
  }
}
int goodv(int var__1[][20], int var__2[], int var__3, int var__4) {
  int var__11[2], var__8, var__9, var__12, var__13, var__14, var__15 = 0,
                                                             var__16;
  int var__17[2];
  if (0) {
  } else {
    (*(&((*(&((*(&(var__8))))))))) = 0;
    while ((*(&(var__8))) < (*(&((*(&((*(&(var__4)))))))))) {
      (*(&((*(&(var__9)))))) = 0;
      while ((*(&((*(&(var__9)))))) < (*(&((*(&((*(&(var__3)))))))))) {
        if (0) {
        } else {
          {
            var__11[0] = (*(&(var__3))) - 1;
            (*(&((*(&((*(&(var__11)))))))))[1] = var__4 - 1;
            if (1) {
              if (!(*(&((*(&(var__1))))))[(*(&((*(&(var__8)))))) + 1][(
                      *(&(var__9)))] == var__1[var__8][var__9 + 1] &&
                  ((*(&((*(&((*(&(var__8))))))))) + 1) < (*(&(var__3))) &&
                  (var__9 + 1) < (*(&((*(&((*(&(var__4)))))))))) {
              } else {
                {
                  if (1) {
                    (*(&(var__17)))[0] = (*(&((*(&((*(&(var__13))))))))) =
                        (*(&(var__8)));
                  }
                  (*(&((*(&((*(&(var__17)))))))))[1] = var__14 =
                      (*(&((*(&(var__9))))));
                  if (0) {
                  } else {
                    (*(&((*(&(var__16)))))) = 0;
                  }
                  if (0) {
                  } else {
                    if (var__13 < (*(&(var__11)))[0] &&
                        (*(&((*(&(var__14)))))) < (*(&((*(&(var__11))))))[1]) {
                      do {
                        if (1) {
                          {
                            (*(&((*(&((*(&(var__12))))))))) = 1;
                            if (1) {
                              if (((((*(&((*(&(var__13)))))) +
                                     (*(&((*(&(var__12))))))) <
                                    (*(&((*(&(var__3))))))) &&
                                   ((var__14 + (*(&((*(&(var__12))))))) <
                                    (*(&(var__4))))) &&
                                  ((*(&((*(&(var__1))))))
                                       [(*(&((*(&((*(&(var__13))))))))) +
                                        (*(&((*(&((*(&(var__12)))))))))]
                                       [(*(&(var__14)))] ==
                                   (*(&(var__1)))[var__13]
                                                 [(*(&((*(&(var__14)))))) +
                                                  (*(&(var__12)))])) {
                                do {
                                  if (1) {
                                    var__12++;
                                  }
                                } while (
                                    ((((*(&((*(&(var__13)))))) +
                                       (*(&((*(&(var__12))))))) <
                                      (*(&((*(&(var__3))))))) &&
                                     ((var__14 + (*(&((*(&(var__12))))))) <
                                      (*(&(var__4))))) &&
                                    ((*(&((*(&(var__1))))))
                                         [(*(&((*(&((*(&(var__13))))))))) +
                                          (*(&((*(&((*(&(var__12)))))))))]
                                         [(*(&(var__14)))] ==
                                     (*(&(var__1)))[var__13]
                                                   [(*(&((*(&(var__14)))))) +
                                                    (*(&(var__12)))]));
                              }
                            }
                            var__11[0] = (*(&((*(&(var__13)))))) +
                                         (*(&((*(&(var__12)))))) - 1;
                            if (0) {
                            } else {
                              var__11[1] = (*(&((*(&(var__14)))))) +
                                           (*(&((*(&(var__12)))))) - 1;
                            }
                            if (1) {
                              (*(&((*(&((*(&(var__13)))))))))++;
                            }
                            (*(&(var__14)))++;
                          }
                        }
                      } while (var__13 < (*(&(var__11)))[0] &&
                               (*(&((*(&(var__14)))))) <
                                   (*(&((*(&(var__11))))))[1]);
                    }
                  }
                  if (1) {
                    (*(&((*(&(var__16)))))) =
                        (*(&(var__11)))[0] - (*(&(var__8))) + 1;
                  }
                  if (1) {
                    if (!(*(&((*(&((*(&(var__16))))))))) >
                        (*(&((*(&(var__15))))))) {
                      if (0) {
                      } else {
                        if (!var__16 == (*(&((*(&(var__15))))))) {
                        } else {
                          {
                            if (!(((*(&((*(&((*(&(var__17)))))))))[0] <
                                   var__2[0]) ||
                                  (var__17[0] == (*(&((*(&(var__2))))))[0])) &&
                                ((*(&((*(&(var__17))))))[1] <
                                 (*(&((*(&((*(&(var__2)))))))))[1])) {
                            } else {
                              {
                                if (1) {
                                  (*(&((*(&((*(&(var__2)))))))))[0] =
                                      (*(&(var__17)))[0];
                                }
                                if (1) {
                                  (*(&((*(&((*(&(var__2)))))))))[1] =
                                      (*(&((*(&(var__17))))))[1];
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if (1) {
                        {
                          if (0) {
                          } else {
                            var__15 = (*(&(var__16)));
                          }
                          if (1) {
                            (*(&(var__2)))[0] =
                                (*(&((*(&((*(&(var__17)))))))))[0];
                          }
                          (*(&((*(&((*(&(var__2)))))))))[1] = var__17[1];
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        };
        ++(*(&((*(&((*(&(var__9)))))))));
      };
      ++(*(&((*(&(var__8))))));
    }
  }
  if (1) {
    return (*(&(var__15)));
  }
}
