#include <string>
#include <array>
#include <algorithm>
#include <cassert>
 
#include "task.hh"
 
static_assert(add(1, 2) == 3);
 
struct User {
    int id;
    constexpr User operator+(User u) { return User{id+u.id}; }
};
static_assert(add(User{1}, User{2}).id == 3);
 
template<class T, int N>
struct Array {
    std::array<T, N> a;
    template<int M>
    Array<T, N+M> operator+(const Array<T, M>& other) {
        Array<T, N+M> result;
        std::copy(a.begin(), a.end(), result.a.begin());
        std::copy(other.a.begin(), other.a.end(), result.a.begin() + N);
        return result;
    }
    bool operator==(const Array& other) {
        return std::equal(a.begin(), a.end(), other.a.begin());
    }
};
 
 
int main() {
    using namespace std::literals::string_literals;
    assert(add("abc"s, "cde"s) == "abccde"s);
    assert((add(Array<int, 1>{1}, Array<int, 1>{2}) == Array<int, 2>{1,2}));
}
