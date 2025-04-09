#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(){
   printf(1, “return val of system call is %d\n”, trigger());
    exit();
}
