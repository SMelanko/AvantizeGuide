#include "pch.h"
#include "User.h"

namespace Db
{

User::User(const std::string& name, const std::string& email,
	const std::string& pwd, const Role role)
	: name_(name)
	, email_(email)
	, pwd_(pwd)
	, role_(std::make_pair(role, static_cast<int>(role)))
{
}

} // namespace Db
