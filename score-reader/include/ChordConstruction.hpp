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
			typedef const std::wregex& SVFunc();

		private:
			const std::wstring name;
			const int interval;
			const std::wregex reg;
			SVFunc* const refunc;

		public:
			ConstructionBase(SVFunc* re) : refunc(re), name(L""), interval(0) {}
			ConstructionBase(SVFunc* re, const std::wstring& name, int interval) : refunc(re), name(name), interval(interval), reg(re()) {}

			ConstructionBase(const std::wstring& name, int interval, const std::wstring& re) : name(name), reg(re), interval(interval), refunc(nullptr) {}

			const std::wstring& Name() const { return name; }
			int Interval() const { return interval; }
			const std::wregex& Regex() const { return reg; }
		};

		/**
		* 使われていないコードだった
		*/
		class None : public ConstructionBase
		{
			static const std::wregex& _Regex() { const static std::wregex r(L"^\\w*"); return r; }
		public:
			None() : ConstructionBase(_Regex, L"", 0) {}
		};

		/**
		* クラスの自動生成用マクロ
		*/
#define MAKE_CONSTRUCTION(BASE_NAME, CLASS_NAME, WSTR, INTERVAL) \
		class CLASS_NAME : public BASE_NAME \
		{\
			static const std::wregex& _Regex() { const static std::wregex r(std::wstring(L"^.+") + WSTR + std::wstring(L".*")); return r; } \
		public:\
			CLASS_NAME() : BASE_NAME(_Regex, WSTR, INTERVAL) {} \
		}; \

		/**
		* 正規表現をカスタマイズできる方
		*/
