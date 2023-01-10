#include <stdio.h>
#include <math.h>
long long int res = 1;
long long int power(long long int x)
{
    long long int y;
    for (y = x; y >= 1; y--)
    {
        res = res * x;
    }
    return res;
}
long long int findsize(long long int value)
{
    long long int count = 0;
    while (value != 0)
    {
        count++;
        value /= 10;
    }
    if (count == 0)
    {
        return count;
    }
}
long long int KARATSUBA(long long int x, long long int y, long long int n)
{

    long long int p;
    if (n == 1)
    {
        p = x * y;
    }
    else
    {

        long long int m = (power(n / 2));
        long long int x2 = x % m;
        long long int x1 = x / m;
        long long int y2 = y % m;
        long long int y1 = y / m;
        long long int u = KARATSUBA(x1, y1, n / 2);
        long long int W = KARATSUBA(x1 - x2, y1 - y2, n / 2);
        long long int v = KARATSUBA(x2, y2, n / 2);
        p = power(n) * u + (power(n / 2)) * (u + v - W) + v;
    }

    return p;
}
long long int main()
{
    long long int x, y, n, a, b;
    printf("enter the 1st number: ");
    scanf("%lld", &x);

    printf("enter the 2nd number:  ");
    scanf("%lld", &y);

    n = findsize(x);

    KARATSUBA(x, y, n);
    printf("multipication  is %lld\n", KARATSUBA(x, y, n));

    return 0;
}
