#include <stdio.h>

/*
 *  1. (a) 1 2 (b) 0 (c) 1 (d) 0
 *  2. Yes (C99). In mathematical fractions a minus sign before the fraction is
 *     equivalent to a minus sign within either the nominator/denominator.
 *  3. (a) 1 (b) -1, -2 (c) -1, -2 (d) 1 
 *  4. (a) 1 (b) -1 (c) -1 (d) 1
 *  5. (a) 3 (b) -3, 2 (c) -3, 2 (d) -3, 2
 *  6. (a) 3 (b) -3 (c) 3 (d) -3
 *  7. "9 - ((x - 1) % 10)" is not equivalent to "10 - (x % 10)" If the total
 *     is something to the power of 10, then the modulo 10 operation would
 *     result in zero. The check digit would remain 10 instead of 0.
 *  8. Yes, because the total to the power of 10 problem in the previous
 *     question would be resolved.
 *  9. (a) 63 8 (b) 3 2 1 (c) 2 -1 3 (d) 0 0 0
 * 10. (a) 12 12 (b) 3 4 (c) 2 8 (d) 6 9
 * 11. (a) 0 2 (b) 4 11 6 (c) 0 8 7 (d) 3 4 5 4
 * 12. (a) 6 16 (b) 6 -7 (c) 6 23 (d) 6 15
 * 13. Both ++i and i++ have the side effect to increment i by one. The
 *     expression ++i is equivalent to (i += 1) because both fetch the
 *     increased value of i (i + 1).
 * 14. (a) (((a * b) - (c * d)) + e) (b) ((((a / b) % c) / d)
 *     (c) ((((-a) - b) + c) - (+d)) (d) (((a * (-b)) / c) - d)
 * 15. (a) 3, 2 (b) 0, 2 (c) 1, 2 (d) 1, 3
 */

void pp1() {
    int n;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    printf("The reversal is: %d%d\n", n % 10, n / 10);
}

void pp2() {
    int n;

    printf("Enter a three-digit number: ");
    scanf("%d", &n);

    printf("The reversal is: %d%d%d\n", n % 10, n / 10 % 10, n / 100);
}

void pp3() {
    int n1, n2, n3;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &n1, &n2, &n3);

    printf("The reversal is: %d%d%d\n", n3, n2, n1);
}

void pp4() {
    int n, o1, o2, o3, o4, o5;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    o1 = n % 8;
    o2 = (n / 8) % 8;
    o3 = (n / (8 * 8)) % 8;
    o4 = (n / (8 * 8 * 8)) % 8;
    o5 = (n / (8 * 8 * 8 * 8)) % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", o5, o4, o3, o2, o1);
}

void pp5() {
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, s1, s2, t; 

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5);

    s1 = d + i2 + i4 + j1 + j3 + j5;
    s2 = i1 + i3 + i5 + j2 + j4;
    t = (3 * s1) + s2;
    t = 9 - ((t - 1) % 10);

    printf("Check digit: %d\n", t);
}

void pp6() {
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, s1, s2, c;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);

    s1 = n2 + n4 + n6 + n8 + n10 + n12;
    s2 = n1 + n3 + n5 + n7 + n9 + n11;
    c = (s1 * 3) + s2;
    c =  9 - ((c - 1) % 10);

    printf("Check digit: %d\n", c);
}

int main(void) {
    pp1();
    pp2();
    pp3();
    pp4();
    pp5();
    pp6();
    return 0;
}
