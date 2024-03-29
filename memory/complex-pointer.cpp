void (*signal(int sig, void (*func)(int)))(int){}

// `signal` is a function, taking an int, and a pointer to a function taking an int returning void, returning a pointer to a function taking an int returning void.

int *(*p(int))[3] {}

// p is a function, taking an int, returning a pointer to an array of 3 int pointer.

int *((*p)(int))[3] {}

// p is a pointer to a function, taking an int, returning an array of 3 int pointer.