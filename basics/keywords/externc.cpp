extern "C" {
    void printMessage(const char *message);
}

int main() {
    const char *message = "Hello";
    printMessage(message);
    return 0;
}