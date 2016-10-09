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

    static_assert(std::is_reference<int&&>::value == true, "is_reference is incorrect for int&&");
    static_assert(std::is_reference<int&>::value == true, "is_reference is incorrect for int&");
    static_assert(std::is_rvalue_reference<int>::value == false, "is_reference is incorrect for int");

    class member_ptr_test {};
    static_assert(std::is_member_pointer<int(member_ptr_test::*)>::value == true, "is_member_pointer is incorrect for int(member_ptr_test::*)");
    static_assert(std::is_member_pointer<int>::value == false, "is_member_pointer is incorrect for int");

    union is_union_test { int i; float f; };
    static_assert(std::is_union<is_union_test>::value == true, "is_union is incorrect for test union");
    static_assert(std::is_union<int>::value == false, "is_union is incorrect for int");

    class is_class_test {};
    static_assert(std::is_class<is_class_test>::value == true, "is_class is incorrect for test class");
    static_assert(std::is_class<int>::value == false, "is_class is incorrect for int");

    static_assert(std::is_function<void*(int, float)>::value == true, "is_function is incorrect for test function");
    static_assert(std::is_function<int>::value == false, "is_function is incorrect for int");

    class is_member_function_pointer_test { public: void Test(); };
    static_assert(std::is_member_function_pointer<decltype(&is_member_function_pointer_test::Test)>::value == true, "is_member_function_pointer is incorrect for test member function");
    static_assert(std::is_member_function_pointer<int>::value == false, "is_member_function_pointer is incorrect for int");

    class is_member_object_pointer_test {};
    static_assert(std::is_member_object_pointer<int(is_member_object_pointer_test ::*)>::value == true, "is_member_object_pointer is incorrect for test member object");
    static_assert(std::is_member_object_pointer<int>::value == false, "is_member_object_pointer is incorrect for int");

    enum class is_enum_test { case1, case2, case3 };
    static_assert(std::is_enum<is_enum_test>::value == true, "is_enum is incorrect for test enum");
    static_assert(std::is_enum<int>::value == false, "is_enum is incorrect for int");

    static_assert(std::is_arithmetic<int>::value == true, "is_arithmetic is incorrect for int");
    static_assert(std::is_arithmetic<float>::value == true, "is_arithmetic is incorrect for float");
    static_assert(std::is_arithmetic<char>::value == true, "is_arithmetic is incorrect for char");
    static_assert(std::is_arithmetic<void>::value == false, "is_arithmetic is incorrect for void");

    struct is_fundamental_test {};
    static_assert(std::is_fundamental<char>::value == true, "is_fundamental is incorrect for char");
    static_assert(std::is_fundamental<long int>::value == true, "is_fundamental is incorrect for long int");
    static_assert(std::is_fundamental<void>::value == true, "is_fundamental is incorrect for void");
    static_assert(std::is_fundamental<std::nullptr_t>::value == true, "is_fundamental is incorrect for long int");
    static_assert(std::is_fundamental<is_fundamental_test>::value == false, "is_fundamental is incorrect for test struct");

    class is_object_test {};
    static_assert(std::is_object<int>::value == true, "is_object is incorrect for int");
    static_assert(std::is_object<int&>::value == false, "is_object is incorrect for int&");
    static_assert(std::is_object<is_object_test>::value == true, "is_object is incorrect for is_object_test");
    static_assert(std::is_object<is_object_test&>::value == false, "is_object is incorrect for is_object_test&");

    enum class is_scalar_test_enum { case1, case2, case3 };
    class is_scalar_test_class {};
    static_assert(std::is_scalar<is_scalar_test_enum>::value == true, "is_scalar is incorrect for test enum");
    static_assert(std::is_scalar<is_scalar_test_enum*>::value == true, "is_scalar is incorrect for test enum pointer");
    static_assert(std::is_scalar<int(is_scalar_test_class::*)>::value == true, "is_scalar is incorrect for class member pointer");
    static_assert(std::is_scalar<std::size_t>::value == true, "is_scalar is incorrect for std::size_t");
    static_assert(std::is_scalar<std::nullptr_t>::value == true, "is_scalar is incorrect for std::nullptr_t");
    static_assert(std::is_scalar<is_scalar_test_class>::value == false, "is_scalar is incorrect for test class");
    static_assert(std::is_scalar<is_scalar_test_class&>::value == false, "is_scalar is incorrect for test class reference");

    class is_compound_test {};
    static_assert(std::is_compound<is_compound_test>::value == true, "is_compound is incorrect for test class");
    static_assert(std::is_compound<int>::value == false, "is_compound is incorrect for int");
}
