#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#ifdef _WIN32
#include "getopt.h"
#else
#include <unistd.h>
#endif

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <luabind/luabind.hpp>

#include "./script/scriptbind/lw_class_luabbind.h"

int main(int argc, char **argv) {
// 	int ch;
// 	std::string s;
// 	std::string d;
// 	while ((ch = getopt(argc, argv, "t:d::")) != -1)
// 	{
// 		switch (ch)
// 		{
// 		case 't': {
// 			s = optarg;
// 			break;
// 		}
// 		case 'd': {
// 			d = optarg;
// 			break;
// 		}
// 		default:
// 			break;
// 		}
// 	}

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	luabind::open(L);

	lw::lw_class_all_luabind(L);
	
	int isOpen = luaL_dofile(L, "./main.lua");
	{
		try
		{
			int result = luabind::call_function<int>(L, "lua_add", 2, 3);
			std::cout << "result lua_add: " << result << std::endl;
		}
		catch (luabind::error& e)
		{
			std::cout << "catch exception: " << e.what() << std::endl;
		}
	
		std::string value = luabind::object_cast<std::string>(luabind::globals(L)["nGlobalValue"]);
		std::cout << "nGlobalValue: " << value << std::endl;

		luabind::object tTable = luabind::globals(L)["globalTable"];
		std::cout << "lua的table型全局变量globalTable" << std::endl;
		if (luabind::type(tTable) == LUA_TTABLE)
		{
			std::string name = luabind::object_cast<std::string>(tTable["name"]);
			std::cout << "lua的table型全局变量globalTable中的字段name = " << name << std::endl;
				
			int age = luabind::object_cast<int>(tTable["age"]);
			std::cout << "lua的table型全局变量globalTable中的字段age = " << age << std::endl;
		}
	}
	
	lua_close(L);

	system("pause");

	return 0;
}