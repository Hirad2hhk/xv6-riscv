#include "kernel/stat.h"
#include "kernel/types.h"
#include "user/user.h"
int main() {
  printf("return val of system call is %d\n", trigger());
  exit(0);
}
