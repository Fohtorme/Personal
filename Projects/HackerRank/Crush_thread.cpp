#include <bits/stdc++.h>
#include <vector>       // std::vector
#include <thread>         // std::thread

using namespace std;

int main()
{
    // Sum threads
    std::vector<std::thread> sum;
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
        //std::thread first (std::for_each, array.begin()+i-1, array.begin()+f, [&v](long& d) { d+=v;});
        //first.join();
        try{
            sum.push_back(std::thread([&array, i, f, v]()
            {
                std::for_each(array.begin()+i-1, array.begin()+f, [&v](long& d) { d+=v;});
            }));
        } catch (exception& e) {
            std::for_each(sum.begin(), sum.end(), [](std::thread &t)
            {
                t.join();
            });
            sum.clear();
        }

    }
    std::for_each(sum.begin(), sum.end(), [](std::thread &t)
    {
        t.join();
    });
    sum.clear();

    /*for(int idx = 0; idx < al; idx++){
        printf("%d\n", array[idx]);
    }*/

    // Print the result
    std::cout << *std::max_element(array.begin(),array.end());
    return 0;
}
