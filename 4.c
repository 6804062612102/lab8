#include <stdio.h>

// ฟังก์ชันเรียงลำดับคะแนนจากมากไปน้อย (Bubble Sort)
void sort(int thing[][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            // ถ้าคะแนนตัวหน้า น้อยกว่า ตัวหลัง ให้สลับที่กัน
            if (thing[j][0] < thing[j + 1][0]) {
                // สลับค่าคะแนน (Index 0)
                int temp0 = thing[j][0];
                thing[j][0] = thing[j + 1][0];
                thing[j + 1][0] = temp0;

                // สลับลำดับครั้งที่ (Index 1) ตามไปด้วย
                int temp1 = thing[j][1];
                thing[j][1] = thing[j + 1][1];
                thing[j + 1][1] = temp1;
            }
        }
    }
}

int main() {
    int history[4][2];

    // รับค่าคะแนน 4 ครั้ง
    for (int i = 0; i < 4; i++) {
        printf("Input your score from attempt #%d: \t", i + 1);
        scanf("%d", &history[i][0]);
        history[i][1] = i + 1; // เก็บหมายเลขครั้งที่ไว้
    }

    sort(history);

    // แสดงผลลัพธ์ 3 อันดับแรก
    printf("\nYour best attempts were (in order): \t");
    for (int i = 0; i < 3; i++) {
        printf("%d", history[i][1]);
        
        // ใส่คอมม่าคั่น ยกเว้นตัวสุดท้าย
        if (i < 2) {
            printf(", ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
