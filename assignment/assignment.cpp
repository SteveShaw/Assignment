// assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "luaexample.h"
#include "myapplication.h"

#include <quickfix/FileStore.h>
#include <quickfix/FileLog.h>
#include <quickfix/SocketAcceptor.h>
#include <quickfix/Session.h>
#include <quickfix/SessionSettings.h>

// The goal of this assignment is to provide a scripting interface that any one can use
// to simply change the behaviour of fix in and out messages all without having 
// to recompile your code! Developers, QA and, even Application Support will be able
// to easily add/remove/update fix tags without changing any of the core fix logic.
// 
// Use Case 1: Client A can only understand Bloomberg options symbology
// We now can convert our symbology to their symbology without making a code change
//
// Use Case 2: A QA worker wants to test a specific combination of fix tags to ensure
// the application handles a scenario properly. All QA has to do is create a lua script
// that will recreate the particular scenario.
// 
// We have selected a very lightweight and easy to use scripting language called lua to obtain 
// the above objective. Take a very close look at the LuaExample class below. It has an example
// of how to implement everything that we are asking below.
// 
// Your assignment is as follows:
//
// 1. Create a class that MyApplication can either use as a member or derive from. It must
//    encapsulate the lua functionality into a simple interface and have the following
//    functionality:
//    a. SetField - Register a new lua function that can set a field on a FIX:Message 
//    b. RemoveField - Register a new lua function that can remove a field from a FIX:Message 
//    c. GetField - Register a new lua function that can get a field value from a FIX::Message
//    d. FixMsgToString - Register a new lua function that can turn a FIX::Message into a string
//    e. Any other functions you feel necessary
//    f. A generic way to call from C/C++ a lua function with 2 FIX::Message parameters
//
// 2. Use the new lua class to implement MyApplication::fromApp just like the executor example:
//	void Application::fromApp( const FIX::Message& message,
//							   const FIX::SessionID& sessionID )
//							   throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType )
//	{ crack( message, sessionID ); }
//
// Instead of using the message cracker (above), use the new lua class to call into lua function which 
// will set the same fields as the message cracker does in each overloaded version of Application::onMessage.
// For example, see the following function, we would like to see the lua equivalent.
// void Application::onMessage( const FIX40::NewOrderSingle& message,
//								const FIX::SessionID& sessionID )
//
// 3. Implement a lua version of onMessage that will be called from MyApplication::fromApp. 
//    Choose a particular Application::onMessage overload function to use as your template.
//
// Expectations:
// We ** do not ** expect you to have a working MyApplication class that will work against an opposing fix engine
// A simple showcase of your implementation is good for the spirit of this assignment. The example below will suffice:
// FIX::Message from;
// FIX::SessionID session;
// MyApplication application;
// application.fromApp( from, session );
//
// Useful references:
// http://www.lua.org/manual/5.1/
// http://www.quickfixengine.org/quickfix/doc/html/

int _tmain(int argc, _TCHAR* argv[])
{
	LuaExample example;
	example.RunExample( "example.lua" );

	 //FIX::Message from;
	 //FIX::SessionID session;
	 //MyApplication application;
	 //application.fromApp( from, session );


	// The code below is used if you want to test against another fixegine ** THIS IS NOT REQUIRED FOR THIS ASSIGNMENT **
	//try
	//{
	//	std::string fileName = "..\\..\\quickfix\\specs\\FIX44.xml";
	//	if( argc < 2 ) 
	//	{
	//		std::cout << "Defaulting to configuration file: " << fileName << std::endl;
	//	}
	//	else
	//	{
	//		fileName = argv[ 0 ]; 
	//	}
	//	
	//	FIX::SessionSettings settings( fileName );

	//	MyApplication application;
	//	FIX::FileStoreFactory storeFactory(settings);
	//	FIX::FileLogFactory logFactory(settings);
	//	FIX::SocketAcceptor acceptor
	//		(application, storeFactory, settings, logFactory /*optional*/);
	//	acceptor.start();
	//	// while( condition == true ) { do something; }
	//	acceptor.stop();
	//	return 0;
	//}
	//catch(FIX::ConfigError& e)
	//{
	//	std::cout << e.what() << std::endl;
	//	return -1;
	//}
	return 0;
}

