#include <stdio.h>
#define MAX 100

long long fibonacci (int n)
{
    // use memorization to store the values of the fibonacci series
    static long long f[MAX + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n - 1];
}

int main (void)
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        printf("%lld ", fibonacci(i));
    return 0;
}
