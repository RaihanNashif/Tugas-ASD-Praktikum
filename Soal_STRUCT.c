#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void nextDay(struct Date *date) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,31, 30, 31};

    if (date->month == 2 && isLeapYear(date->year)) {
        daysInMonth[2] = 29;
    }

    if (date->day < daysInMonth[date->month]) {
        date->day++;
    } else {
        date->day = 1;
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

int main() {
    struct Date currentDate;

    printf("Masukkan tanggal (format: dd/mm/yyyy): ");
    scanf("%d/%d/%d", &currentDate.day, &currentDate.month, &currentDate.year);

    nextDay(&currentDate);

    printf("Tanggal berikutnya adalah: %d/%d/%d\n", currentDate.day, currentDate.month, currentDate.year);

    return 0;
}

/*
-Deklarasi 'Struktur Date':
Program mendefinisikan struktur Date yang memiliki tiga variabel angka bulat untuk menyimpan tanggal, bulan, dan tahun.

-Fungsi 'isLeapYear'untuk memeriksa apakah suatu tahun merupakan tahun kabisat atau bukan berdasarkan aturan tahun kabisat. Jika tahun tersebut adalah tahun kabisat, fungsi mengembalikan nilai 1; jika tidak, mengembalikan nilai 0.

Fungsi nextDay:
-Fungsi ini menghitung tanggal berikutnya berdasarkan tanggal yang diberikan.
-Fungsi menggunakan array daysInMonth untuk menyimpan jumlah hari dalam setiap bulan.
-Jika tanggal yang diberikan adalah 29 Februari pada tahun kabisat, array daysInMonth diperbarui untuk memperhitungkan tahun kabisat.
-Fungsi ini memperbarui tanggal, bulan, dan tahun sesuai dengan perhitungan yang dilakukan.

Fungsi Utama (main) 
-Meminta pengguna memasukkan tanggal dalam format "dd/mm/yyyy", kemudian inputan dibaca menggunakan scanf.
-Fungsi kemudian memanggil nextDay untuk menghitung tanggal berikutnya.
-Hasil tanggal berikutnya kemudian dicetak ke layar menggunakan printf.
*/