#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

using namespace std;

struct toSum{
    int i;
    int f;
    int v;
};

int main()
{
    // Sum threads
    std::vector<std::thread> sum;
    // Scanf value
    int n;
    // Array length, parameter length, index and greater value
    int al, pl, id, gv = 0;
    // Create and initialize the array with specified length
    if(!~scanf("%d", &n)) return 0;
    al = n;
    std::vector<long> array (al);
    // Arguments used to sum
    if(!~scanf("%d", &n)) return 0;
    pl = n;
    std::vector<toSum> to_sum (pl);
    // Get all parameters
    for(int x = 0; x < pl; x++){
        // Initial index
        if(!~scanf("%d", &n)) break;
        to_sum[x].i = n;
        // Final index
        if(!~scanf("%d", &n)) break;
        to_sum[x].f = n;
        // Value to sum
        if(!~scanf("%d", &n)) break;
        to_sum[x].v = n;
    }
    // For each element in array
    for(int y = 0; y < al; y++){
        try{
            sum.push_back(std::thread([&array, &to_sum, y, &pl]()
            {
                for(int x = 0; x < pl; x++){
                    if(y >= to_sum[x].i &&
                       y <= to_sum[x].f){
                        array[y] += to_sum[x].v;
                    }
                }
            }));
        } catch (exception& e) {
            // Finalize threads to free memory
            std::for_each(sum.begin(), sum.end(), [](std::thread &t)
            {
                t.join();
            });
            sum.clear();
        }
    }
    // Finalize remaining threads
    std::for_each(sum.begin(), sum.end(), [](std::thread &t)
    {
        t.join();
    });
    sum.clear();
    // Print the result
    std::cout << *std::max_element(array.begin(),array.end());
    return 0;
}
