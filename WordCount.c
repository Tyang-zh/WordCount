#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int countCharacters(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

int countWords(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    int count = 0;
    bool inWord = false;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || ch == ',') {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] input_file_name\n", argv[0]);
        return 1;
    }

    const char *param = argv[1];
    const char *fileName = argv[2];

    if (strcmp(param, "-c") == 0) {
        int characters = countCharacters(fileName);
        if (characters != -1) {
            printf("Characters: %d\n", characters);
        }
    } else if (strcmp(param, "-w") == 0) {
        int words = countWords(fileName);
        if (words != -1) {
            printf("Words: %d\n", words);
        }
    } else {
        printf("Invalid parameter. Use '-c' for characters or '-w' for words.\n");
        return 1;
    }

    return 0;
}
