//. Implement a simple text editor’s Undo/Redo using stacks.
#include <stdio.h>
#include <string.h>
#define MAX 50
#define STACK_SIZE 10
char undo[STACK_SIZE][MAX];
char redo[STACK_SIZE][MAX];
int utop = -1, rtop = -1;
char text[MAX] = "";
void type(char *s) {
    strcpy(undo[++utop], text);
    rtop = -1;
    strcat(text, s);
}
void undoOp() {
    if (utop >= 0) {
        strcpy(redo[++rtop], text);
        strcpy(text, undo[utop--]);
    }
}
void redoOp() {
    if (rtop >= 0) {
        strcpy(undo[++utop], text);
        strcpy(text, redo[rtop--]);
    }
}
int main() {
    type("Hello ");
    type("World");
    printf("Text: %s\n", text);
    undoOp();
    printf("After Undo: %s\n", text);
    redoOp();
    printf("After Redo: %s\n", text);
    return 0;
}
