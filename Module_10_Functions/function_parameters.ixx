module;

#include <vector>
#include <span>

export module function_parameters;

export void pass_by_value_increment_print(int a);

export void pass_by_reference_increment_print(int &a);

export void pass_by_const_reference_increment_print(const int &a);

export void pass_by_pointer_increment_print(int *a);

export void pass_by_default_increment_print(int a = 14);

export void vector_print(const std::vector<int> &vec);

export void raw_array_print(const int arr[], const size_t &size);

export void span_print(std::span<const int> span_view);
