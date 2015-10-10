#include "ModeManager.hpp"
#include "Modulation.hpp"
using namespace score::score;

void ModeManager::PushBack(const std::wstring& key) {
	if (std::find_if(begin(), end(), [key](const scale::KeyChordModalizer& m) { return key == m.KeyName(); }) == end())
		emplace_back(key);
}

const score::scale::KeyChordModalizer& ModeManager::Find(const std::wstring& key) const {
	return *std::find_if(begin(), end(), [key](const scale::KeyChordModalizer& m) { return key == m.KeyName(); });
}

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