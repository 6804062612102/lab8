#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// โปรโตไทป์ฟังก์ชัน (ชื่อเดิมทั้งหมด)
int random1toN(int N);
void printAr(int numAr[], int numArSize, int cLimit);
int checkNum(int numAr[], int numArSize, int target);
int searchNum(int numAr[], int numArSize, int target);

int main() {
    srand(time(NULL));
    int list[SIZE];

    for (int i = 0; i < SIZE; i++) {
        int rn;
        
        // วนลูปจนกว่าจะสุ่มได้ตัวเลขที่ไม่ซ้ำ (checkNum คืนค่า 1 คือไม่ซ้ำ)
        do {
            rn = random1toN(SIZE);
        } while (checkNum(list, i, rn) == 0);
        
        list[i] = rn;
    }

    printAr(list, SIZE, 20);
    
    return 0;
}

// สุ่มเลข 1 ถึง N
int random1toN(int N) {
    return (rand() % N) + 1;
}

// ตรวจสอบว่าตัวเลข "ใช้งานได้" (ไม่ซ้ำ) หรือไม่
int checkNum(int numAr[], int numArSize, int target) {
    // ถ้า searchNum เจอ (เป็น 1) แสดงว่าซ้ำ ให้คืนค่า 0 (ใช้งานไม่ได้)
    if (searchNum(numAr, numArSize, target)) {
        return 0; 
    }
    return 1; // ไม่ซ้ำ ใช้งานได้
}

// ค้นหาตัวเลขใน Array
int searchNum(int numAr[], int numArSize, int target) {
    for (int i = 0; i < numArSize; i++) {
        if (numAr[i] == target) {
            return 1; // เจอตัวเลข
        }
    }
    return 0; // ไม่เจอ
}

// แสดงผล Array
void printAr(int numAr[], int numArSize, int cLimit) {
    for (int i = 0; i < numArSize; i++) {
        printf("%3d", numAr[i]);
        
        // ตรวจสอบการขึ้นบรรทัดใหม่
        if ((i + 1) % cLimit == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}
