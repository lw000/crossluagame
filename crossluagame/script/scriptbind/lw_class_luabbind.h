#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

// #include <luabind/lua_include.hpp>
#include <luabind/luabind.hpp>

namespace lw {
	int lw_class_all_luabind(lua_State* L);
}
