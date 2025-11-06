#include <stdio.h>

/*
 * 1. (a)   86,1040
 *    (b) 3.02530e+01
 *    (c) 83.1620
 *    (d) 1e-06
 * 2. (a) printf("%-8.1e\n", x)
 *    (b) printf("%10.6e\n", x)
 *    (c) printf("%-8.3f\n", x)
 *    (d) printf("%6.0f\n", x)
 * 3. (a) equivalent
 *    (b) not equivalent
 *        The second expression allows any number of spaces before the hyphens.
 *    (c) not equivalent
 *        The second expression causes the program to search for an additional
 *        non-whitespace character.
 *    (d) equivalent
 * 4. i = 10, x = .3, j = 5
 * 5. x = 12.3, i = 45, y = .6
 * 6. scanf("%d /%d", &num1, &denom1);
 *    scanf("%d /%d", &num2, &denom2);
 */

void pp1() {
    int d, m, y;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("You entered the date %d%.2d%.2d\n", y, m, d);
}

void pp2() {
    int n, d, m, y;
    float p;

    printf("Enter item number: ");
    scanf("%d", &n);
    printf("Enter unit price: ");
    scanf("%f", &p);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t$%-4.2f\t%.2d/%.2d/%d\n", n, p, m, d, y);
}

void pp3() {
    int x, g, p, n, c;
    
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &x, &g, &p, &n, &c);
    
    printf("GS1 prefix: %d\n", x);
    printf("Group identifier: %d\n", g);
    printf("Publisher code: %d\n", p);
    printf("Item number: %d\n", n);
    printf("Check digit: %d\n", c);
}

void pp4() {
    int f, s, t;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &f, &s, &t);

    printf("You entered %d.%d.%d\n", f, s, t);
}

void pp5() {
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
        &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9,
        &n10, &n11, &n12, &n13, &n14, &n15, &n16);

    printf("%2d %2d %2d %2d\n", n1, n2, n3, n4);
    printf("%2d %2d %2d %2d\n", n5, n6, n7, n8);
    printf("%2d %2d %2d %2d\n", n9, n10, n11, n12);
    printf("%2d %2d %2d %2d\n", n13, n14, n15, n16);

    printf("Row sums: %d %d %d %d\n",
        (n1 + n2 + n3 + n4),
        (n5 + n6 + n7 + n8),
        (n9 + n10 + n11 + n12),
        (n13 + n14 + n15 + n16)
    );
    printf("Column sums: %d, %d, %d, %d\n",
        (n1 + n5 + n9 + n13),
        (n2 + n6 + n10 + n14),
        (n3 + n7 + n11 + n15),
        (n4 + n8 + n12 + n16)
    );
    printf("Diagonal sums: %d %d\n",
        (n1 + n6 + n11 + n16),
        (n4 + n7 + n10 + n13)
    );
}

void pp6() {
    int n1, d1, n2, d2;

    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &n1, &d1, &n2, &d2);

    printf("The sum is %d/%d \n",
        ((n1 * d2) + (n2 * d1)),
        (d1 * d2)
    );
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
