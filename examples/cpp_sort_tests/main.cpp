#include <cclib_cpp/cclib_cpp.hpp>

#include <vector>
#include <iostream>

template <typename T>
void insertion_sort(std::vector<T>& data) {
    size_t n = data.size();

    for (int i = 1; i < n; i++) {
        T key = data[i];

        // Here size_t fucks up the program since we have j = -1 at some point after while.
        int j = i-1;

        while(j >= 0 && data[j] < key) {
            // std::cout << "deb: " << j << " " << data[j] << " " << key << std::endl;
            data[j+1] = data[j];

            j--;
        }
        data[j+1] = key;
    }

}

int main() {
    cclib::cpp::hello();

     std::vector<int> test1 = {4, 5, 3, 2, 1};
    //std::vector<int> test1 = {1, 2, 3,5, 4};

    for (const auto& i : test1) std::cout << i << " ";
    std::cout << std::endl;

    insertion_sort(test1);

    for (const auto& i : test1) std::cout << i << " ";
    std::cout << std::endl;


}
