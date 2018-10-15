#include "lw_class_luabbind.h"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../Calc.h"
#include "../Common.h"
#include "../People.h"

namespace lw {
	/*static */void greet() {
		std::cout << "hello world" << std::endl;
	}

	/*static */int add(int a, int b) {
		return a + b;
	}

	/*static */std::string add(const std::string& a, const std::string& b) {
		return a + b;
	}

	int lw_class_all_luabind(lua_State* L) {
		using namespace luabind;
		open(L);

// 		module(L, "lw")[
// 			def("greet", &greet),
// 			def("add", (int(*)(int, int))&add),
// 			def("add", (std::string (*)(const std::string&, const std::string&))&add)
// 		];

		module(L, "lw")[
			class_<Common>("Common").def(constructor<>())
		];

		module(L, "lw")[		
			namespace_("user")[
				class_<user::People>("People")
					.def(constructor<>())
					.def(constructor<const std::string&, int, int>())
					.def("setName", &user::People::setName)
					.def("getName", &user::People::getName)
					.def("setTag", &user::People::setTag)
					.def("getTag", &user::People::getTag)
					.def("setSex", &user::People::setSex)
					.def("getSex", &user::People::getSex)
					.def("printf", (void (user::People::*)())&user::People::printf)
					.def("printf", (void (user::People::*)(const std::string&))&user::People::printf, dependency(_1, _2))
			],
				class_<Student>("Student")
					.def(constructor<>())
					.def("setName", &Student::setName)
					.def("getName", &Student::getName)
					.def("setTag", &Student::setTag)
					.def("getTag", &Student::getTag)
					.def("setSex", &Student::setSex)
					.def("getSex", &Student::getSex)
		];

		module(L, "lw")[
			namespace_("user")[
				class_<user::Man, user::People>("Man")
			]
		];

		return 0;
	}
}
