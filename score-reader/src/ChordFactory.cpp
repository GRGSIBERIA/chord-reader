#include "ChordFactory.hpp"
using namespace score::chord;

ChordPtr ChordFactory::CreateChord(const std::wstring& str)
{
	const auto& consts = ChordConstructions::GetInstance();

	auto ch = ChordPtr(
		new Chord(str, 
		(const Root&)consts.MatchRoots(str), 
		(const Tone&)consts.MatchTones(str), 
		(const Fifth&)consts.MatchFifthes(str), 
		(const Dominant&)consts.MatchDominants(str), 
		(const Tension&)consts.MatchTensions(str), 
		(const OnChord&)consts.MatchOnChords(str)));

	return ch;
}

// 任意の度数からコードを作成する関数
Chord ChordFactory::CreateChord(const int rooti, const int thirdi, const int fifthi, const int sevensi)
{
	const auto& consts = ChordConstructions::GetInstance();

#define FIND(X, Y, Z) std::find_if(X.begin(), X.end(), [Y](const Z& i) { return i.Interval() == Y; })

	const auto& root = FIND(consts.roots, rooti, Root);
	const auto& third = FIND(consts.tones, thirdi, Tone);
	const auto& fifth = FIND(consts.fifthes, fifthi, Fifth);
	if (sevensi >= 0)
	{
		const auto& sevens = FIND(consts.dominants, sevensi, Dominant);
		return Chord(root->Name() + third->Name() + sevens->Name() + fifth->Name(),
			(const Root&)*root, (const Tone&)*third, (const Fifth&)*fifth, (const Dominant&)*sevens, (const Tension&)consts.none, (const OnChord&)consts.none);
	}
	return Chord(root->Name() + third->Name() + fifth->Name(),
		(const Root&)*root, (const Tone&)*third, (const Fifth&)*fifth, (const Dominant&)consts.none, (const Tension&)consts.none, (const OnChord&)consts.none);
}