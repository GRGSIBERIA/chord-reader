#pragma once
#include <string>
#include <memory>

namespace score
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
			Tone(const std::wstring& name) : ConstructionBase(name) {}
		};

		class Major3rd : public Tone
		{
		public:
			Major3rd() : Tone(L"") {}
		};

		class Minor3rd : public Tone
		{
		public:
			Minor3rd() : Tone(L"m") {}
		};

		/**
		* 第7音
		*/
		class Dominant : public ConstructionBase
		{
		public:
			Dominant(const std::wstring& name) : ConstructionBase(name) {}
		};

		class Major7th : public Dominant
		{
		public:
			Major7th() : Dominant(L"M7") {}
		};

		class Minor7th : public Dominant
		{
		public:
			Minor7th() : Dominant(L"7") {}
		};

		class Major6th : public Dominant
		{
		public:
			Major6th() : Dominant(L"6") {}
		};

		/**
		* 第5音
		*/
		class Fifth : public ConstructionBase
		{
		public:
			Fifth(const std::wstring& name) : ConstructionBase(name) {}
		};

		class Perfect5th : public Fifth
		{
		public:
			Perfect5th() : Fifth(L"") {}
		};

		class Diminished5th : public Fifth
		{
		public:
			Diminished5th() : Fifth(L"-5") {}
		};

		class Augumented5th : public Fifth
		{
		public:
			Augumented5th() : Fifth(L"+5") {}
		};

		class Sus4 : public Fifth
		{
		public:
			Sus4() : Fifth(L"sus4") {}
		};

		/**
		* テンションノート
		*/
		class Tension : public ConstructionBase
		{
		public:
			Tension(const std::wstring& name) : ConstructionBase(name) {}
		};

		class Flat9th : public Tension
		{
		public:
			Flat9th() : Tension(L"b9") {}
		};

		class Perfect9th : public Tension
		{
		public:
			Perfect9th() : Tension(L"9") {}
		};

		class Sharp9th : public Tension
		{
		public:
			Sharp9th() : Tension(L"#9") {}
		};

		class Flat11th : public Tension
		{
		public:
			Flat11th() : Tension(L"b11") {}
		};

		class Perfect11th : public Tension
		{
		public:
			Perfect11th() : Tension(L"11") {}
		};

		class Sharp11th : public Tension
		{
		public:
			Sharp11th() : Tension(L"#11") {}
		};

		class Flat13th : public Tension
		{
		public:
			Flat13th() : Tension(L"b13") {}
		};

		class Perfect13th : public Tension
		{
		public:
			Perfect13th() : Tension(L"13") {}
		};

		class Sharp13th : public Tension
		{
		public:
			Sharp13th() : Tension(L"#13") {}
		};

		typedef std::shared_ptr<Tone> TonePtr;
		typedef std::shared_ptr<Fifth> FifthPtr;
		typedef std::shared_ptr<Dominant> DominantPtr;
		typedef std::shared_ptr<Tension> TensionPtr;
	}
}