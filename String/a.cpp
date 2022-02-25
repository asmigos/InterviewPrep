#include <iostream>
using namespace std;
 
int count_num_finger(int n)
{
    int r = n % 8;
    if (r == 0)
        return 2;
    if (r < 5)
        return r;
    else
        return 10 - r;
}
 
// Driver code
int main()
{
    int n;
    n = 1000;
    cout << count_num_finger(n);
 
    return 0;
}