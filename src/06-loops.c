#include <stdio.h>

/*
 *   1. 1 2 4 8 16 32 64 128
 *   2. 9384 938 93 9
 *   3. 5 4 3 2
 *   4. (c) is not equivalent.
 *   5. (c) is (again) not equivalent.
 *   6. for (int i = 1; i <= 128; i *= 2) printf("%d ", i);
 *   7. for (int i = 9384; i > 0; i /= 10) printf("%d ", i);
 *   8. 10 5 3 2 1 1 1...
 *   9. i = 10; while (i >= 1) { printf("%d ", i++); i /= 2; }
 *  10. for (...) {
 *          ...
 *          goto eol; // here would be continue
 *          ...
 *          eol:;
 *      }
 *  11. 20
 *  12. for (d = 2; (d * d) <= n; d++) 
 *  13. for (n = 0; m > 0; m /= 2, n++) ;
 *  14. if (n % 2 == 0) printf("n is even\n");
 */

void pp1() {
    float x = 0, y;

    do {
        printf("Enter a number: ");
        scanf("%f", &y);
        x = (x < y) ? y : x;
    } while (y > 0);

    printf("\nThe largest number entered was %f\n", x);
}

void pp2() {
    int n, m, r;

    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);

    while (n > 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("Greatest common divisor: %d\n", m);
}

void pp3() {
    int n, d, x, y, r;

    printf("Enter a fraction: ");
    scanf("%d/%d", &n, &d);
    x = n;
    y = d;

    while (x > 0) {
        r = y % x;
        y = x;
        x = r;
    }

    printf("In lowest terms: %d/%d\n", (n / y), (d / y));
}

void pp4() {
    float v, c;

    while (1) {
        printf("Enter value of trade: ");
        scanf("%f", &v);

        if (v == 0) {
            break;
        }

        if (v < 2500.0f) {
            c = 30.0f + (.017f * v);
        } else if (v < 6250.0f) {
            c = 56.0f + (.0066f * v);
        } else if (v < 20000.0f) {
            c = 76.0f + (.0034f * v);
        } else if (v < 50000.0f) {
            c = 100.0f + (.0022f * v);
        } else if (v < 500000.0f) {
            c = 155.0f + (.0011f * v);
        } else {
            c = 255.0f + (.0009f * v);
        }

        if (c < 39.0f) {
            c = 39.0f;
        }
        printf("Commission: $%.2f\n", c);
    }
}

void pp5() {
    int n, x;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The reversal is: ");
    do {
        x = n % 10;
        printf("%d", x);
        n /= 10;
    } while (n != 0);
    printf("\n");
}

void pp6() {
    int n;

    printf("Enter a number n: ");
    scanf("%d", &n);

    for (int i = 1; (i * i) < n; i++) {
        if (i % 2 == 0) {
            printf("%d\n", (i * i));
        }
    }
    printf("%d\n", n);
}

void pp7() {
    int n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (int i = 1, s = 1, o = 3; i <= n; i++, s += o, o += 2) {
        printf("%10d%10d\n", i, s);
    }
}

void pp8() {
    int d, w;

    printf("Enter number of days in month: ");
    scanf("%d", &d);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &w);

    for (int i = w; i > 1; i--) {
        printf("   ");
    }
    for (int i = 1; i <= d; w++, i++) {
        printf("%2d ", i);
        if (w % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void pp9() {
    float a, i, m, r;
    int p;

    printf("Enter amount of loan: ");
    scanf("%f", &a);
    printf("Enter interest rate: ");
    scanf("%f", &i);
    printf("Enter monthly payment: ");
    scanf("%f", &m);
    printf("Enter number of payments: ");
    scanf("%d", &p);

    r = (i / 12 / 100) + 1;
    for (int y = 1; y <= p; y++) {
        a = (a - m) * r;
        printf("Balance remaining after %d. payment: $%.2f\n", y, a);
    }
}

void pp10() {
    int m1 = 12, d1 = 31, y1 = 99, m2, d2, y2;

    do {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &m2, &d2, &y2);

        if (!m2 || !d2 || !y2) {
            break;
        } else if (y1 < y2) {
            continue;
        } else if (y1 == y2 && m1 < m2) {
            continue;
        } else if (y1 == y2 && m1 == m2 && d1 <= d2) {
            continue;
        }

        m1 = m2;
        d1 = d2;
        y1 = y2;
    } while(1);

    printf("%d/%d/%d is the earliest date\n", m1, d1, y1);
}

void pp11() {
    int n;
    float a, r = 1.0f;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        a = 1.0f;
        for (int j = 1; j <= i; j++) {
            a *= j;
        }
        r += 1.0f / a;
    }

    printf("Approximation of e with n = %d is: %f\n", n, r);
}

void pp12() {
    float e, a, r = 1.0f;

    printf("Enter epsilon: ");
    scanf("%f", &e);

    for (int i = 1; r < e; i++) {
        a = 1.0f;
        for (int j = 1; j <= i; j++) {
            a *= j;
        }
        r += 1.0f / a;
    }

    printf("Approximation of e with epsilon = %f is: %f\n", e, r);
}

int main(void) {
    pp1();
    pp2();
    pp3();
    pp4();
    pp5();
    pp6();
    pp7();
    pp8();
    pp9();
    pp10();
    pp11();
    pp12();
    return 0;
}
