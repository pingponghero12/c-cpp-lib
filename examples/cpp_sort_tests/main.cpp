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
int recursive_binary_search_helper(std::vector<T>& A, int p, int r, T x) {
    int q = (p + r) / 2;

    if (p > r) return -1;
    if (A[q] == x) return q;
    else if(A[q] > x) return recursive_binary_search_helper(A, p, q-1, x);
    else return recursive_binary_search_helper(A, q+1, r, x);
}

template <typename T>
int recursive_binary_search(std::vector<T>& A, T x) { 
    // We return the index
    return recursive_binary_search_helper(A, 0, A.size() - 1, x);
}

template <typename T>
void recursive_insertion_sort_helper(std::vector<T>& A, int n) {
    if (n == 0) return;

    recursive_insertion_sort_helper(A, n-1);

    T key = A[n];

    // Here size_t fucks up the program since we have j = -1 at some point after while.
    int j = n-1;

    while(j >= 0 && A[j] > key) {
        // std::cout << "deb: " << j << " " << data[j] << " " << key << std::endl;
        A[j+1] = A[j];

        j--;
    }

    A[j+1] = key;

    return;
}

template <typename T>
void recursive_insertion_sort(std::vector<T>& A) {
    size_t n = A.size();

    recursive_insertion_sort_helper(A, n-1);
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

    std::copy(A.begin() + p, A.begin() + q + 1, L.begin()); // end needs to be A.begin + n + 1
    std::copy(A.begin() + q+1, A.begin() + r + 1, R.begin());

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
}

template <typename T>
void merge_sort(std::vector<T>& A) {
    merge_sort_helper(A, 0, A.size() -1);
}

template <typename T>
bool find_if_two_sum_to_x(std::vector<T>& A, T x) {
    size_t n = A.size();
    std::vector<T> Acopy(A);
    std::sort(Acopy.begin(), Acopy.end());

    for (int i = 0; i < n; i++) {
        if (Acopy[i] == x/2 && x%2 == 0) {
            if (i != n-1 && Acopy[i+1] == Acopy[i]) {
                return true;
            }
            else if (i == n-1) return false;
        }

        if(int dupa = recursive_binary_search(Acopy, x-Acopy[i]) >= 0) {

            return true;
        }
    }
    return false;
}

int main() {
    cclib::cpp::hello();

    std::vector<int> test1 = {4, 5, 3, 2, 1};
    //std::vector<int> test1 = {1, 2, 3,5, 4};

    for (const auto& i : test1) std::cout << i << " ";
    std::cout << std::endl;

    //insertion_sort(test1);
    //merge_sort(test1);
    recursive_insertion_sort(test1);

    std::cout << "rec" << std::endl;
    for (const auto& i : test1) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "find if " << find_if_two_sum_to_x(test1, 10) << std::endl;

}
