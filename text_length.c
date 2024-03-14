#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *n) {
    printf("The length of your text is less than specified, please update your text\n");
    *n = MIN_LENGTH;
}

void equalThanRequired(int *n) {
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired(int *n) {
    printf("Your text is too long, please reduce the text\n");
    *n = MAX_LENGTH;
}

int checkLengthRequirement(char *text) {
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText = 0, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    lengthOfText = strlen(text);
    printf("lenght before: %d\n", lengthOfText);
    selectOption = checkLengthRequirement(text);

    void (*fun_ptr_arr[])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};
    (*fun_ptr_arr[selectOption])(&lengthOfText);

    printf("\nThe Length is updated to %d\n", lengthOfText);

    return 0;
}

/*
3.	Penjelasan
Kode di atas adalah program dalam bahasa C yang membaca teks dari file "file.txt" dan menentukan panjang teks tersebut. Berikut adalah ringkasan singkatnya:
1. Program membuka file "file.txt" untuk dibaca dan membaca teks dari file tersebut menggunakan fungsi `fgets()`. Teks tersebut disimpan dalam array `text`.
2. Panjang teks dihitung menggunakan fungsi `checkLengthRequirement()`. Fungsi ini mengembalikan nilai yang menunjukkan apakah panjang teks kurang dari, sama dengan, atau lebih dari panjang minimum yang ditentukan.
3. Program menggunakan array of function pointers `fun_ptr_arr` untuk menyimpan alamat fungsi-fungsi yang akan dipanggil berdasarkan hasil dari `checkLengthRequirement()`. 
4. Berdasarkan hasil perhitungan, program memanggil salah satu dari tiga fungsi berikut:
   - `lessThanRequired()`: Jika panjang teks kurang dari panjang minimum yang ditentukan.
   - `equalThanRequired()`: Jika panjang teks sama dengan panjang minimum yang ditentukan.
   - `moreThanRequired()`: Jika panjang teks lebih dari panjang minimum yang ditentukan.
5. Setiap fungsi menampilkan pesan sesuai dengan kondisi teks, serta memperbarui panjang teks jika diperlukan.
6. Output program mencakup pesan yang sesuai dan panjang teks yang telah diperbarui.
Kode ini menunjukkan penggunaan array of function pointers dan pointer untuk mengubah nilai panjang teks di dalam fungsi-fungsi yang sesuai.

*/