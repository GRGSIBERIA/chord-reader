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

		// ������buffer�ɃC���^�[�o����W�J����
		for (int cnt = 0; cnt < size; ++cnt, ++pos)
		{
			if (pos >= size) pos = 0;
			buffer[cnt] = scale.GetInterval(pos);
		}

		// �W�J�����C���^�[�o�����m�̍������߂�
		buffer[0] = 0;
		int total = 0;
		for (int cnt = 1; cnt < size; ++cnt)
		{
			int sub;
			if (buffer[cnt - 1] > buffer[cnt])
				sub = buffer[cnt - 1] - (buffer[cnt] + 12);
			else
				sub = buffer[cnt - 1] - buffer[cnt];

			// <- �����ւ��炷
			buffer[cnt] = sub + total;
			total += sub;					// �����Ōv�Z���Ԉ���Ă�����C2�s��ɂ��炵���ق�������
		}

		modeScales.emplace_back(L"", buffer);
	}
}

ModeTheory::ModeTheory(const Scale& scale)
{
	CreateModeScales(scale);
}