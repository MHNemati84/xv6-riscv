#include "kernel/types.h"
#include "user/user.h"

int main() {
    printf("Triggering system call...\n");
    trigger();
    return 0;	
}
