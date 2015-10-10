#include "ModeManager.hpp"
#include "Modulation.hpp"
using namespace score::score;


ModeManager::ModeManager(const ChordUnitArray chords)
{
	auto k = chords.NextKey(chords.begin());
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
	if (Find(key) == end())
		emplace_back(key);
}

const ModeManager::const_iterator ModeManager::Find(const std::wstring& key) const {
	return std::find_if(begin(), end(), [key](const scale::KeyChordModalizer& m) { return key == m.KeyName(); });
}