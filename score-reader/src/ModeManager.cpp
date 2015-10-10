#include "ModeManager.hpp"
#include "Modulation.hpp"
using namespace score::score;
using namespace score::scale;

ModeManager::ModeManager(const ChordUnitArray chords)
{
	auto k = chords.begin();
	while (k != chords.end())
	{
		PushBack(k->Key);
		PushBack(scale::Modulation::Parallel(k->Key));
		PushBack(scale::Modulation::Relative(k->Key));
		PushBack(scale::Modulation::Dominant(k->Key));
		PushBack(scale::Modulation::SubDominant(k->Key));
		PushBack(scale::Modulation::MinorDominant(k->Key));
		PushBack(scale::Modulation::MinorSubDominant(k->Key));
		k = chords.NextKey(k);
	}
}

void ModeManager::PushBack(const std::wstring& key) {
	if (Find(key) == modes.end())
		modes.emplace_back(key);
}

const ModeManager::Itr ModeManager::Find(const std::wstring& key) const {
	return std::find_if(modes.begin(), modes.end(), [key](const scale::KeyChordModalizer& m) { return key == m.KeyName(); });
}

const ModeManager::Itr ModeManager::Parallel(const std::wstring& key) const
{
	return Find(Modulation::Parallel(key));
}
const ModeManager::Itr ModeManager::Relative(const std::wstring& key) const
{
	return Find(Modulation::Relative(key));
}
const ModeManager::Itr ModeManager::Dominant(const std::wstring& key) const
{
	return Find(Modulation::Dominant(key));
}
const ModeManager::Itr ModeManager::SubDominant(const std::wstring& key) const
{
	return Find(Modulation::SubDominant(key));
}
const ModeManager::Itr ModeManager::MinorDominant(const std::wstring& key) const
{
	return Find(Modulation::MinorDominant(key));
}
const ModeManager::Itr ModeManager::MinorSubDominant(const std::wstring& key) const
{
	return Find(Modulation::MinorSubDominant(key));
}