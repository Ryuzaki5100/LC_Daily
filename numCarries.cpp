#include <bits/stdc++.h>
using namespace std;
int numberOfCarries(int a, int b)
{
    int totalCarry = 0, carry = 0;
    while (a && b)
        carry = (a % 10 + b % 10 + carry) / 10, totalCarry += carry, a /= 10, b /= 10;
    while (a % 10 == 9 && carry)
        totalCarry++, a /= 10;
    while (b % 10 == 9 && carry)
        totalCarry++, b /= 10;
    return totalCarry;
}
int main()
{
    cout << numberOfCarries(9999986, 214);
}