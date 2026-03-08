#pragma once

#include <memory>
#include <cstdlib>
#include <cstddef>

namespace cclib::cpp {

enum class Safety { 
    SAFE,
    UNSAFE
};

enum class Host { 
    HOST,
    DEVICE
};

template <typename T = float, Host HOST = Host::HOST, Safety SAFETY = Safety::UNSAFE>
class hc {
    T* data;
    size_t size;

    hc(size_t size) : size(size) {
        data = static_cast<T*>(std::malloc(size * sizeof(T)));
    }

    ~hc() {
        std::free(data);
    }

    const T& at(size_t x) const {
        return data[x];
    }

    T& at(size_t x) {
        return data[x];
    }

};

}

namespace cl = cclib::cpp;
