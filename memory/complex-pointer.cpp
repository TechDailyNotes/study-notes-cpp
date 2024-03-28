void (*signal(int sig, void (*func)(int)))(int){}

// `signal` is a pointer to a function, taking an int and a pointer to a function taking an int returning void, taking an int, returning void.