#define MAKE_CONSTRUCTION_REG(BASE_NAME, CLASS_NAME, WSTR, INTERVAL, REGSTR) \
		class CLASS_NAME : public BASE_NAME \
		{\
			static const std::wregex& _Regex() { const static std::wregex r(REGSTR); return r; } \
		public:\
			CLASS_NAME() : BASE_NAME(_Regex, WSTR, INTERVAL) {} \
		}; \

		/**
		* 根音
		*/
		class Root : public ConstructionBase
		{
		public:
			Root(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}

			Root(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}
		};

		/**
		* 第3音
		*/
		class Tone : public ConstructionBase
		{
		public:
			Tone(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}

			Tone(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}
		};

		MAKE_CONSTRUCTION_REG(Tone, Major3rd, L"", 4, L"");
		MAKE_CONSTRUCTION(Tone, Minor3rd, L"m", 3);

		/**
		* 第5音
		*/
		class Fifth : public ConstructionBase
		{
		public:
			Fifth(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}

			Fifth(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}
		};

		MAKE_CONSTRUCTION_REG(Fifth, Perfect5th, L"", 7, L"");
		MAKE_CONSTRUCTION(Fifth, Diminished5th, L"-5", 6);
		MAKE_CONSTRUCTION_REG(Fifth, Augumented5th, L"+5", 8, L"^.+\\+5.*");
		MAKE_CONSTRUCTION(Fifth, Sus4, L"sus4", 5);

		/**
		* 第7音
		*/
		class Dominant : public ConstructionBase
		{
		public:
			Dominant(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}

			Dominant(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}
		};

		MAKE_CONSTRUCTION(Dominant, Major7th, L"M7", 11);
		MAKE_CONSTRUCTION(Dominant, Minor7th, L"7", 10);
		//MAKE_CONSTRUCTION_REG(Dominant, Perfect6th, L"6", 9, L"^.+6[^sus6].*");
		MAKE_CONSTRUCTION(Dominant, Perfect6th, L"6", 9);

		/**
		* テンションノート
		*/
		class Tension : public ConstructionBase
		{
		public:
			Tension(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}

			Tension(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}
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

		/**
		* オンコード
		*/
		class OnChord : public ConstructionBase
		{
		public:
			OnChord(SVFunc* re, const std::wstring& name, int interval) : ConstructionBase(re, name, interval) {}

			OnChord(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}
		};

		MAKE_CONSTRUCTION_REG(OnChord, OnC, L"C", 0, L".+(/|on|\\(on) *C.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnD, L"D", 2, L".+(/|on|\\(on) *D.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnE, L"E", 4, L".+(/|on|\\(on) *E.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnF, L"F", 5, L".+(/|on|\\(on) *F.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnG, L"G", 7, L".+(/|on|\\(on) *G.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnA, L"A", 9, L".+(/|on|\\(on) *A.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnB, L"B", 11, L".+(/|on|\\(on) *B.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnDb, L"Db", 1, L".+(/|on|\\(on) *Db.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnEb, L"Eb", 3, L".+(/|on|\\(on) *Eb.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnGb, L"Gb", 6, L".+(/|on|\\(on) *Gb.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnAb, L"Ab", 8, L".+(/|on|\\(on) *Ab.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnBb, L"Bb", 10, L".+(/|on|\\(on) *Bb.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnCSharp, L"C#", 1, L".+(/|on|\\(on) *C#.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnDSharp, L"D#", 3, L".+(/|on|\\(on) *D#.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnFSharp, L"F#", 6, L".+(/|on|\\(on) *F#.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnGSharp, L"G#", 8, L".+(/|on|\\(on) *G#.*");
		MAKE_CONSTRUCTION_REG(OnChord, OnASharp, L"A#", 10, L".+(/|on|\\(on) *A#.*");

		typedef std::shared_ptr<Root> RootPtr;
		typedef std::shared_ptr<Tone> TonePtr;
		typedef std::shared_ptr<Fifth> FifthPtr;
		typedef std::shared_ptr<Dominant> DominantPtr;
		typedef std::shared_ptr<Tension> TensionPtr;

		typedef std::array<ConstructionBase, 17> RootRegices; // vertex -> vertices -> regices
		typedef std::array<ConstructionBase, 2> ToneRegices;
		typedef std::array<ConstructionBase, 4> FifthRegices;
		typedef std::array<ConstructionBase, 3> DominantRegices;
		typedef std::array<ConstructionBase, 9> TensionRegices;
		typedef std::array<ConstructionBase, 17> OnChordRegices;

		/**
		* コードの解析を行うクラス
		* シングルトンクラスなのでGet()でインスタンスを取得
		*/
		class ChordConstructions
		{
		private:
			template <typename T>
			const ConstructionBase& MatchArray(const T& constructions, const std::wstring& str) const;

			const ConstructionBase none = None();

#define TEST_CHORD

#ifdef TEST_CHORD
		public:
#endif
			const RootRegices roots = RootRegices{ {
				Root(L"Db", 1, L"^Db.*$"),
				Root(L"Eb", 3, L"^Eb.*$"),
				Root(L"Gb", 6, L"^Gb.*$"),
				Root(L"Ab", 8, L"^Ab.*$"),
				Root(L"Bb", 10,L"^Bb.*$"),
				Root(L"C#", 1, L"^C#.*$"),
				Root(L"D#", 3, L"^D#.*$"),
				Root(L"F#", 6, L"^F#.*$"),
				Root(L"G#", 8, L"^G#.*$"),
				Root(L"A#", 10,L"^A#.*$"),
				Root(L"C", 0, L"^C.*$"),
				Root(L"D", 2, L"^D.*$"),
				Root(L"E", 4, L"^E.*$"),
				Root(L"F", 5, L"^F.*$"),
				Root(L"G", 7, L"^G.*$"),
				Root(L"A", 9, L"^A.*$"),
				Root(L"B", 11, L"^B.*$")
					} };

			const ToneRegices tones = ToneRegices{ {
				chord::Minor3rd(),
				chord::Major3rd()
					} };

			const FifthRegices fifthes = FifthRegices{ {
				chord::Diminished5th(),
				chord::Augumented5th(),
				chord::Sus4(),
				chord::Perfect5th()
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

			const OnChordRegices onchords = OnChordRegices{ {
				chord::OnDb(),
				chord::OnEb(),
				chord::OnGb(),
				chord::OnAb(),
				chord::OnBb(),
				chord::OnCSharp(),
				chord::OnDSharp(),
				chord::OnFSharp(),
				chord::OnGSharp(),
				chord::OnASharp(),
				chord::OnC(),
				chord::OnD(),
				chord::OnE(),
				chord::OnF(),
				chord::OnG(),
				chord::OnA(),
				chord::OnB()
					} };

		public:
			const ConstructionBase& MatchRoots(const std::wstring& str) const;
			const ConstructionBase& MatchTones(const std::wstring& str) const;
			const ConstructionBase& MatchFifthes(const std::wstring& str) const;
			const ConstructionBase& MatchDominants(const std::wstring& str) const;
			const ConstructionBase& MatchTensions(const std::wstring& str) const;
			const ConstructionBase& MatchOnChords(const std::wstring& str) const;

		private:
			ChordConstructions() {}
			static std::shared_ptr<ChordConstructions> _inst;

		public:
			static const ChordConstructions& GetInstance();
		};
	}
}