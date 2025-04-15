#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define MAX_LEN 512
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(int argc, char *argv[]) {
    char buffer[MAX_LEN + 1];
    int i, len = 0;

    // Build the full message from argv
    for (i = 1; i < argc; i++) {
        int arg_len = strlen(argv[i]);

        if (len + arg_len + 1 >= MAX_LEN) {
            write(2, "Error: Message too long\n", 24);
            exit(1);
        }

        memmove(buffer + len, argv[i], arg_len);
        len += arg_len;

        if (i + 1 < argc) {
            buffer[len] = ' ';
            len++;
        }
    }
    buffer[len] = '\0';

    char *p = buffer;
    while (*p) {
        if (p[0] == 'o' && p[1] == 's') {
            write(1, BLUE, strlen(BLUE));
            write(1, "os", 2);
            write(1, RESET, strlen(RESET));
            p += 2;
        } else {
            write(1, p, 1);
            p++;
        }
    }

    write(1, "\n", 1);
    exit(0);
}