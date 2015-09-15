#include <exception>
#include "ModeDatabase.hpp"

using namespace score::scale;

std::shared_ptr<ModeDatabase> ModeDatabase::_ptr = nullptr;

const Mode& ModeDatabase::Modes(const std::wstring& name) const
{
	for (const auto& mode : modes)
	{
		if (mode.Name() == name)
			return mode;
	}
	throw std::invalid_argument(std::string("Doesn't exists mode name: ") + (char*)name.c_str());
}

const Mode& ModeDatabase::Modes(const size_t index) const
{
	return modes[index];
}

const ModeDatabase& ModeDatabase::GetInstance()
{
	if (_ptr == nullptr)
		_ptr = std::shared_ptr<ModeDatabase>(new ModeDatabase());
	return *_ptr;
}

const Mode& ModeDatabase::FindAlter(const Mode& mode) const
{
	const auto& name = alternatives[mode.ModeNumber()];
	return Modes(name);
}

const Mode& ModeDatabase::FindAlter(const std::wstring& name) const
{
	const auto& mode = Modes(name);
	return FindAlter(mode);
}