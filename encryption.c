#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024


void XorEncrypt(const char *input, const char *key, char *output);
void XorDecrypt(const char *input, const char *key, char *output);


int
main(int argc, char* argv[]) {

    if (argc < 4) {
        fprintf(stderr, "Usage: %s -e/-d <key> <message>\n", argv[0]);
        return 1;
    }

    const char *mode = argv[1];
    const char *key = argv[2];
    char output[BUFFER_SIZE];

    if (argc > 4) {
        fprintf(stderr, "Too many arguments. Only one message can be processed.\n");
        return 1;
    }

    if (strcmp(mode, "-e") == 0) {
        XorEncrypt(argv[3], key, output);
        printf("Encrypted message: %s\n", output);
    } else if (strcmp(mode, "-d") == 0) {
        XorDecrypt(argv[3], key, output);
        printf("Decrypted message: %s\n", output);
    } else {
        fprintf(stderr, "Invalid mode. Use '-e' for encrypt or '-d' for decrypt.\n");
        return 1;
    }

	return 0;
}

void
XorEncrypt(const char *input, const char *key, char *output) {
    size_t keyLen = strlen(key);
    for (size_t i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    output[strlen(input)] = '\0';
}

void
XorDecrypt(const char *input, const char *key, char *output) {
    XorEncrypt(input, key, output);
}
