#include <iostream>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // 👈 新增这行，启用 STL 容器支持


namespace py = pybind11;
int add(int i, int j) {
    return i + j;
}

void inadd(){
  int a,b;
  std::cin>>a>>b;
  std::cout<<a+b;
}

int maxElement(const std::vector<int>& nums) {
	int result = 0;
	for (const auto& item : nums) {
		result = std::max(result, item);
	}
	return result;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
  
    m.def("inadd",&inadd,"cin and count");

	m.def("maxElement",&maxElement,"max num of the list");
}