#ifndef _MYAPPLICATION_H_
#define _MYAPPLICATION_H_

#include <quickfix/Application.h>

class MyApplication : public FIX::Application
{
public:
	virtual ~MyApplication()
	{
	}

	/// Notification of a session begin created
	virtual void onCreate( const FIX::SessionID& )
	{
	}

	/// Notification of a session successfully logging on
	virtual void onLogon( const FIX::SessionID& )
	{
	}
	/// Notification of a session logging off or disconnecting
	virtual void onLogout( const FIX::SessionID& )
	{
	}

	/// Notification of admin message being sent to target
	virtual void toAdmin( FIX::Message& msg, const FIX::SessionID& )
	{
		const FIX::FieldBase* pField = msg.getFieldPtr( 0 );
	}

	/// Notification of app message being sent to target
	virtual void toApp( FIX::Message&, const FIX::SessionID& )
		throw( FIX::DoNotSend )
	{

	}

	/// Notification of admin message being received from target
	virtual void fromAdmin( const FIX::Message&, const FIX::SessionID& )
		throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon )
	{
	}

	/// Notification of app message being received from target
	virtual void fromApp( const FIX::Message&, const FIX::SessionID& )
		throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType )
	{
	}

};

#endif // _MYAPPLICATION_H_
