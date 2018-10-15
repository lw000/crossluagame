print("111111")

nGlobalValue = "liweiliwei"

-- globalTable = {
-- 	name = "liwei",
-- 	age = 100
-- }

globalTable = {}
globalTable["name"] = "liwei"
globalTable["age"] = 100

function lua_add(a, b)
	return a + b
end

function luabind_test( ... )
	
end

function main( ... )
	luabind_test()
end

main()
