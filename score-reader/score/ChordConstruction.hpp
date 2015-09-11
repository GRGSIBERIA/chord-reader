#pragma once
#include <vector>
#include <array>
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

		private:
			const std::wstring name;
			const int interval;
			const std::wregex reg;
			SVFunc* const refunc;

		public:
			ConstructionBase(SVFunc* re) : refunc(re), name(L""), interval(0) {}
			ConstructionBase(SVFunc* re, const std::wstring& name, int interval) : refunc(re), name(name), interval(interval), reg(re()) {}

			const std::wstring& Name() const { return name; }
			int Interval() const { return interval; }
			const std::wregex& Regex() const { return reg; }
		};

#define MAKE_CONSTRUCTION(BASE_NAME, CLASS_NAME, WSTR, INTERVAL) \
		class CLASS_NAME : public BASE_NAME \
		{\
		public:\
			static const std::wregex _Regex() { return std::wregex(WSTR); } \
			CLASS_NAME() : BASE_NAME(_Regex, WSTR, INTERVAL) {} \
		}; \

#define MAKE_CONSTRUCTION_REG(BASE_NAME, CLASS_NAME, WSTR, INTERVAL, REGSTR) \
		class CLASS_NAME : public BASE_NAME \
				{\
		public:\
			static const std::wregex _Regex() { return std::wregex(REGSTR); } \
			CLASS_NAME() : BASE_NAME(_Regex, WSTR, INTERVAL) {} \
				}; \

		/**
		* 根音
		*/
		class Root : public ConstructionBase
		{
		public:
			Root(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}
		};

		MAKE_CONSTRUCTION(Root, NoteC, L"C", 0);
		MAKE_CONSTRUCTION(Root, NoteD, L"D", 2);
		MAKE_CONSTRUCTION(Root, NoteE, L"E", 4);
		MAKE_CONSTRUCTION(Root, NoteF, L"F", 5);
		MAKE_CONSTRUCTION(Root, NoteG, L"G", 7);
		MAKE_CONSTRUCTION(Root, NoteA, L"A", 9);
		MAKE_CONSTRUCTION(Root, NoteB, L"B", 11);
		MAKE_CONSTRUCTION(Root, NoteDb, L"Db", 1);
		MAKE_CONSTRUCTION(Root, NoteEb, L"Eb", 3);
		MAKE_CONSTRUCTION(Root, NoteGb, L"Gb", 6);
		MAKE_CONSTRUCTION(Root, NoteAb, L"Ab", 8);
		MAKE_CONSTRUCTION(Root, NoteBb, L"Bb", 10);
		MAKE_CONSTRUCTION(Root, NoteCSharp, L"C#", 1);
		MAKE_CONSTRUCTION(Root, NoteDSharp, L"D#", 3);
		MAKE_CONSTRUCTION(Root, NoteFSharp, L"F#", 6);
		MAKE_CONSTRUCTION(Root, NoteGSharp, L"G#", 8);
		MAKE_CONSTRUCTION(Root, NoteASharp, L"A#", 10);

		/**
		* 第3音
		*/
		class Tone : public ConstructionBase
		{
		public:
			Tone(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}
		};

		MAKE_CONSTRUCTION(Tone, Major3rd, L"", 4);
		MAKE_CONSTRUCTION(Tone, Minor3rd, L"m", 3);

		/**
		* 第7音
		*/
		class Dominant : public ConstructionBase
		{
		public:
			Dominant(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}
		};

		MAKE_CONSTRUCTION(Dominant, Major7th, L"M7", 11);
		MAKE_CONSTRUCTION(Dominant, Minor7th, L"7", 10);
		MAKE_CONSTRUCTION(Dominant, Perfect6th, L"6", 9);

		/**
		* 第5音
		*/
		class Fifth : public ConstructionBase
		{
		public:
			Fifth(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}
		};

		MAKE_CONSTRUCTION(Fifth, Perfect5th, L"", 7);
		MAKE_CONSTRUCTION(Fifth, Diminished5th, L"-5", 6);
		MAKE_CONSTRUCTION_REG(Fifth, Augumented5th, L"+5", 8, L"\\+5");
		MAKE_CONSTRUCTION(Fifth, Sus4, L"sus4", 5);
		MAKE_CONSTRUCTION(Fifth, Sus6, L"sus6", 9);

		/**
		* テンションノート
		*/
		class Tension : public ConstructionBase
		{
		public:
			Tension(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}
		};

		MAKE_CONSTRUCTION(Tension, Flat9th, L"b9", 1);
		MAKE_CONSTRUCTION(Tension, Flat11th, L"b11", 4);
		MAKE_CONSTRUCTION(Tension, Flat13th, L"b13", 8);
		MAKE_CONSTRUCTION(Tension, Perfect9, L"9", 2);
		MAKE_CONSTRUCTION(Tension, Perfect11, L"11", 5);
		MAKE_CONSTRUCTION(Tension, Perfect13, L"13", 9);
		MAKE_CONSTRUCTION(Tension, Sharp9, L"#9", 3);
		MAKE_CONSTRUCTION(Tension, Sharp11, L"#11", 6);
		MAKE_CONSTRUCTION(Tension, Sharp13, L"#13", 10);

		typedef std::shared_ptr<Root> RootPtr;
		typedef std::shared_ptr<Tone> TonePtr;
		typedef std::shared_ptr<Fifth> FifthPtr;
		typedef std::shared_ptr<Dominant> DominantPtr;
		typedef std::shared_ptr<Tension> TensionPtr;

		typedef std::array<ConstructionBase, 17> RootRegices; // vertex -> vertices -> regices
		typedef std::array<ConstructionBase, 2> ToneRegices;
		typedef std::array<ConstructionBase, 5> FifthRegices;
		typedef std::array<ConstructionBase, 3> DominantRegices;
		typedef std::array<ConstructionBase, 9> TensionRegices;

		struct ChordConstructions
		{
			template <typename T>
			const int MatchArray(const T& constructions, const std::wstring& str);
			const ConstructionBase& MatchRoots(const std::wstring& str);
			const ConstructionBase& MatchTones(const std::wstring& str);
			const ConstructionBase& MatchFifthes(const std::wstring& str);
			const ConstructionBase& MatchDominants(const std::wstring& str);
			const ConstructionBase& MatchTensions(const std::wstring& str);

			const RootRegices roots = RootRegices{ {
				chord::NoteDb(),
				chord::NoteEb(),
				chord::NoteGb(),
				chord::NoteAb(),
				chord::NoteBb(),
				chord::NoteCSharp(),
				chord::NoteDSharp(),
				chord::NoteFSharp(),
				chord::NoteGSharp(),
				chord::NoteASharp(),
				chord::NoteC(),
				chord::NoteD(),
				chord::NoteE(),
				chord::NoteF(),
				chord::NoteG(),
				chord::NoteA(),
				chord::NoteB()
					} };

			const ToneRegices tones = ToneRegices{ {
				chord::Major3rd(),
				chord::Minor3rd()
					} };

			const FifthRegices fifthes = FifthRegices{ {
				chord::Perfect5th(),
				chord::Diminished5th(),
				chord::Augumented5th(),
				chord::Sus4(),
				chord::Sus6()
					} };

			const DominantRegices dominants = DominantRegices{ {
				chord::Major7th(),
				chord::Minor7th(),
				chord::Perfect6th()
					} };

			const TensionRegices tensions = TensionRegices{ {
				chord::Flat9th(),
				chord::Flat11th(),
				chord::Flat13th(),
				chord::Sharp9(),
				chord::Sharp11(),
				chord::Sharp13(),
				chord::Perfect9(),
				chord::Perfect11(),
				chord::Perfect13()
					} };
		};
	}
}