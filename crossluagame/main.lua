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

function luabind_class_test( ... )
	print("create a C++ class Student")
	local student = lw.Student()
	student:setName("liwei")
	student:setTag(100)
	student:setSex(1)
	print("student name: " .. student:getName())
	print("student tag: " .. student:getTag())
	print("student sex: " .. student:getSex())

	print("create a C++ class People")
	local people = lw.user.People("liwei", 200, 1)
	print("people name: " .. people:getName())
	print("people tag: " .. people:getTag())
	print("people sex: " .. people:getSex())
	-- print("people printf: " .. people:printf())
	print("people printf: " .. people:printf("8475758484949"))

	print("create a C++ class Common")
	local common = lw.Common()

	print("create a C++ class Man")
	local man = lw.user.Man()
	man:setName("limingzhe")
	man:setTag(200)
	man:setSex(1)
	print("man name: " .. man:getName())
	print("man tag: " .. man:getTag())
	print("man sex: " .. man:getSex())
end

function main( ... )
	luabind_class_test()
end

main()
