#include <exception>
#include "ModeDatabase.hpp"

using namespace score::scale;

std::shared_ptr<ModeDatabase> ModeDatabase::_ptr = nullptr;

const Mode& ModeDatabase::Find(const std::wstring& name)
{
	for (const auto& mode : modes)
	{
		if (mode.Name() == name)
			return mode;
	}
	throw std::invalid_argument(std::string("Doesn't exists mode name: ") + (char*)name.c_str());
}

const Mode& ModeDatabase::Find(const size_t index)
{
	return modes[index];
}

const ModeDatabase& ModeDatabase::GetInstance()
{
	if (_ptr == nullptr)
		_ptr = std::shared_ptr<ModeDatabase>(new ModeDatabase());
	return *_ptr;
}