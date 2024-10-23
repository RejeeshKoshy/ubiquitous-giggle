/*----------------------------
reverseString.c

Rejeesh Koshy
XX-10-2024
----------------------------*/

typedef struct {
    char A[SIZE];
    int top;
} stack;

stack s;

// Stack functions
void InitStack();
void Push(char ch);
char Pop();
int IsEmpty();
void ReverseString(char str[]);

int main() {
    char str[SIZE];

    // Input: string
    printf("Enter a string: ");
    gets(str);

    // Reverse the string
    ReverseString(str);

    // Output: reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}


// Stack functions
void InitStack() {
    s.top = -1; // Initializing the stack to be empty
}

void Push(char ch) {
    if (s.top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        s.top++;
        s.A[s.top] = ch;
    }
}

char Pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s.A[s.top--];
    }
}

int IsEmpty() {
    return s.top == -1;
}

// Function to reverse the string using the stack
void ReverseString(char str[]) {
    int len = strlen(str);
    InitStack();

    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++) {
        Push(str[i]);
    }

    // Pop characters from the stack to get the reversed string
    for (int i = 0; i < len; i++) {
        str[i] = Pop();
    }
}