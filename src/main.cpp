#include "nstl/type_traits"

int main() {
    static_assert(std::true_type::value == true, "true_type has incorrect value type");
    const std::true_type::value_type tt_vt = false;
    static_assert(tt_vt == false, "true_type has incorrect type");

    static_assert(std::false_type::value == false, "false_type has value type");
    const std::false_type::value_type ft_vt = true;
    static_assert(ft_vt == true, "false_type has incorrect type");

    std::remove_const<const int>::type rc_ci;
    rc_ci = 10;
    std::remove_const<int>::type rc_i;

    std::remove_volatile<volatile int>::type rv_vi;
    std::remove_volatile<int>::type rv_i;

    std::remove_cv<const volatile int>::type rcv_cvi;
    rcv_cvi = 20;
    std::remove_cv<const int>::type rcv_ci;
    rcv_ci = 30;
    std::remove_cv<volatile int>::type rcv_vi;
    std::remove_cv<int>::type rcv_i;

    std::add_const<int>::type ac_i = 0;
    std::add_const<const int>::type ac_ci = 0;

    std::add_volatile<int>::type av_i;
    std::add_volatile<volatile int>::type av_vi;

    static_assert(std::is_void<void>::value == true, "is_void is incorrect for void types");
    static_assert(std::is_void<int[]>::value == false, "is_void is incorrect for non-void types");

    static_assert(std::is_null_pointer<std::nullptr_t>::value == true, "is_null_pointer is incorrect for nullptr types");
    static_assert(std::is_null_pointer<int[]>::value == false, "is_null_pointer is incorrect for non-nullptr types");

    static_assert(std::is_integral<int>::value == true, "is_integral is incorrect for int type");
    //TODO(vim): More tests for is_integral

    static_assert(std::is_floating_point<float>::value == true, "is_floating_point is incorrect for float type");
    static_assert(std::is_floating_point<double>::value == true, "is_floating_point is incorrect for double type");
    static_assert(std::is_floating_point<long double>::value == true, "is_floating_point is incorrect for long double type");
    static_assert(std::is_floating_point<int>::value == false, "is_floating_point is incorrect for int type");

    static_assert(std::is_array<int[]>::value == true, "is_array is incorrect for int[]");
    static_assert(std::is_array<int[20]>::value == true, "is_array is incorrect for int[20]");
    static_assert(std::is_array<int>::value == false, "is_array is incorrect for int");

    static_assert(std::is_pointer<int*>::value == true, "is_pointer is incorrect for int*");
    static_assert(std::is_pointer<int>::value == false, "is_pointer is incorrect for int");

    static_assert(std::is_lvalue_reference<int&>::value == true, "is_lvalue_reference is incorrect for int&");
    static_assert(std::is_lvalue_reference<int>::value == false, "is_lvalue_reference is incorrect for int");

    static_assert(std::is_rvalue_reference<int&&>::value == true, "is_rvalue_reference is incorrect for int&&");
    static_assert(std::is_rvalue_reference<int>::value == false, "is_rvalue_reference is incorrect for int");

    //TODO(vim): Tests from this point onwards

    class member_ptr_test {};
    static_assert(std::is_member_pointer<int(member_ptr_test::*)>::value == true, "is_member_pointer is incorrect for int(member_ptr_test::*)");
    static_assert(std::is_member_pointer<int>::value == false, "is_member_pointer is incorrect for int");
}
