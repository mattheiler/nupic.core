#define _CRT_SECURE_NO_WARNINGS // global?

#include "nupic/animals/Cat.hpp"

#include <pybind11/pybind11.h>

using namespace std;
using namespace nupic::animals;

namespace py = pybind11;

PYBIND11_MODULE(cat, m)
{
	py::class_<Cat>(m, "Cat")
		.def(py::init<const string&>())
		.def("setName", &Cat::setName)
		.def("getName", &Cat::getName);
}
