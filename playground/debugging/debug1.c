#include <stdio.h>

struct Human {
    char* name;
    int age;
    int num;
};

int main() {
    struct Human h;
    h.name = "Daniel";
    //h.age = 45;
    //printf("%d\n",h.age);

    long double start;
    long double end;
    long double step;

    printf("Please enter start: ");
    scanf("%Lf", &start);

    printf("Please enter end: ");
    scanf("%Lf", &end);

    printf("Please enter step: ");
    scanf("%Lf", &step);

    while (start != end) { // simulates a wrong program
        printf("%Lf\n", start);
        start += step;
    }


    return 0;
}