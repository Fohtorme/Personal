#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

using namespace std;

int main()
{
    // Scanf value
    int n;
    // Array length, initial, final, value and greater value
    int al, i, f, v, gv = 0;
    // Create and initialize the array with specified length
    if(!~scanf("%d", &n)) return 0;
    al = n;
    std::vector<long> array (al);
    // Ignore this parameter
    if(!~scanf("%d", &n)) return 0;
    while (1) {
        // Initial index
        if(!~scanf("%d", &n)) break;
        i = n;
        // Final index
        if(!~scanf("%d", &n)) break;
        f = n;
        // Value to sum
        if(!~scanf("%d", &n)) break;
        v = n;
        // Increment each element between range in array
        std::for_each(array.begin()+i-1, array.begin()+f, [&v](long& d) { d+=v;});
    }
    // Print the result
    std::cout << *std::max_element(array.begin(),array.end());
    return 0;
}
