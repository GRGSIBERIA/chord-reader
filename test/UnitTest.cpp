#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace test
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///���݂̃e�X�g�̎��s�ɂ��Ă̏�񂨂�ы@�\��
		///�񋟂���e�X�g �R���e�L�X�g���擾�܂��͐ݒ肵�܂��B
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//�e�X�g���쐬����ۂɂ́A���̒ǉ��������g�p�ł��܂�:
		//
		//�N���X���ōŏ��̃e�X�g�����s����O�ɁAClassInitialize ���g�p���ăR�[�h�����s���Ă�������
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//�N���X���̃e�X�g�����ׂĎ��s������AClassCleanup ���g�p���ăR�[�h�����s���Ă�������
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//�e�e�X�g�����s����O�ɁATestInitialize ���g�p���ăR�[�h�����s���Ă�������
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//�e�e�X�g�����s������ɁATestCleanup ���g�p���ăR�[�h�����s���Ă�������
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestMethod1()
		{
			//
			// TODO: �e�X�g ���W�b�N�������ɒǉ����Ă�������
			//
		};
	};
}
