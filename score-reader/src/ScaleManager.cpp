#include "ScaleManager.hpp"
using namespace score::score;

ScaleManager::ScaleManager(const Score& score)
{
	for (size_t partid = 0; partid < score.Size(); ++partid)
	{
		const auto& part = score.Part(partid);
		for (size_t keyid = 0; keyid < part.Size(); ++keyid)
		{
			const auto& key = part.Key(keyid);
			const auto& keyStr = key.KeyString();

			if (keys.find(keyStr) == keys.end())
				keys[keyStr] = KCMPtr(new scale::KeyChordModalizer(keyStr));
		}
	}
}