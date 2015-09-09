#pragma once
#include <string>

namespace ts
{
	namespace chord
	{
		/**
		* �\�����̊�{�N���X
		*/
		class ConstructionBase
		{
			std::wstring name;

		public:
			ConstructionBase() {}

			ConstructionBase(const std::wstring& name) : name(name) {}

			const std::wstring Name() const { return name; }
		};

		/**
		* ��3��
		*/
		class Tone : public ConstructionBase
		{
		public:
		};

		/**
		* ��7��
		*/
		class Dominant : public ConstructionBase
		{
		public:
		};

		/**
		* ��5��
		*/
		class Fifth : public ConstructionBase
		{
		public:
		};

		/**
		* �e���V�����m�[�g
		*/
		class Tension : public ConstructionBase
		{
		public:
		};
	}
}