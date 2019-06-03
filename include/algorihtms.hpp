template<class T>
constexpr decltype(auto) add(T&& a, T&& b) {
    return a + b;
}
