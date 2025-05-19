#ifndef UNIQUE_RESOURCE_H
#define UNIQUE_RESOURCE_H

#include <functional>
#include <memory>

template<typename T,auto close_fn>
class unique_resource {
public:
    unique_resource() {p = nullptr;}
    explicit unique_resource(T _p) {this->p = _p;}
    explicit unique_resource(unique_resource&& other)noexcept {
        p = std::move(other.p);
        other.p = nullptr;
    }

    // Disallow copying
    unique_resource(const unique_resource&) = delete;
    unique_resource& operator=(const unique_resource&) = delete;

    ~unique_resource() {
        if(p) close_fn(p);
    }
    T get(){return this->p;}
    explicit operator bool()const{return this->p!=nullptr;}
    auto operator&() {return &this->p;}
    T operator->() {return this->p;}
private:
    T p;
};

using unique_free_str = unique_resource<char*,free>;

#endif
