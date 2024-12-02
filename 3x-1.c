#include <stdio.h>
#include <stdbool.h>
int collatzSteps(unsigned long long int num)
{

    long int steps = 0;

    while (num !=1)
    {
    printf("Step %d: %llu\n", steps, num);
        if (num % 2 == 0)
        {
        num /= 2;
        }
        else
        {
        num = num * 3 + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    unsigned long long int num;
    printf("Enter a number greater than 0: ");
    scanf("%llu", &num);

    if (num <= 0)
    {
    printf("Invalid Input");
    }
    int steps = collatzSteps(num);
    printf("Step %d: 1\n", steps);
}