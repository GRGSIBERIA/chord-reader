#include "ModeTheory.hpp"
using namespace score::scale;

void ModeTheory::CreateModeScales(const Scale& scale)
{
	modeScales[0] = scale;

	size_t size = scale.Size();

	std::vector<int> buffer(size);

	for (size_t i = 1; i < size; ++i)
	{
		int pos = i;

		// ここでbufferにインターバルを展開する
		for (int cnt = 0; cnt < size; ++cnt, ++pos)
		{
			if (pos >= size) pos = 0;
			buffer[cnt] = scale.GetInterval(pos);
		}

		// 展開したインターバル同士の差を求める
		buffer[0] = 0;
		int total = 0;
		for (int cnt = 1; cnt < size; ++cnt)
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

		modeScales.emplace_back(L"", buffer);
	}
}

ModeTheory::ModeTheory(const Scale& scale)
{
	CreateModeScales(scale);
}