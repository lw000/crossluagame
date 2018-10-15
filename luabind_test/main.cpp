#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <luabind/luabind.hpp>

void greet()
{
	std::cout << "hello world!\n";
}

extern "C" int init(lua_State* L)
{
	using namespace luabind;
	open(L);
// 	module(L)
// 		[
// 			def("greet", &greet)
// 		];
	return 0;
}


int main(int argc, char **argv) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	
	init(L);

	int isOpen = luaL_dofile(L, "./main.lua");

	std::cout << "cpp hello luabind" << std::endl;

	lua_close(L);

	system("pause");

	return 0;
}