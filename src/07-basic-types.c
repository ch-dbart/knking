#include <stdio.h>
#include <ctype.h>
#include <math.h>

/*
 *  1. (a) 63 (b) 119 (c) 2748
 *  2. (a), (b) and (e) are legal floats (c) and (d) are illegal ints
 *  3. (b) is illegal
 *  4. (d) is illegal
 *  5. (b) is illegal
 *  6. (a) char (b) short (c) short (d) long
 *  7. (a) \010 (b) \012 (c) \015 (d) \011
 *  8. (a) \0x8 (b) \0xA (c) \0xD (d) \0x9
 *  9. int
 * 10. unsigned int
 * 11. double
 * 12. i is converted to float and (i + f) is promoted to double
 * 13. (a) -3 int (b) 7 long (c) 6.5 float (d) 3.75 double (e) -1 double (f) 6 int
 * 14. No, f could exceed the integer range.
 * 15. typedef char Int8;
 *     typedef short Int16;
 *     typedef int Int32;
 */

void pp1() {
    /*
     * smallest value of n for failure is...
     * - 182 for short (16 bit)
     * - 46'341 for int (32 bit)
     * - 3'037'000'500 for long (64 bit)
     */ 
}

void pp2() {
    int n, i;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    getchar(); /* catch newline */

    for (i = 1; i <= n; i += 1) {
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n');
        }            
        printf("%10d%10d\n", i, i * i);
    }
}

void pp3() {
    double n, s = 0.0;

    printf("This program sums a series of decimal numbers.\n");
    printf("Enter decimal numbers (0 to terminate): ");

    do {
        scanf("%lf", &n);
        s += n;
    } while (n != 0);

    printf("The sum is %f\n", s);
}

void pp4() {
    char c;

    printf("Enter phone number: ");
    while (1) {
        c = getchar();
        if (c == '\n') {
            printf("\n");
            break;
        }
        switch (c) {
            case 'A': case 'B': case 'C':
                printf("2");
                break;
            case 'D': case 'E': case 'F':
                printf("3");
                break;
            case 'G': case 'H': case 'I':
                printf("4");
                break;
            case 'J': case 'K': case 'L':
                printf("5");
                break;
            case 'M': case 'N': case 'O':
                printf("6");
                break;
            case 'P': case 'R': case 'S':
                printf("7");
                break;
            case 'T': case 'U': case 'V':
                printf("8");
                break;
            case 'W': case 'X': case 'Y':
                printf("9");
                break;
            default:
                putchar(c);
                break;
        }
    }
}

void pp5() {
    int s = 0;
    char c;

    printf("Enter a word: ");
    while (1) {
        c = getchar();

        if (c == '\n') {
            printf("Scrabble value: %d\n", s);
            break;
        }

        c = toupper(c);
        switch (c) {
            case 'A': case 'E': case 'I': case 'L': case 'N':
            case 'O': case 'R': case 'S': case 'T': case 'U':
                s += 1;
                break;
            case 'D': case 'G':
                s += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                s += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                s += 4;
                break;
            case 'K':
                s += 5;
                break;
            case 'J': case 'X':
                s += 8;
                break;
            case 'Q': case 'Z':
                s += 10;
                break;
            default:
                break;
        }
    }
}

void pp6() {
    printf("sizeof(short):\t\t%2hd\n", (short) sizeof(short));
    printf("sizeof(int):\t\t%2hd\n", (short) sizeof(int));
    printf("sizeof(long):\t\t%2hd\n", (short) sizeof(long));
    printf("sizeof(float):\t\t%2hd\n", (short) sizeof(float));
    printf("sizeof(double):\t\t%2hd\n", (short) sizeof(double));
    printf("sizeof(long double):\t%2hd\n", (short) sizeof(long double));
}

void pp7() {
    int n1, d1, n2, d2, n3, d3;
    char c;

    printf("Enter two fractions separated by an operator: ");
    scanf("%d/%d", &n1, &d1);
    c = getchar();
    scanf("%d/%d", &n2, &d2);

    switch (c) {
        case '+':
            n3 = (n1 * d2) + (n2 * d1);
            d3 = (d1 * d2);
            break;
        case '-':
            n3 = (n1 * d2) - (n2 * d1);
            d3 = (d1 * d2);
            break;
        case '*':
            n3 = (n1 * d2);
            d3 = (d1 * d2);
            break;
        case '/':
            n3 = (n1 * d2);
            d3 = (n2 * d1);
            break;
        default:
            return;
    }

    printf("The sum is %d/%d \n", n3, d3);
}

