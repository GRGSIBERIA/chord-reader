#pragma once
#include <string>

namespace ts
{
	namespace chord
	{
		/**
		* 構成音の基本クラス
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
		* 第3音
		*/
		class Tone : public ConstructionBase
		{
		public:
		};

		/**
		* 第7音
		*/
		class Dominant : public ConstructionBase
		{
		public:
		};

		/**
		* 第5音
		*/
		class Fifth : public ConstructionBase
		{
		public:
		};

		/**
		* テンションノート
		*/
		class Tension : public ConstructionBase
		{
		public:
		};
	}
}