#include "pch.h"

#include "User.h"

namespace Db {

//
// Definition of the User class.
//

User::User(const std::string& name, const std::string& email,
	const std::string& pwd, const Role role)
	: name_{ name }
	, email_{ email }
	, pwd_{ pwd }
	, role_{ std::make_pair(role, static_cast<int>(role)) }
{
}

void User::Log() const
{
	// TODO: Just for example.
}

} // namespace Db
