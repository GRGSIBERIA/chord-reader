#include "ModeTheory.hpp"
using namespace score::scale;

void UnfoldIntervals(const size_t size, int& pos, std::vector<int>& buffer, const Scale& scale)
{
	for (int cnt = 0; cnt < size; ++cnt, ++pos)
	{
		if (pos >= size) pos = 0;
		buffer[cnt] = scale.GetInterval(pos);
	}
}

void CalculateInterval(std::vector<int>& buffer, int& total, const int& cnt)
{
	int sub;
	if (buffer[cnt - 1] > buffer[cnt])
		sub = buffer[cnt - 1] - (buffer[cnt] + 12);
	else
		sub = buffer[cnt - 1] - buffer[cnt];

	// <- ここへずらす
	buffer[cnt] = sub + total;
	total += sub;					// ここで計算が間違っていたら，2行上にずらしたほうがいい
}

void ModeTheory::MakeModeScale(const int i, const size_t size, std::vector<int>& buffer, const Scale& scale)
{
	int pos = i;

	// ここでbufferにインターバルを展開する
	UnfoldIntervals(size, pos, buffer, scale);

	// 展開したインターバル同士の差を求める
	buffer[0] = 0;
	int total = 0;
	for (int cnt = 1; cnt < size; ++cnt)
	{
		CalculateInterval(buffer, total, cnt);
	}

	modeScales.emplace_back(L"", buffer);
}

void ModeTheory::CreateModeScales(const Scale& scale)
{
	modeScales[0] = scale;

	size_t size = scale.Size();

	std::vector<int> buffer(size);

	for (size_t i = 1; i < size; ++i)
	{
		MakeModeScale(i, size, buffer, scale);
	}
}

ModeTheory::ModeTheory(const Scale& scale)
{
	CreateModeScales(scale);
}