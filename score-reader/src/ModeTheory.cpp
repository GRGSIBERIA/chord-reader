#include "ModeTheory.hpp"
#include "ChordFactory.hpp"
#include <iostream>
using namespace score::scale;
using namespace std;

void PrintArray(const std::vector<int>& a)
{
	std::string str = "";
	for (const auto& i : a)
		str += std::to_string(i) + ",";
	cout << str << endl;
}

void ModifyMinusIntervals(const size_t size, ScaleIntervals& buffer)
{
	int sub = buffer[0];
	for (size_t i = 0; i < size; ++i)
	{
		buffer[i] -= sub;
		if (buffer[i] < 0) buffer[i] += 12;
	}
}

void UnfoldIntervals(const size_t size, size_t& pos, ScaleIntervals& buffer, const Scale& scale)
{
	int sub = buffer[0];
	for (size_t cnt = 0; cnt < size; ++cnt, ++pos)
	{
		if (pos >= size) pos = 0;
		buffer[cnt] = scale.GetInterval(pos) - sub;
	}

	ModifyMinusIntervals(size, buffer);
}

void FindAvoidNotes(const ScaleIntervals& buffer, const ScaleIndices& chordTones, ScaleIndices& avoids)
{
	for (const auto& tone : chordTones)
	{
		int target = tone + 1;
		if (target >= (int)buffer.size()) target = 0;

		// アボイドノートは，コードトーンに対して短2度を形成する
		if (buffer[tone] + 1 == buffer[target])
			avoids.push_back(target);
	}
}

// トライトーンからコードトーンを除外する
const bool ExcludeChordTone(const ScaleIndices& chordTones, const size_t i)
{
	bool flag = false;
	for (const auto& t : chordTones)
	{
		if (t == i) flag = true;
	}
	return flag;
}

void FindTritones(const ScaleIntervals& buffer, const ScaleIndices& chordTones, ScaleIndices& tritones)
{
	for (const auto& tone : chordTones)
	{
		// 増4度，もしくは減5度を探す
		int target = buffer[tone] + 6;
		if (target >= 12) target -= 12;

		for (size_t i = 0; i < buffer.size(); ++i)
		{
			if (buffer[i] == target && !ExcludeChordTone(chordTones, i))
			{
				int tmp = i;

				// 増4度か減5度か判定する
				if (i >= 0 && i < buffer.size() - 1)
				{
					if (buffer[i - 1] - buffer[i] == 1)
						tmp = -tmp;
				}
				else if (i == buffer.size() - 1)
				{
					if ((buffer[0] + 12) - buffer[i] == 1)
						tmp = -tmp;
				}

				tritones.push_back(tmp);
			}
		}
	}
}

void MergeAvoidAndTritone(ScaleIndices& avoids, const ScaleIndices& tritones)
{
	avoids.insert(avoids.end(), tritones.begin(), tritones.end());
}

void CreateAvailableScale(const ScaleIndices& buffer, const ScaleIndices& avoids, ScaleIndices& availables)
{
	availables = buffer;

	for (const auto& index : avoids)
	{
		int tmp = availables[index];

		if (index >= 0) tmp++;
		else
			tmp--;
		
		if (tmp < 0) tmp += 12;
		else if (tmp > 11) tmp -= 12;

		availables[index] = tmp;
	}
}

void ModeTheory::MakeModeScale(const int i, const Scale& scale)
{
	size_t pos = i;
	ScaleIntervals buffer(scale.Size(), 0);
	ScaleIndices avoids;
	ScaleIndices tritones;
	ScaleIndices availables;

	// ここでbufferにインターバルを展開する
	UnfoldIntervals(scale.Size(), pos, buffer, scale);

	FindAvoidNotes(buffer, chordTones, avoids);
	FindTritones(buffer, chordTones, tritones);
	MergeAvoidAndTritone(avoids, tritones);
	CreateAvailableScale(buffer, avoids, availables);

	//PrintArray(buffer);
	//PrintArray(avoids);
	//PrintArray(tritones);

	modeScales.emplace_back(L"", buffer, chordTones, avoids, tritones, availables);
}

void ModeTheory::BuildingModeScales(const Scale& scale)
{
	for (size_t i = 0; i < scale.Size(); ++i)
	{
		MakeModeScale(i, scale);
	}
}

void ModeTheory::BuildingDiatonicChords()
{
	for (size_t i = 0; i < Size(); ++i)
	{
		diatonics.emplace_back(score::chord::ChordFactory::CreateChord(
			modeScales[i].GetInterval(chordTones[0]),
			modeScales[i].GetInterval(chordTones[1]),
			modeScales[i].GetInterval(chordTones[2]),
			modeScales[i].GetInterval(chordTones[3])));
	}
}

ModeTheory::ModeTheory(const Scale& scale, const ScaleIndices& chordTones) : chordTones(chordTones)
{
	BuildingModeScales(scale);
	BuildingDiatonicChords();
}