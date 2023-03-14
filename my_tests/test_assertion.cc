#include <cstdio>
#include <cstdlib>

#define ASSERT(cond)                                                                                                   \
    do {                                                                                                               \
        if (!(cond)) {                                                                                                 \
            printf("%s:%d: %s: Assertion `%s` failed.\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, #cond);             \
            exit(EXIT_FAILURE);                                                                                        \
        }                                                                                                              \
    } while (0);

int main() {
    ASSERT(1 == 1);
    printf("Assertion 1 passed.\n");
    ASSERT(1 == 2);
    printf("Assertion 2 passed.\n");
}