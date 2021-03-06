#pragma once
#include <blacspp/types.hpp>
#include <type_traits>

namespace blacspp {
namespace detail {

  /**
   *  \brief A SFINAE struct to check if a type is BLACS enabled.
   *  
   *  @tparam T Type to query for BLACS support.
   *
   *  Type is queried by blacs_supported<T>::value (true/false)
   *  
   *  The following types are BLACS enabled:
   *    - blacs_int (i)
   *    - float     (s)
   *    - double    (d)
   *    - scomplex  (c)
   *    - dcomplex  (z)
   */
  template <typename T>
  struct blacs_supported : public std::false_type { };

  template<>
  struct blacs_supported< blacs_int > : public std::true_type { };
  template<>
  struct blacs_supported< float >     : public std::true_type { };
  template<>
  struct blacs_supported< double >    : public std::true_type { };
  template<>
  struct blacs_supported< scomplex >  : public std::true_type { };
  template<>
  struct blacs_supported< dcomplex >  : public std::true_type { };

  template <typename T, typename U = void>
  using enable_if_blacs_supported_t = 
    typename std::enable_if< blacs_supported<T>::value, U >::type;


  template <typename T, typename = std::void_t<>>
  struct has_data_member : public std::false_type { };

  template <typename T>
  struct has_data_member< T,
    std::void_t< decltype( std::declval<T>().data() ) >
  > : public std::true_type { };

  template <typename T>
  inline constexpr bool has_data_member_v = has_data_member<T>::value;

  template <typename T, typename = std::void_t<>>
  struct has_size_member : public std::false_type { };

  template <typename T>
  struct has_size_member< T,
    std::void_t< decltype( std::declval<T>().size() ) >
  > : public std::true_type { };

  template <typename T>
  inline constexpr bool has_size_member_v = has_size_member<T>::value;



}
}
