#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *  1. The expression is no longer valid after the type is changed. Furthermore
 *     the correctness of 't' isn't guaranteed and needs to be checked
 *     elsewhere in the code.
 *  2. digit_count[d-'0']
 *  3. bool weekend[] = {1, 0, 0, 0, 0, 0, 1} 
 *  4. bool weekend[] = {[0] = 1, [6] = 1}
 *  5. int fib_numbers[40] = {0, 1};
 *     for (int i = 2; i < (sizeof(fib_numbers) / sizeof(fib_numbers[0])); i++) {
 *         fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
 *     }
 *  6. const int segments[10][7] = {
 *         {1, 1, 1, 1, 1, 1, 0}, // 0 
 *         {0, 1, 1, 0, 0, 0, 0}, // 1
 *         {1, 1, 0, 1, 1, 0, 1}, // 2
 *         {1, 1, 1, 1, 0, 0, 1}, // 3
 *         {0, 1, 1, 0, 0, 1, 1}, // 4
 *         {1, 0, 1, 1, 0, 1, 1}, // 5
 *         {1, 0, 1, 1, 1, 1, 1}, // 6
 *         {1, 1, 1, 0, 0, 0, 0}, // 7
 *         {1, 1, 1, 1, 1, 1, 1}, // 8
 *         {1, 1, 1, 1, 0, 1, 1}  // 9
 *     };
 *  7. const int segments[10][7] = {
 *         {1, 1, 1, 1, 1, 1}, // 0
 *         {[1] = 1, 1}, // 1
 *         {1, 1, [3] = 1, 1, [6] = 1}, // 2
 *         {1, 1, 1, 1, [6] = 1}, // 3
 *         {[1] = 1, 1, [5] = 1, 1}, // 4
 *         {1, [2] = 1, 1, [5] = 1, 1}, // 5
 *         {1, [2] = 1, 1, 1, 1, 1}, //6
 *         {1, 1, 1}, // 7
 *         {1, 1, 1, 1, 1, 1, 1}, // 8
 *         {1, 1, 1, 1, [5] = 1, 1 } // 9
 *     };
 *  8. float temperature_readings[30][24];
 *  9. for (int i = 0; i < 30; i++) {
 *         for (int j = 0; j < 24; j += 1) {
 *             a += temperature_readings[i][j];
 *         }
 *     }
 *     m /= 30 * 24;
 * 10. const int chess_board[8][8] = {
 *         {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
 *         {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
 *         {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 *         {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 *         {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 *         {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 *         {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
 *         {'R', 'N', 'B'. 'Q', 'K', 'B', 'N', 'R'}
 *     };
 * 11. char checker_board[8][8];
 *     for (int i = 0; i < 8; i++) {
 *         for(int j = 0; j < 8; j += 1) {
 *             if ((i + j) % 2) {
 *                 checker_board[i][j] = 'R';
 *             } else {
 *                 checker_board[i][j] = 'B';
 *             }
 *         }
 *     }
 */

void pp1() {
    int digits[10] = {0}, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digits[n % 10] += 1;
        n /= 10;
    }
    printf("Repeated digit(s): ");
    for (i = 0; i < (int) (sizeof(digits) / sizeof(digits[0])); i++) {
        if (digits[i] > 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void pp2() {
    int digits[10] = {0}, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digits[n%10] += 1;
        n /= 10;
    }

    printf("Digit:\t\t");
    for (i = 0; i < (int) (sizeof(digits) / sizeof(digits[0])); i++) {
        printf("%d ", i);
    }
    printf("\nOccurrences:\t");
    for (i = 0; i < (int) (sizeof(digits) / sizeof(digits[0])); i++) {
        printf("%d ", digits[i]);
    }
    printf("\n");
}

void pp3() {
    int digits[10] = {0}, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0) {
        digits[n % 10] += 1;
        n /= 10;
        printf("Enter a number: ");
        scanf("%ld", &n);
    }

    printf("Digit:\t\t");
    for (i = 0; i < (int) (sizeof(digits) / sizeof(digits[0])); i++) {
        printf("%d ", i);
    }
    printf("\nOccurrences:\t");
    for (i = 0; i < (int) (sizeof(digits) / sizeof(digits[0])); i++) {
        printf("%d ", digits[i]);
    }
    printf("\n");
}

void pp4() {
    int digits[10], i;

    printf("Enter %d numbers: ", (int) (sizeof(digits) / sizeof(digits[0])));
    for (i = 0; i < (int) (sizeof(digits) / sizeof(digits[0])); i++) {
        scanf("%d", &digits[i]);
    }

    printf("In reverse order:");
    for (i = (int) (sizeof(digits) / sizeof(digits[0])) - 1; i >= 0; i--) {
        printf(" %d", digits[i]);
    }
    printf("\n");
}

void pp5() {
    int r, y;
    double a[5], s;

    printf("Enter interest rate: ");
    scanf("%d", &r);
    printf("Enter number of years: ");
    scanf("%d", &y);

    printf("Years\t");
    for (int i = 0; i < 5; i++) {
        printf("%9d%%", r + i);
        a[i] = 100.0;
    }
    printf("\n");

    for (int i = 1; i <= y; i++) {
        printf("%5d\t", i);
        for (int j = 0; j < 5; j += 1) {
            s = 0;
            for (int k = 0; k < 12; k += 1) {
                s += ((r + j) / 100.0) * a[j];
            }
            a[j] += s;
            printf("%10.2f", a[j]);
        }
        printf("\n");
    }
}

void pp6() {
    char m[256];

    printf("Enter message: ");
    for (int i = 0; i < 256; i++) {
        m[i] = getchar();
        if (m[i] == '\n') {
            break;
        }
    }

    printf("In B1FF-speak: ");
    for (int i = 0; i < 256; i++) {
        m[i] = toupper(m[i]);
        if (m[i] == '\n') {
            printf("!!!!!!!!!!\n");
            break;
        }
        switch (m[i]) {
            case 'A':
                printf("4");
                break;
            case 'B':
                printf("8");
                break;
            case 'E':
                printf("3");
                break;
            case 'I':
                printf("1");
                break;
            case 'O':
                printf("0");
                break;
            case 'S':
                printf("5");
                break;
            default:
                printf("%c", m[i]);
                break;
        }
    }
}

void pp7() {
    int a[5][5], i, j, s[2][5] = {0};

    for (i = 0; i < 5; i++) {
        printf("Enter row %d: ", i + 1);
        scanf("%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    }

    printf("Row totals: ");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j += 1) {
            s[0][i] += a[i][j];
            s[1][i] += a[j][i];
        }
        printf("%d ", s[0][i]);
    }

    printf("\nColumn totals: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", s[1][i]);
    }
    printf("\n");
}

#define N 5
void pp8() {
    int a[N][N], i, j, t[N][2], s[2][N] = {0};

    printf("\n");
    for (i = 0; i < N; i++) {
        printf("Enter quiz grade %d: ", i + 1);
        for (j = 0; j < N; j += 1) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < N; i++) {
        t[i][0] = 99;
        t[i][1] = 0;
        for (j = 0; j < N; j += 1) {
            s[0][i] += a[i][j];
            s[1][i] += a[j][i];
            if (a[i][j] < t[i][0]) {
                t[i][0] = a[i][j];
            }
            if (a[i][j] > t[i][1]) {
                t[i][1] = a[i][j];
            }
        }
    }

    printf("Student\t\t");
    for (i = 1; i <= N; i++) {
        printf("%3d ", i);
    }
    printf("\nAverage:\t");
    for (i = 0; i < N; i++) {
        printf("%3d ", (s[1][i] / N));
    }
    printf("\nTotal:\t\t");
    for (i = 0; i < N; i++) {
        printf("%3d ", s[1][i]);
    }

    printf("\nQuiz\t\t");
    for (i = 1; i <= N; i++) {
        printf("%3d ", i);
    }
    printf("\nAverage:\t");
    for (i = 0; i < N; i++) {
        printf("%3d ", (s[0][i] / N));
    }
    printf("\nLow Score:\t");
    for (i = 0; i < N; i++) {
        printf("%3d ", (t[i][0]));
    }
    printf("\nHigh Score:\t");
    for (i = 0; i < N; i++) {
        printf("%3d ", (t[i][1]));
    }
    printf("\n");
}

void pp9() {
    int i, j, x = 0, y = 0, next, top, right, bottom, left, possible;
    char grid[10][10], letter = 'A';

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            grid[i][j] = '.';
        }
    }

    srand((unsigned) time(NULL));
    do {
        grid[x][y] = letter++;
        top = right = bottom = left = 1;

        if ((y - 1) < 0 || grid[x][y - 1] != '.') {
            top = 0;
        }
        if ((x + 1) > 9 || grid[x][x + 1] != '.') {
            right = 0;
        }
        if ((y + 1) > 9 || grid[x][y + 1] != '.') {
            bottom = 0;
        }
        if ((x - 1) < 0 || grid[x - 1][y] != '.') {
            left = 0;
        }
        possible = top + right + bottom + left;

        while (possible > 0) {
            next = rand() % 4;
            if (next == 0 && top == 1) {
                y--;
                break;
            } else if (next == 1 && right == 1) {
                x++;
                break;
            } else if (next == 2 && bottom == 1) {
                y++;
                break;
            } else if (next == 3 && left == 1) {
                x--;
                break;
            }
        }
        printf("Letter %c @ x %d y %d\n", letter, x, y);
        printf("top %d right %d bottom %d left %d\n", top, right, bottom, left);
    } while (possible > 0 && letter <= 'Z');

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void pp10() {
}

void pp11() {
}

void pp12() {
}

void pp13() {
}

void pp14() {
}

void pp15() {
}

void pp16() {
}

void pp17() {
}

int main(void) {
    // pp1();
    // pp2();
    // pp3();
    // pp4();
    // pp5();
    // pp6();
    // pp7();
    // pp8();
    pp9();
    pp10();
    pp11();
    pp12();
    pp13();
    pp14();
    pp15();
    pp16();
    pp17();
    return 0;
}
