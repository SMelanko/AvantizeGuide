#pragma once

namespace Db {

//
// Declaration of the User class.
//

class User
{
	//
	// Public type aliases.
	//
public:
	// User's roles.
	enum class Role
	{
		USER,
		ADMIN,
		SUPERUSER
	};

	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	User() = default;
	//! Constructor.
	User(const std::string& name, const std::string& email,
		const std::string& pwd, const Role role = Role::USER);

	//
	// Public interface.
	//
public:
	//! Returns user's email.
	const std::string& GetEmail() const;
	//! Returns user's name.
	const std::string& GetName() const;
	//! Returns user's password.
	const std::string& GetPassword() const;
	//! Returns user's role.
	const Role& GetRole() const;
	const int& GetRoleInt() const;

	//! Sets new user's email.
	void SetEmail(const std::string& email);
	void SetEmail(std::string&& email);
	//! Sets new user's name.
	void SetName(const std::string& name);
	void SetName(std::string&& name);
	//! Sets new user's password.
	void SetPassword(const std::string& pwd);
	void SetPassword(std::string&& pwd);
	//! Sets user's role.
	void SetRole(const Role role);

	//
	// Private methods.
	//
private:
	//! Makes a log entry.
	void Log() const;

	//
	// Private data members.
	//
private:
	//! User's name.
	std::string name_;
	//! User's email.
	std::string email_;
	//! User's password.
	std::string pwd_;
	//! User's role.
	std::pair<Role, int> role_;
};

//
// Inline implementation.
//

inline const std::string& User::GetEmail() const
{
	return email_;
}

inline const std::string& User::GetName() const
{
	return name_;
}

inline const std::string& User::GetPassword() const
{
	return pwd_;
}

inline const User::Role& User::GetRole() const
{
	return role_.first;
}

inline const int& User::GetRoleInt() const
{
	return role_.second;
}

inline void User::SetEmail(const std::string& email)
{
	email_ = email;
}

inline void User::SetName(const std::string& name)
{
	name_ = name;
}

inline void User::SetName(std::string&& name)
{
	name_ = std::move(name);
}

inline void User::SetEmail(std::string&& email)
{
	email_ = std::move(email);
}

inline void User::SetPassword(const std::string& pwd)
{
	pwd_ = pwd;
}

inline void User::SetPassword(std::string&& pwd)
{
	pwd_ = std::move(pwd);
}

inline void User::SetRole(const User::Role role)
{
	role_ = std::make_pair(role, static_cast<int>(role));
}

} // namespace Db

namespace Poco { namespace Data {

//
// Declaration of the TypeHandler<Db::User> class.
//

template <>
class TypeHandler<Db::User>
{
	//
	// Construction and destruction.
	//
private:
	//! Constructor.
	TypeHandler();
	//! Destructor.
	~TypeHandler();
	//! Copy constructor.
	TypeHandler(const TypeHandler&);
	//! Assignment operator.
	TypeHandler& operator=(const TypeHandler&);

	//
	// Public interface.
	//
public:
	static void bind(std::size_t pos, const Db::User& obj,
		AbstractBinder::Ptr binder, AbstractBinder::Direction dir)
	{
		poco_assert_dbg(!binder.isNull());

		binder->bind(pos++, obj.GetName(), dir);
		binder->bind(pos++, obj.GetEmail(), dir);
		binder->bind(pos++, obj.GetPassword(), dir);
		binder->bind(pos++, obj.GetRoleInt(), dir);
	}

	static void extract(std::size_t pos, Db::User& obj,
		const Db::User& defVal, AbstractExtractor::Ptr ext)
	{
		poco_assert_dbg (!ext.isNull());

		std::string name;
		std::string email;
		std::string pwd;
		int role;

		TypeHandler<std::string>::extract(pos++, name, defVal.GetName(), ext);
		TypeHandler<std::string>::extract(pos++, email, defVal.GetEmail(), ext);
		TypeHandler<std::string>::extract(pos++, pwd, defVal.GetPassword(), ext);
		TypeHandler<int>::extract(pos++, role, defVal.GetRoleInt(), ext);

		obj.SetName(std::move(name));
		obj.SetEmail(std::move(email));
		obj.SetPassword(std::move(pwd));
		obj.SetRole(static_cast<Db::User::Role>(role));
	}

	static void prepare(std::size_t pos, const Db::User& obj,
		AbstractPreparator::Ptr prepare)
	{
		poco_assert_dbg(!prepare.isNull());

		prepare->prepare(pos++, obj.GetName());
		prepare->prepare(pos++, obj.GetEmail());
		prepare->prepare(pos++, obj.GetPassword());
		prepare->prepare(pos++, obj.GetRoleInt());
	}

	static std::size_t size()
	{
		return 4;
	}
};

} } // namespace Poco::Data
