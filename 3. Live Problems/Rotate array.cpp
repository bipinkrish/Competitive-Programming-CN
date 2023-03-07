#include <bits/stdc++.h>
using namespace std;

void rotate(int *input, int d, int n)
{
    reverse(input, input + d);
    reverse(input + d, input + n);
    reverse(input, input + n);
}