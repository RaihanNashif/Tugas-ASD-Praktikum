#include <stdio.h>
#include <stdlib.h>

// Struktur data stack untuk menyimpan tanda kurung
struct Stack {
    char data;
    struct Stack* next;
};

// Fungsi untuk membuat node stack baru
struct Stack* newNode(char data) {
    struct Stack* stackNode = (struct Stack*)malloc(sizeof(struct Stack));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Fungsi untuk menambahkan elemen ke stack
void push(struct Stack** root, char data) {
    struct Stack* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Fungsi untuk menghapus elemen dari stack
char pop(struct Stack** root) {
    if (*root == NULL) return '\0'; // Return NULL character if stack kosong
    struct Stack* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Fungsi untuk memeriksa apakah tanda kurung berpasangan
char isBalanced(char* exp) {
    struct Stack* stack = NULL;
    char popped;

    // Iterasi melalui setiap karakter dalam string
    for (int i = 0; exp[i] != '\0'; i++) {
        // Jika karakter merupakan tanda kurung pembuka, tambahkan ke stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&stack, exp[i]);
        }
        // Jika karakter merupakan tanda kurung penutup
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            // Jika stack kosong, tanda kurung tidak berpasangan
            if (stack == NULL) return 'N';
            
            // Pop dari stack dan periksa pasangan tanda kurung
            popped = pop(&stack);
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == '}' && popped != '{') ||
                (exp[i] == ']' && popped != '[')) {
                return 'N'; // Pasangan tanda kurung tidak sesuai
            }
        }
    }

    // Jika stack tidak kosong pada akhir iterasi, tanda kurung tidak seimbang
    if (stack != NULL) return 'N';
    
    return 'Y'; // Tanda kurung seimbang
}

int main() {
    char expression[100];
    fgets(expression, sizeof(expression), stdin);

    char result = isBalanced(expression);

    if (result == 'Y') {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

/*
Program ini menggunakan tumpukan untuk menentukan apakah tanda kurung dalam sebuah ekspresi matematika seimbang atau tidak. Jika tanda kurung pembuka dan penutupnya cocok dan urutannya benar, program akan mengeluarkan output "YES"; jika tidak, maka akan mengeluarkan output "NO"
*/