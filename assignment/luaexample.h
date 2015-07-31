#ifndef LUA_EXAMPLE_H_
#define LUA_EXAMPLE_H_

#include <lua.hpp>

#define TONAME( x ) "x"

class LuaExample
{
public:
	LuaExample()
	{
		m_iSomeValue = 0;
	}

private:
	struct foo
	{
		foo( int _x = 0 ) : x( _x )
		{
		}

		int x;
	};

	static int PrintFoo( lua_State *pState )
	{
		int iArgs = lua_gettop( pState );
		if( ( 1 != iArgs ) ||
			( !lua_islightuserdata( pState, 1 ) ) )
		{
			LuaError( pState, "PrintFoo - invalid parameters!" );
			return 0;
		}
		foo* pFoo = (foo*)lua_touserdata( pState, 1 );
		printf( "Foo<%d>\n", pFoo->x );
		// We are not returning any arguements
		return 0;
	}

	static int GetX( lua_State *pState )
	{
		int iArgs = lua_gettop( pState );
		if( ( 1 != iArgs ) ||
			( !lua_islightuserdata( pState, 1 ) ) )
		{
			LuaError( pState, "PrintFoo - invalid parameters!" );
			return 0;
		}
		foo* pFoo = (foo*)lua_touserdata( pState, 1 );
		lua_pushnumber( pState, pFoo->x );
		// Return 1 argument
		return 1;
	}

	static int SetX( lua_State *pState )
	{
		int iArgs = lua_gettop( pState );
		if( ( 2 != iArgs ) ||
			( !lua_islightuserdata( pState, 1 ) ) ||
			( !lua_isnumber( pState, 2 ) ) )
		{
			LuaError( pState, "SetX - invalid parameters!" );
			return 0;
		}
		foo *pFoo = (foo*)lua_touserdata( pState, 1 );
		int iNum = (int)lua_tonumber( pState, 2 );
		pFoo->x = iNum;
		return 0;
	}

	static int IncSomeValue( lua_State *pState )
	{
		int iArgs = lua_gettop( pState );
		if ( 0 != iArgs )
		{
			LuaError( pState, "IncSomeValue - no parameters allowed!" );
			return 0;
		}
		
		LuaExample *pExample = (LuaExample*)lua_getstateuserdata( pState );
		++ pExample->m_iSomeValue;
		return 0;
	}

	static void LuaError( lua_State *pState, const char* pszError )
	{
		printf( "LuaError<%s>\n", pszError );
		lua_pushstring( pState, pszError );
		lua_error( pState );
	}

public:
	void RunExample( const char *pszLuaFile )
	{
		lua_State *pState = NULL;
		pState = luaL_newstate();

		// Set the this pointer as the user data.
		// lua_setstateuserdata is a function we added so we can refer back
		// to this instance. This allows for easier extension of the lua library 
		lua_setstateuserdata( pState, this );

		// Open core lua libraries
		luaL_openlibs( pState );

		lua_register( pState, "GetX", GetX );
		lua_register( pState, "SetX", SetX );
		lua_register( pState, "PrintFoo", PrintFoo );
		lua_register( pState, "IncSomeValue", IncSomeValue );

		// Loads and runs a lua file
		// Functions/variables defined in global space will be availble from
		// now on in the lua state
		int ret = luaL_dofile( pState, pszLuaFile );
		if ( 0 != ret )
		{
			printf( "Script error: %s, running script in %s\n", 
					lua_tostring( pState, -1 ), 
					pszLuaFile );
			lua_close( pState );
			pState = NULL;
			return;
		}

		foo a, b( 2 );
		// Check if function is defined and call the function with a single
		// parameter
		const char *pszFunc = "test";
		lua_getglobal( pState, pszFunc );
		bool bIsFunction = lua_isfunction( pState, -1 );
		printf( "function<%s> %s exist\n", pszFunc, ( ( bIsFunction ) ? "does" : "does not" ) );
		if ( bIsFunction )
		{
			int iSomeValueBefore = m_iSomeValue;
			lua_pushlightuserdata( pState, &a );
			int iError = lua_pcall( pState, 1, 0, 0 );
			if ( 0 != iError )
			{
				const char *pszErr = lua_tostring( pState, -1 );
				printf( "Possible script error. Function<%s> erro<%s>.\n", pszFunc, pszErr );
				// Remove the lua_tostring() result from the stack.
				lua_pop( pState, 1 );
			}

			if ( iSomeValueBefore != m_iSomeValue )
			{
				printf( "SomeValue changed before<%d> after<%d>\n", iSomeValueBefore, m_iSomeValue );
			}
			else
			{
				printf( "SomeValue did not change <%d>\n", m_iSomeValue );
			}
		}

		pszFunc = "test2";
		lua_getglobal( pState, pszFunc );
		bIsFunction = lua_isfunction( pState, -1 );
		printf( "function<%s> %s exist\n", pszFunc, ( ( bIsFunction ) ? "does" : "does not" ) );
		if ( bIsFunction )
		{
			int iSomeValueBefore = m_iSomeValue;
			lua_pushlightuserdata( pState, &b );
			int iError = lua_pcall( pState, 1, 0, 0 );
			if ( 0 != iError )
			{
				const char *pszErr = lua_tostring( pState, -1 );
				printf( "Possible script error. Function<%s> erro<%s>.\n", pszFunc, pszErr );
				// Remove the lua_tostring() result from the stack.
				lua_pop( pState, 1 );
			}

			if ( iSomeValueBefore != m_iSomeValue )
			{
				printf( "SomeValue changed before<%d> after<%d>\n", iSomeValueBefore, m_iSomeValue );
			}
			else
			{
				printf( "SomeValue did not change <%d>\n", m_iSomeValue );
			}
		}
	}

private:
	int m_iSomeValue;
};

#endif // LUA_EXAMPLE_H_