#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

struct Node
{
    struct Node *link;
    char alphabet;
};
typedef struct Node Node;

int main()
{
    // inisialisasi struct yang akan dikaitkan
    Node l1, l2, l3, l4, l5, l6, l7, l8, l9; 
    
    l1.link = NULL;
    l1.alphabet = 'F';
    l2.link = NULL;
    l2.alphabet = 'M';
    l3.link = NULL;
    l3.alphabet = 'A';
    l4.link = NULL;
    l4.alphabet = 'I';
    l5.link = NULL;
    l5.alphabet = 'K';
    l6.link = NULL;
    l6.alphabet = 'T';
    l7.link = NULL;
    l7.alphabet = 'N';
    l8.link = NULL;
    l8.alphabet = 'O';
    l9.link = NULL;
    l9.alphabet = 'R';

    // mengurutkan posisi struct di dalam array
    Node *arrayNode[9] = {&l7, &l1, &l8, &l2, &l5, &l3, &l6, &l9, &l4};

    // mengaitkan semua struct
    for(int i = 0; i < 9 - 1; i++)
    {
        arrayNode[i]->link = arrayNode[i+1];
    }
    arrayNode[8]->link = arrayNode[0];

    // insialisasi variabel pondasi yang mencakup semua struct yang berkaitan
    Node *current = arrayNode[0];
    // variabel yang menyimpan rangkaian kata yang dibuat user
    char kalimat[MAX_LENGTH];
    strcpy(kalimat, "\0");

    int state = 1;
    int count = 0, choice, posChar = -1;

    // main program
    printf("Rangkai sebuah kata!\n");
    while(state)
    {
        printf("Rangkaian kata (%d/%d): %s\n", posChar+1, MAX_LENGTH, kalimat);
        printf("Rute: ");
        for(int i = 0; i <= count; i++)
        {
            printf("Link%d->", i+1);
        }
        printf("%c\n", current->alphabet);
        printf("1. Insert character\n2. Next node\n3. Exit program\nPilih menu: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            posChar++;
            if(posChar < MAX_LENGTH)
            {
                kalimat[posChar] = current->alphabet;
            }
            else
            {
                printf("ERROR: Jumlah karakter mencapai batas maksimal.\n");
                state = 0;
            }
            break;
        case 2:
            count++;
            current = current->link;
            if(current->alphabet == 'N')
            {
                count = 0;
            }
            break;
        case 3:
            state = 0;
            break;
        default:
            break;
        }
    }
    printf("\nHasil akhir rangkaian kata: %s", kalimat);
    return 0;
}

/*
'stdio.h' yang mengimpor file header stdio.h untuk fungsi-fungsi standar input-output dan string.h untuk fungsi-fungsi pemrosesan string

struktur Node yang memiliki dua anggota: pointer link untuk menghubungkan node dengan node lainnya, dan karakter alphabet untuk menyimpan huruf pada node tersebut.
typedef struct Node Node; membuat alias Node untuk struct Node, sehingga kita bisa menggunakan Node langsung tanpa menulis struct setiap kali.

Fungsi main:
Inisialisasi: Membuat 9 objek Node (l1 hingga l9) dan mengatur link mereka ke NULL pada awalnya. Kemudian, tetapkan karakter ke setiap node ('F', 'M', dll.).
Penyortiran: Array arrayNode pointer ke objek Node dibuat, mengacak urutan mereka untuk lebih dinamis.

Loop melalui arrayNode untuk menghubungkan node secara berurutan. Node terakhir (arrayNode[8]) menunjuk kembali ke yang pertama (arrayNode[0]).

current: Pointer ke simpul saat ini dalam daftar tertaut.
kalimat (string): Menyimpan kata yang dibuat pengguna (diinisialisasi sebagai string kosong).
-state: Bendera untuk mengontrol loop program (1 = berjalan, 0 = keluar).
-count: Melacak jumlah node yang dilalui dalam kata saat ini.
-choice: Pilihan menu pengguna.
-posChar: Posisi karakter yang disisipkan dalam string kalimat.

Loop Program Utama:
Menampilkan kata, dan opsi menu saat ini.
Membaca pilihan pengguna menggunakan scanf.
Pernyataan switch: Menangani tindakan pengguna:
-Kasus 1 (Sisipkan karakter): Meningkatkan posChar, memeriksa panjang maksimum, dan menambahkan karakter simpul saat ini ke string kalimat.
-Kasus 2 (Node berikutnya): Meningkatkan count, memperbarui current ke node berikutnya, dan mengatur ulang count ke 0 jika node 'N' tercapai (secara efektif memulai kembali traversal).
-Kasus 3 (Keluar program): Mengatur state ke 0 untuk keluar dari loop.

Menampilkan hasil akhir dari rangkaian kata yang telah dibuat oleh pengguna.
Mengembalikan nilai 0 

*/