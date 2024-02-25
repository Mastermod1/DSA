#include <cassert>
#include <iostream>
#include <algorithm>

int loop_gcd(int a, int b)
{
    while(a != 0 and b != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return std::max(a, b);
}

int recursive_gcd(int a, int b)
{
    if (a == 0)
        return b;
    return recursive_gcd(b % a, a);
}

int extended_gcd(int a, int b, int& x, int& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_gcd(b % a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

int main()
{
    assert(loop_gcd(5,17) == 1);
    assert(loop_gcd(17,5) == 1);

    assert(loop_gcd(12,0) == 12);
    assert(loop_gcd(0,12) == 12);

    assert(loop_gcd(12,36) == 12);
    assert(loop_gcd(36,12) == 12);

    assert(loop_gcd(15,35) == 5);
    assert(loop_gcd(35,15) == 5);


    assert(recursive_gcd(5,17) == 1);
    assert(recursive_gcd(17,5) == 1);

    assert(recursive_gcd(12,0) == 12);
    assert(recursive_gcd(0,12) == 12);

    assert(recursive_gcd(12,36) == 12);
    assert(recursive_gcd(36,12) == 12);

    assert(recursive_gcd(15,35) == 5);
    assert(recursive_gcd(35,15) == 5);


    int x, y;
    assert(extended_gcd(12, 36, x, y) == 12);
    assert(12 * x + 36 * y == 12);

    assert(extended_gcd(36, 12, x, y) == 12);
    assert(36 * x + 12 * y == 12);

    assert(extended_gcd(5, 17, x, y) == 1);
    assert(5 * x + 17 * y == 1);
}
