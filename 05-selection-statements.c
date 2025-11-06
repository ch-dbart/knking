#include <stdio.h>

/*
 *  1. (a) 1 (b) 1 (c) 1 (d) 0
 *  2. (a) 1 (b) 1 (c) 1 (d) 1
 *  3. (a) 1 3 4 5 (b) 0 7 8 9 (c) 1 8 8 9 (d) 1 2 1 1
 *  4. (i > j) - (i < j)
 *  5. Yes. It prints "0 is between 1 and 10".
 *  6. Yes. It does nothing.
 *  7. 17. 17.
 *  8. teenager = age > 12 && age < 20
 *  9. They are equivalent.
 * 10. onetwo
 * 11. switch (area_code) {
 *         case 229:
 *             printf("Albany\n");
 *             break;
 *          case 404: case 470: case 678: case 770:
 *              printf("Atlanta\n");
 *              break;
 *          case 478:
 *              printf("Macon\n");
 *              break;
 *          case 706: case 762:
 *              printf("Columbus\n");
 *              break;
 *          case 912:
 *              printf("Savannah\n");
 *              break;
 *          default:
 *              printf("Area code not recognized\n");
 *              break;
 *     }
 */

void pp1() {
    int n, d;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 10) {
        d = 1;
    } else if (n < 100) {
        d = 2;
    } else if (n < 1000) {
        d = 3;
    } else {
        d = 4;
    }

    printf("The number %d has %d digit(s)\n", n, d);
}

void pp2() {
    int h, m;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);
    printf("Equivalent 12-hour time: ");

    if (h < 13) {
        printf("%.2d:%.2d AM\n", h, m);
    } else {
        printf("%.2d:%.2d PM\n", (h - 12), m);
    }
}

void pp3() {
    int a;
    float p, v, c, r;

    printf("Enter amount of shares: ");
    scanf("%d", &a);
    printf("Enter values per share: ");
    scanf("%f", &p);
    v = a * p;

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

    if (a < 2000) {
        r = 33.0f + (.03f * a);
    } else {
        r = 33.0f + (.02f * a);
    }
    printf("Commission (rival): $%.2f\n", r);
}

void pp4() {
    int k;

    printf("Enter a wind speed (in knots): ");
    scanf("%d", &k);

    if (k < 1) {
        printf("Calm\n");
    } else if (k < 4) {
        printf("Light air\n");
    } else if (k < 28) {
        printf("Breeze\n");
    } else if (k < 48) {
        printf("Gale\n");
    } else if (k < 64) {
        printf("Storm\n");
    } else {
        printf("Hurricane\n");
    }
}

void pp5() {
    float a, t;

    printf("Enter amount of taxable income: ");
    scanf("%f", &a);

    if (a <= 750.0f) {
        t = (0.01f * a);
    } else if (a <= 2250.0f) {
        t = 7.5f + (.02f * (a - 750.0f));
    } else if (a <= 3750.0f) {
        t = 37.5f + (.03f * (a - 2250.0f));
    } else if (a <= 5250.0f) {
        t = 82.5f + (.04f * (a - 3750.0f));
    } else if (a <= 7000.0f) {
        t = 142.5f + (.05f * (a - 5250.0f));
    } else {
        t = 230.0f + (.06f * (a - 7000.0f));
    }

    printf("Tax due: $%.2f\n", t);
}

void pp6() {
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, c, s1, s2, t; 

    printf("Enter a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &c);

    s1 = d1 + d3 + d5 + d7 + d9 + d11;
    s2 = d2 + d4 + d6 + d8 + d10;
    t = 9 - ((((3 * s1) + s2) - 1) % 10);

    if (t == c) {
        printf("VALID\n");
    } else {
        printf("NOT VALID\n");
    }
}

void pp7() {
    int d1, d2, d3, d4, l1, s1, l2, s2, l, s;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &d1, &d2, &d3, &d4);

    if (d1 > d2) {
        l1 = d1;
        s1 = d2;
    } else {
        l1 = d2;
        s1 = d1;
    }
    if (d3 > d4) {
        l2 = d3;
        s2 = d4;
    } else {
        l2 = d4;
        s2 = d3;
    }

    l = (l1 > l2) ? l1 : l2;
    s = (s1 < s2) ? s1 : s2;

    printf("Largest: %d\n", l);
    printf("Smallest: %d\n", s);
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

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);
    t = (h * 60) + m;

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
    int m1, d1, y1, m2, d2, y2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    if (y1 < y2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
    } else if (y2 < y1) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
    } else if (m1 < m2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
    } else if (m2 < m1) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
    } else if (d1 < d2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
    } else if (d2 < d1) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
    } else {
        printf("%d/%d/%d is equal to %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
    }
}

void pp10() {
    int g;

    printf("Enter numerical grade: ");
    scanf("%d", &g);

    if (g > 100 || g < 0) {
        g = -11;
    }

    switch(g / 10) {
        case 0: case 1: case 2: case 3: case 4: case 5: 
            printf("Letter grade: F\n");
            break;
        case 6: 
            printf("Letter grade: E\n");
            break;
        case 7: 
            printf("Letter grade: C\n");
            break;
        case 8: 
            printf("Letter grade: B\n");
            break;
        case 9: case 10:
            printf("Letter grade: A\n");
            break;
        default:
            printf("Grade is not between 1 and 100\n");
            break;
    }
}

void pp11() {
    int n;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    switch (n / 10) {
        case 1:
            switch (n % 10) {
                case 0:
                    printf("ten\n");
                    break;
                case 1:
                    printf("eleven\n");
                    break;
                case 2:
                    printf("twelve\n");
                    break;
                case 3:
                    printf("thirteen\n");
                    break;
                case 4:
                    printf("fourteen\n");
                    break;
                case 5:
                    printf("fifteen\n");
                    break;
                case 6:
                    printf("sixteen\n");
                    break;
                case 7:
                    printf("seventeen\n");
                    break;
                case 8:
                    printf("eighteen\n");
                    break;
                case 9:
                    printf("nineteen\n");
                    break;
            }
            break;
       case 2:
           printf("twenty");
           break;
       case 3:
           printf("thirdy");
           break;
       case 4:
           printf("forty");
           break;
       case 5:
           printf("fifty");
           break;
       case 6:
           printf("sixty");
           break;
       case 7:
           printf("seventy");
           break;
       case 8:
           printf("eighty");
           break;
       case 9:
           printf("ninety");
           break;
    }

    if (n / 10 != 1) {
        switch (n % 10) {
            case 0:
                printf("\n");
                break;
            case 1:
                printf("-one\n");
                break;
            case 2:
                printf("-two\n");
                break;
            case 3:
                printf("-three\n");
                break;
            case 4:
                printf("-four\n");
                break;
            case 5:
                printf("-five\n");
                break;
            case 6:
                printf("-six\n");
                break;
            case 7:
                printf("-seven\n");
                break;
            case 8:
                printf("-eight\n");
                break;
            case 9:
                printf("-nine\n");
                break;
        }
    }
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
    return 0;
}
