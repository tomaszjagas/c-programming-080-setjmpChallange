#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void errorRecovery() {
    printf("detected an error\n");
    longjmp(buf, 1);
}

int main() {
    while (1) {
        if (setjmp(buf)) {
            printf("back in main\n");
            break;
        }
        else {
            errorRecovery();
        }
    }

    return 0;
}