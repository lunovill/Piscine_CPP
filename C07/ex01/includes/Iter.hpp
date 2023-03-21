#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void    iter(T *tab, size_t size, void (*ft)(size_t &, T &)) {
    for (size_t i = 0; i < size; i++) ft(i, tab[i]);
    return;
}

#endif