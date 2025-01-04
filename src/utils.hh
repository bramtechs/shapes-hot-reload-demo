#pragma once
#include <utility>

#define GETTER(X)                                                \
    [[nodiscard]] auto get##X() const noexcept -> decltype(m##X) \
    {                                                            \
        return m##X;                                             \
    }

#define GETTER_SETTER(X)                                                       \
    GETTER(X)                                                                  \
    void set##X(const decltype(m##X)& it)                                      \
    {                                                                          \
        m##X = it;                                                             \
    }                                                                          \
    void set##X(decltype(m##X)&& it)                                           \
    {                                                                          \
        m##X = std::move(it);                                                  \
    }
