#pragma once

#define GETTER_SETTER(X)                                                       \
    [[nodiscard]] auto get##X() const noexcept -> decltype(m##X)               \
    {                                                                          \
        return m##X;                                                           \
    }                                                                          \
    void set##X(const decltype(m##X)& it)                                      \
    {                                                                          \
        m##X = it;                                                             \
    }                                                                          \
    void set##X(decltype(m##X)&& it)                                           \
    {                                                                          \
        m##X = std::move(it);                                                  \
    }
