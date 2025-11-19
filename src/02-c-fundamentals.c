#include <stdio.h>

/*
 *  1. Yes. It needs a return statement with an integer value.
 *  2. (a). One directive and four statements.
 *     (b). Parkinson's Law:
 *          Work expands so as to fill the time
 *          available for its completion.
 *  3. int height = 8, length = 12, width = 10;
 *     printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);
 *  4. There isn't a pattern.
 *     int a, b, c;
 *     float x, y, z;
 *     printf("%d, %d, %d", a, b, c);
 *     printf("%f, %f, %f", x, y, z);
 *  5. (a). illegal
 *     (b). legal
 *     (c). legal
 *     (d). legal
 *  6. It isn't a good idea because the readability is weak.
 *  7. (a). keyword
 *     (b). no keyword
 *     (c). no keyword
 *     (d). no keyword
 *     (e). keyword
 *  8. fourteen
 *  9. answer = (3 * q - p * p) / 3;
 * 10. The text inside the printf statements.
 *     The return statement and zero.
 *     The include directive.
 */

void pp1() {
    printf("       *\n");
    printf("      * \n");
    printf("     *  \n");
    printf("*   *   \n");
    printf(" * *    \n");
    printf("  *     \n");
}

void pp2() {
    int r = 10;
    printf("%f\n", (4.0f / 3.0f) * 3.14159f * r * r * r);
}

void pp3() {
    int r;

    printf("Enter radius: ");
    scanf("%d", &r);

    printf("%f\n", (4.0f / 3.0f) * 3.14159f * r * r * r);
}

void pp4() {
    float a;

    printf("Enter an amount: ");
    scanf("%f", &a);

    printf("With tax added: %.2f\n", a * 1.05f);
}

void pp5() {
    int x, r;

    printf("Enter value for x: ");
    scanf("%d", &x);

    r = (3 * x * x * x * x * x);
    r += (2 * x * x * x * x);
    r -= (5 * x * x * x);
    r -= (x * x);
    r += (7 * x);
    r -= 6;

    printf("%d\n", r);
}

void pp6() {
    int x;

    printf("Enter value for x: ");
    scanf("%d", &x);

    printf("%d\n", ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);
}

void pp7() {
    int a, b;

    printf("Enter a dollar amount: ");
    scanf("%d", &a);

    b = a / 20;
    printf("$20 bills: %d\n", b);
    a -= b * 20;
    b = a / 10;
    printf("$10 bills: %d\n", b);
    a -= b * 10;
    b = a / 5;
    printf(" $5 bills: %d\n", b);
    a -= b * 5;
    printf(" $1 bills: %d\n", a);
}

void pp8() {
    float a, i, m, r;

    printf("Enter amount of loan: ");
    scanf("%f", &a);
    printf("Enter interest rate: ");
    scanf("%f", &i);
    printf("Enter monthly payment: ");
    scanf("%f", &m);

    r = (i / 12 / 100) + 1;
    a = (a - m) * r;
    printf("Balance remaining after first payment: $%.2f\n", a);
    a = (a - m) * r;
    printf("Balance remaining after second payment: $%.2f\n", a);
    a = (a - m) * r;
    printf("Balance remaining after third payment: $%.2f\n", a);
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
    return 0;
}
