#pragma once
#include <string>
#include <memory>
#include <regex>

namespace score
{
	namespace chord
	{
		/**
		* 構成音の基本クラス
		*/
		class ConstructionBase
		{
		protected:
			typedef const std::wregex SVFunc();
			const std::wregex re;

		private:
			const std::wstring name;
			SVFunc* const refunc;

		public:
			ConstructionBase(SVFunc* re) : refunc(re) {}
			ConstructionBase(SVFunc* re, const std::wstring& name) : refunc(re), name(name), re(name) {}

			const std::wstring& Name() const { return name; }
		};

#define MAKE_CONSTRUCTION(BASE_NAME, CLASS_NAME, WSTR) \
		class CLASS_NAME : public BASE_NAME \
		{\
		public:\
			static const std::wregex Regex() { return std::wregex(WSTR); } \
			CLASS_NAME() : BASE_NAME(Regex, WSTR) {} \
		}; \

		/**
		* 根音
		*/
		class Root : public ConstructionBase
		{
		public:
			Root(SVFunc* re, const std::wstring& name) : ConstructionBase(re, name) {}
		};

		MAKE_CONSTRUCTION(Root, NoteC, L"C");
		MAKE_CONSTRUCTION(Root, NoteD, L"D");
		MAKE_CONSTRUCTION(Root, NoteE, L"E");
		MAKE_CONSTRUCTION(Root, NoteF, L"F");
		MAKE_CONSTRUCTION(Root, NoteG, L"G");
		MAKE_CONSTRUCTION(Root, NoteA, L"A");
		MAKE_CONSTRUCTION(Root, NoteB, L"B");
		MAKE_CONSTRUCTION(Root, NoteDb, L"Cb");
		MAKE_CONSTRUCTION(Root, NoteEb, L"Eb");
		MAKE_CONSTRUCTION(Root, NoteGb, L"Gb");
		MAKE_CONSTRUCTION(Root, NoteAb, L"Ab");
		MAKE_CONSTRUCTION(Root, NoteBb, L"Bb");
		MAKE_CONSTRUCTION(Root, NoteCSharp, L"C#");
		MAKE_CONSTRUCTION(Root, NoteDSharp, L"D#");
		MAKE_CONSTRUCTION(Root, NoteFSharp, L"F#");
		MAKE_CONSTRUCTION(Root, NoteGSharp, L"G#");
		MAKE_CONSTRUCTION(Root, NoteASharp, L"A#");

		/**
		* 第3音
		*/
		class Tone : public ConstructionBase
		{
		public:
			Tone(SVFunc* re, const std::wstring& name) : ConstructionBase(re, name) {}
		};

		MAKE_CONSTRUCTION(Tone, Major3rd, L"");
		MAKE_CONSTRUCTION(Tone, Minor3rd, L"");

		/**
		* 第7音
		*/
		class Dominant : public ConstructionBase
		{
		public:
			Dominant(SVFunc* re, const std::wstring& name) : ConstructionBase(re, name) {}
		};

		MAKE_CONSTRUCTION(Dominant, Major7th, L"M7");
		MAKE_CONSTRUCTION(Dominant, Minor7th, L"7");
		MAKE_CONSTRUCTION(Dominant, Perfect6th, L"6");

		/**
		* 第5音
		*/
		class Fifth : public ConstructionBase
		{
		public:
			Fifth(SVFunc* re, const std::wstring& name) : ConstructionBase(re, name) {}
		};

		MAKE_CONSTRUCTION(Fifth, Perfect5th, L"");
		MAKE_CONSTRUCTION(Fifth, Diminished5th, L"-5");
		MAKE_CONSTRUCTION(Fifth, Augumented5th, L"+5");
		MAKE_CONSTRUCTION(Fifth, Sus4, L"sus4");

		/**
		* テンションノート
		*/
		class Tension : public ConstructionBase
		{
		public:
			Tension(SVFunc* re, const std::wstring& name) : ConstructionBase(re, name) {}
		};

		MAKE_CONSTRUCTION(Tension, Flat9th, L"b9");
		MAKE_CONSTRUCTION(Tension, Flat11th, L"b11");
		MAKE_CONSTRUCTION(Tension, Flat13th, L"b13");
		MAKE_CONSTRUCTION(Tension, Perfect9, L"9");
		MAKE_CONSTRUCTION(Tension, Perfect11, L"11");
		MAKE_CONSTRUCTION(Tension, Perfect13, L"13");
		MAKE_CONSTRUCTION(Tension, Sharp9, L"#9");
		MAKE_CONSTRUCTION(Tension, Sharp11, L"#11");
		MAKE_CONSTRUCTION(Tension, Sharp13, L"#13");

		typedef std::shared_ptr<Root> RootPtr;
		typedef std::shared_ptr<Tone> TonePtr;
		typedef std::shared_ptr<Fifth> FifthPtr;
		typedef std::shared_ptr<Dominant> DominantPtr;
		typedef std::shared_ptr<Tension> TensionPtr;
	}
}