#include "ModeTheory.hpp"
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

// ケアノートからコードトーンを除外する
const bool ExcludeChordTone(const ScaleIndices& chordTones, const size_t i)
{
	bool flag = false;
	for (const auto& t : chordTones)
	{
		if (t == i) flag = true;
	}
	return flag;
}

void FindCareNotes(const ScaleIntervals& buffer, const ScaleIndices& chordTones, ScaleIndices& tritones)
{
	for (const auto& tone : chordTones)
	{
		int target = buffer[tone] + 6;
		if (target >= 12) target -= 12;

		for (size_t i = 0; i < buffer.size(); ++i)
		{
			if (buffer[i] == target && !ExcludeChordTone(chordTones, i))
			{
				tritones.push_back(i);
			}
		}
	}
}

void ModeTheory::MakeModeScale(const int i, const Scale& scale)
{
	size_t pos = i;
	ScaleIntervals buffer(scale.Size(), 0);
	ScaleIndices avoids;
	ScaleIndices tritones;

	// ここでbufferにインターバルを展開する
	UnfoldIntervals(scale.Size(), pos, buffer, scale);

	FindAvoidNotes(buffer, chordTones, avoids);
	FindCareNotes(buffer, chordTones, tritones);

	//PrintArray(buffer);
	//PrintArray(avoids);
	PrintArray(tritones);

	modeScales.emplace_back(L"", buffer, chordTones, avoids, tritones);
}

ModeTheory::ModeTheory(const Scale& scale, const ScaleIndices& chordTones) : chordTones(chordTones)
{
	//modeScales.emplace_back(scale.Name(), scale.Intervals(), chordTones);

	size_t size = scale.Size();

	for (size_t i = 0; i < size; ++i)
	{
		MakeModeScale(i, scale);
	}
}