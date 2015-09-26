#include "KeyChordModalizer.hpp"
using namespace score::scale;

const ScaleTheory KeyChordModalizer::stheory = ScaleTheory({ 0, 2, 4, 5, 7, 9, 11 });

KeyChordModalizer::KeyChordModalizer(const Modal& key)
	: mtheory(Scale(L"", stheory.GetScale(key)), { 0, 2, 4, 6 }), key(key), scale(L"", stheory.GetScale(key)) 
{
	modeScale = ModeModalScales(scale.Size(), ModeModalScale(scale.Size()));

	// 音階ごとにモードスケールを展開する

	for (size_t modeIndex = 0; modeIndex < scale.Size(); ++modeIndex)
	{
		const auto& mode = mtheory.GetMode(modeIndex);

		for (size_t intervalIndex = 0; intervalIndex < scale.Size(); ++intervalIndex)
		{
			int tmp = mode.GetInterval(intervalIndex) + (int)key;
			tmp = tmp > 11 ? tmp - 12 : tmp;
			
			modeScale[modeIndex][intervalIndex] = tmp;
		}
	}
}