#include <array>
#include <cclib_cpp/cclib_cpp.hpp>

#include <iterator>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

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

template <typename T>
void selection_sort(std::vector<T>& A) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int min = std::numeric_limits<int>::max();
        int idx;

        for(int j = i; j < n; j++) {
            if (A[j] < min) {
                min = A[j];
                idx = j;
            }
        }

        std::swap(A[i], A[idx]);
    }
}

template <typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
    int nl = q - p + 1; // Len A[p, q]
    int nr = r - q; // Len A[q+1, r]

    std::vector<T> L(nl);
    std::vector<T> R(nr);

    std::cout << "Before" << std::endl;

    for (const auto i : L) std::cout << i << " ";
    std::cout << std::endl;
    for (const auto i : R) std::cout << i << " ";
    std::cout << std::endl;

    std::copy(A.begin() + p, A.begin() + q + 1, L.begin()); // end needs to be A.begin + n + 1
    std::copy(A.begin() + q+1, A.begin() + r + 1, R.begin());

    std::cout << "After" << std::endl;
    for (const auto i : L) std::cout << i << " ";
    std::cout << std::endl;
    for (const auto i : R) std::cout << i << " ";
    std::cout << std::endl;

    int il = 0;
    int ir = 0;
    int ia = p;

    while (il < nl && ir < nr) {
        if (L[il] <= R[ir]) {
            A[ia] = L[il];
            il++;
        }
        else {
            A[ia] = R[ir];
            ir++;
        }

        ia++;
    }

    while (il < nl) {
        A[ia] = L[il];
        ia++;
        il++;
    }

    while (ir < nr) {
        A[ia] = R[ir];
        ia++;
        ir++;
    }
}
template <typename T>
void merge_sort_helper(std::vector<T>& A, int p, int r) {
    if (p >= r) return;

    int q = (p + r) / 2;

    merge_sort_helper(A, p, q);
    merge_sort_helper(A, q+1, r);

    merge(A, p, q, r);
    
    std::cout << "skibid" << std::endl;
    for (const auto& i : A) std::cout << i << " ";
    std::cout << std::endl;
}

template <typename T>
void merge_sort(std::vector<T>& A) {
    merge_sort_helper(A, 0, A.size() -1);
}




int main() {
    cclib::cpp::hello();

    std::vector<int> test1 = {4, 5, 3, 2, 1};
    //std::vector<int> test1 = {1, 2, 3,5, 4};

    for (const auto& i : test1) std::cout << i << " ";
    std::cout << std::endl;

    //insertion_sort(test1);
    merge_sort(test1);

    std::cout << "mer" << std::endl;
    for (const auto& i : test1) std::cout << i << " ";
    std::cout << std::endl;


}
