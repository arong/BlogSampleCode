#include <string>
#include <type_traits>

void func(int x) {}
static_assert(std::is_invocable<decltype(func), int>::value);
static_assert(!std::is_invocable<decltype(func), std::string>::value);

int main() {
  // is_integral
  static_assert(std::is_integral<int>::value);
  static_assert(std::is_integral_v<int>);  // 上例的简写

  static_assert(!std::is_integral_v<double>);

  // is_floating_point
  static_assert(std::is_floating_point<float>::value);
  static_assert(std::is_floating_point_v<float>);

  static_assert(!std::is_floating_point_v<std::string>);

  // is_pointer
  static_assert(std::is_pointer<int*>::value);
  static_assert(std::is_pointer_v<int*>);

  static_assert(!std::is_pointer_v<int>);

  // is_fundamental
  static_assert(std::is_fundamental<int>::value);
  static_assert(std::is_fundamental<bool>::value);
  static_assert(std::is_fundamental<double>::value);
  static_assert(std::is_fundamental<void>::value);
  struct MyStr {};
  static_assert(std::is_fundamental<std::string>::value == false);
  static_assert(std::is_fundamental<MyStr>::value == false);

  // is_object
  static_assert(std::is_object<std::string>::value);
  static_assert(std::is_compound<std::string>::value);

  // is_reference
  static_assert(std::is_reference<int&>::value);
  static_assert(std::is_reference<int&&>::value);
  static_assert(std::is_reference<int>::value == false);

  // is_const
  static_assert(std::is_const<const int>::value);
  static_assert(!std::is_const<int>::value);

  // is_volatile
  static_assert(std::is_volatile<volatile int>::value);
  static_assert(!std::is_volatile<int>::value);

  // is_trivial
  struct TrivialStruct {
    int x;
  };
  static_assert(std::is_trivial<TrivialStruct>::value);

  struct NonTrivialStruct {
    NonTrivialStruct() {}
    ~NonTrivialStruct() {}
    int x;
  };
  static_assert(!std::is_trivial<NonTrivialStruct>::value);

  // is_constructible
  static_assert(std::is_constructible<std::string, const char*>::value);
  static_assert(!std::is_constructible<int, std::string>::value);

  // is_default_constructible
  struct DC {
    DC() = default;
  };
  static_assert(std::is_default_constructible<DC>::value);

  struct NonDC {
    NonDC(int x) {}
  };
  static_assert(!std::is_default_constructible<NonDC>::value);

  // is_nothrow_constructible
  struct NoThrow {
    NoThrow() noexcept {}
  };
  static_assert(std::is_nothrow_constructible<NoThrow>::value);

  struct MayThrow {
    MayThrow() {}
  };
  static_assert(!std::is_nothrow_constructible<MayThrow>::value);

  // is_move_assignable
  struct MS {
    MS& operator=(MS&&) noexcept { return *this; }
  };
  static_assert(std::is_move_assignable<MS>::value);
  struct MS1 {};
  static_assert(std::is_move_assignable<MS1>::value);

  struct NonMS {
    NonMS& operator=(NonMS&&) = delete;
  };
  static_assert(!std::is_move_assignable<NonMS>::value);

  // is_destructible
  struct DestructibleStruct {
    ~DestructibleStruct() {}
  };
  static_assert(std::is_destructible<DestructibleStruct>::value);

  struct NonDestructibleStruct {
   private:
    ~NonDestructibleStruct() {}
  };
  static_assert(!std::is_destructible<NonDestructibleStruct>::value);

  // is_same
  static_assert(std::is_same<int, int>::value);
  static_assert(!std::is_same<int, double>::value);

  // is_base_of
  class Base {};
  class Derived : public Base {};
  static_assert(std::is_base_of<Base, Derived>::value);
  static_assert(!std::is_base_of<Derived, Base>::value);

  // is_convertible
  static_assert(std::is_convertible<int, double>::value);
  static_assert(!std::is_convertible<std::string, int>::value);

  // remove_cv
  using CVType = const int;
  using NonCVType = std::remove_cv<CVType>::type;
  static_assert(std::is_same<NonCVType, int>::value);

  // remove_const
  using ConstType = const int;
  using NonConstType = std::remove_const<ConstType>::type;
  static_assert(std::is_same<NonConstType, int>::value);

  // add_cv
  using NonCVType2 = int;
  using CVType2 = std::add_cv<NonCVType2>::type;
  static_assert(std::is_same<CVType2, const volatile int>::value);

  // add_const
  using NonConstType2 = int;
  using ConstType2 = std::add_const<NonConstType2>::type;
  static_assert(std::is_same<ConstType2, const int>::value);

  // add_volatile
  using NonVolatileType2 = int;
  using VolatileType2 = std::add_volatile<NonVolatileType2>::type;
  static_assert(std::is_same<VolatileType2, volatile int>::value);

  using RefType = int&;
  using NonRefType = std::remove_reference<RefType>::type;
  static_assert(std::is_same<NonRefType, int>::value);

  using NonRefType2 = int;
  using LRefType = std::add_lvalue_reference<NonRefType2>::type;
  static_assert(std::is_same<LRefType, int&>::value);

  using NonRefType3 = int;
  using RRefType = std::add_rvalue_reference<NonRefType3>::type;
  static_assert(std::is_same<RRefType, int&&>::value);

  using PointerType = int*;
  using NonPointerType = std::remove_pointer<PointerType>::type;
  static_assert(std::is_same<NonPointerType, int>::value);

  using NonPointerType2 = int;
  using PointerType2 = std::add_pointer<NonPointerType2>::type;
  static_assert(std::is_same<PointerType2, int*>::value);

  using UnsignedType = unsigned int;
  using SignedType = std::make_signed<UnsignedType>::type;
  static_assert(std::is_same<SignedType, int>::value);

  using SignedType2 = int;
  using UnsignedType2 = std::make_unsigned<SignedType2>::type;
  static_assert(std::is_same<UnsignedType2, unsigned int>::value);

  int arr[10];
  using DecayedType = std::decay<decltype(arr)>::type;
  static_assert(std::is_same<DecayedType, int*>::value);

  using CommonType = std::common_type<int, unsigned int>::type;
  static_assert(std::is_same<CommonType, unsigned int>::value);
}
