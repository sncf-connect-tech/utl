#pragma once

#include "utl/pipes/all.h"
#include "utl/pipes/is_range.h"

namespace utl {

template <typename T>
auto make_range(T&& t) {
  using Type = std::remove_const_t<std::remove_reference_t<T>>;
  if constexpr (is_range<Type>::value) {
    return t;
  } else if constexpr (std::is_pointer_v<Type>) {
    return all(*t);
  } else {
    return all(std::forward<T>(t));
  }
}

}  // namespace utl