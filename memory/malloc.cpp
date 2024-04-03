#include <cstdlib>

int main() {
    // int *i = (int *) malloc(sizeof(int));
    // free(i);

    // int *p = new int(1);
    // delete p;

    int *i = (int *) malloc(sizeof(int));
    if (NULL != i) {
        free(i);
    }

    int *j;

    try {
        j = new int;
    } catch (...) {

    }

    delete j;
}