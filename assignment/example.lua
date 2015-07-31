function test( foo )
	PrintFoo( foo )
	local x = GetX( foo )
	print( "LuaFoo - x<" .. x .. ">" )
	x = x + 1
	SetX( foo, x )
	PrintFoo( foo )
	x = GetX( foo )
	print( "LuaFoo - x<" .. x .. ">" )
end

function test2( foo )
	PrintFoo( foo )
	local x = GetX( foo )
	print( "LuaFoo - x<" .. x .. ">" )
	x = x + 1
	SetX( foo, x )
	PrintFoo( foo )
	x = GetX( foo )
	print( "LuaFoo - x<" .. x .. ">" )
	IncSomeValue()
end