void pp8() {
    int h, m, t,
        d1 = 480,
        d2 = 583,
        d3 = 679,
        d4 = 767,
        d5 = 840,
        d6 = 945,
        d7 = 1140,
        d8 = 1305;
    char c;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &h, &m, &c);

    c = toupper(c);
    if (c == 'P') {
        t = ((h + 12) * 60) + m;
    } else {
        t = (h * 60) + m;
    }

    printf("Closest Departure time is ");
    if (t < d1 + (d2 - d1) / 2) {
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    } else if (t < d2 + (d3 - d2) / 2) {
        printf("9:43 a.m., arriving at 11:52 p.m.\n");
    } else if (t < d3 + (d4 - d3) / 2) {
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    } else if (t < d4 + (d5 - d4) / 2) {
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    } else if (t < d5 + (d6 - d5) / 2) {
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    } else if (t < d6 + (d7 - d6) / 2) {
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    } else if (t < d7 + (d8 - d7) / 2) {
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    } else {
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
    }
}

void pp9() {
    int h, m;
    char c;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &h, &m, &c);

    c = toupper(c);
    if (c == 'P') {
        h += 12;
    }

    printf("%2.2d:%2.2d\n", h, m);
}

void pp10() {
    int s = 0;
    char c;

    printf("Enter a sentence: ");
    do {
        c = getchar();
        if (c == '\n') {
            break;
        }
        c = toupper(c);
        switch (c) {
            case 'A': case 'E': case 'I':
            case 'O':  case 'U':
                s += 1;
                break;
        }
    } while (1);

    printf("Your sentence contains %d vowels.\n", s);
}

void pp11() {
    char c1, c2;

    printf("Enter a first and last name: ");
    c1 = getchar();
    while (c1 == ' ') {
        c1 = getchar();
    }
    while (getchar() != ' ') {
        continue;
    }

    do {
        c2 = getchar();
        if (c2 == '\n') {
            break;
        } else if (c2 == ' ') {
            continue;
        }
        printf("%c", c2);
    } while (1);

    printf(", %c.\n", c1);
}

void pp12() {
    float s1, s2;
    char c;

    printf("Enter an expression: ");
    scanf("%f", &s1);

    do {
        scanf("%c", &c);
        if (c == '\n') {
            break;
        }
        scanf("%f", &s2);
        switch (c) {
            case '+':
                s1 += s2;
                break;
            case '-':
                s1 -= s2;
                break;
            case '*':
                s1 *= s2;
                break;
            case '/':
                s1 /= s2;
                break;
        }
    } while (1);

    printf("Value of expression: %.1f\n", s1);
}

void pp13() {
    int s1 = 0, s2 = 1;
    char c;
    float t;

    printf("Enter an sentence: ");
    do {
        c = getchar();
        if (c == '\n') {
            break;
        } else if (c == ' ') {
            s2 += 1;
        } else {
            s1 += 1;
        }
    } while (1);

    t = (float) s1 /  s2;
    printf("Average word length: %.1f\n", t);
}

void pp14() {
    double x, y1 = 1.0, y2, z;

    printf("Enter a positive number: ");
    scanf("%lf", &x);
    do {
        y2 = y1;
        z = x / y1;
        y1 = (y1 + z) / 2;
    } while (fabs(y2 - y1) >= 1.e-4);

    printf("Square root: %.5f\n", y1);
}

/*
 * (a) 7
 * (b) 19
 * (c) 42
 * (d) 42
 * (e) 34
 * (f) 170
 * (g) 1754
 */
void pp15() {
    short n, s, i;

    printf("Enter a positive number: ");
    scanf("%hd", &n);
    s = n;

    for (i = n; i > 1; i -= 1) {
        s = s * (i - 1);
    }

    printf("Factiorial of %hd: %hd\n", n, s);
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
    pp13();
    pp14();
    pp15();
    return 0;
}
