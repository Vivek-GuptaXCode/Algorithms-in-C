#include <stdio.h>

#define MAX 100

long long catalan (int n)
{
    static long long cat[MAX];
    
    cat[0] = cat[1] = 1;

    for (int i = 2; i < n; i++)
    {
        cat[i] = cat[i - 1] * (4 * i - 2) / (i + 1);
    }
    return cat[n - 1];
}

int main (void)
{
    int n;
    printf("Which catalan number? ");
    scanf("%d", &n);
    
    printf("Catalan number %d is %lld\n", n, catalan(n));    
    return 0;
}
