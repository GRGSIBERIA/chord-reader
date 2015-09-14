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
		private:
			const std::wstring name;
			const int interval;
			const std::wregex reg;

		public:
			ConstructionBase(const std::wstring& name, int interval, const std::wstring& re) : name(name), reg(re), interval(interval) {}
			ConstructionBase(const std::wstring& name, int interval) : name(name), reg(std::wstring(L"^.+") + name + L".*"), interval(interval) {}

			const std::wstring& Name() const { return name; }
			int Interval() const { return interval; }
			const std::wregex& Regex() const { return reg; }
		};

		/**
		* 使われていないコードだった
		*/
		class None : public ConstructionBase
		{
		public:
			None() : ConstructionBase(L"", 0) {}
		};

#define DEFINE_CONSTRUCTION(CLASS_NAME, COMMENT)\
		/* COMMENT */ \
		class CLASS_NAME : public ConstructionBase { \
			public:\
			CLASS_NAME(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}\
			CLASS_NAME(const std::wstring& name, int interval) : ConstructionBase(name, interval) {}\
		}

		DEFINE_CONSTRUCTION(Root, 根音);
		DEFINE_CONSTRUCTION(Tone, 第3音);
		DEFINE_CONSTRUCTION(Fifth, 第5音);
		DEFINE_CONSTRUCTION(Dominant, 第7音);
		DEFINE_CONSTRUCTION(Tension, 修飾音);
		DEFINE_CONSTRUCTION(OnChord, オンコード);

		typedef std::array<ConstructionBase, 17> Roots; // vertex -> vertices -> s
		typedef std::array<ConstructionBase, 2>	 Tones;
		typedef std::array<ConstructionBase, 4>  Fifths;
		typedef std::array<ConstructionBase, 3>  Dominants;
		typedef std::array<ConstructionBase, 9>  Tensions;
		typedef std::array<ConstructionBase, 17> OnChords;

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
			const Roots roots = Roots{ {
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
				Root(L"C",	0, L"^C.*$"),
				Root(L"D",	2, L"^D.*$"),
				Root(L"E",	4, L"^E.*$"),
				Root(L"F",	5, L"^F.*$"),
				Root(L"G",	7, L"^G.*$"),
				Root(L"A",	9, L"^A.*$"),
				Root(L"B",	11,L"^B.*$")
					} };

			const Tones tones = Tones{ {
				Tone(L"m", 3),
				Tone(L"", 4, L"")
					} };

			const Fifths fifthes = Fifths{ {
				Fifth(L"-5",	6),
				Fifth(L"+5",	8, L"^.+\\+5.*"),
				Fifth(L"sus4",	5),
				Fifth(L"",		7, L""),
					} };

			const Dominants dominants = Dominants{ {
				Dominant(L"M7", 11),
				Dominant(L"7", 10),
				Dominant(L"6", 9 )
					} };

			const Tensions tensions = Tensions{ {
				Tension(L"b9",	1),
				Tension(L"b11", 4),
				Tension(L"b13", 8),
				Tension(L"#9",	3),
				Tension(L"#11", 6),
				Tension(L"#13", 10),
				Tension(L"9",	2),
				Tension(L"11",	5),
				Tension(L"13",	9)
					} };

			const OnChords onchords = OnChords{ {
				OnChord(L"Db", 1, L".+(/|on|\\(on) *Db.*"),
				OnChord(L"Eb", 3, L".+(/|on|\\(on) *Eb.*"),
				OnChord(L"Gb", 6, L".+(/|on|\\(on) *Gb.*"),
				OnChord(L"Ab", 8, L".+(/|on|\\(on) *Ab.*"),
				OnChord(L"Bb", 10, L".+(/|on|\\(on) *Bb.*"),
				OnChord(L"C#", 1, L".+(/|on|\\(on) *C#.*"),
				OnChord(L"D#", 3, L".+(/|on|\\(on) *D#.*"),
				OnChord(L"F#", 6, L".+(/|on|\\(on) *F#.*"),
				OnChord(L"G#", 8, L".+(/|on|\\(on) *G#.*"),
				OnChord(L"A#", 10, L".+(/|on|\\(on) *A#.*"),
				OnChord(L"C", 0, L".+(/|on|\\(on) *C.*"),
				OnChord(L"D", 2, L".+(/|on|\\(on) *D.*"),
				OnChord(L"E", 4, L".+(/|on|\\(on) *E.*"),
				OnChord(L"F", 5, L".+(/|on|\\(on) *F.*"),
				OnChord(L"G", 7, L".+(/|on|\\(on) *G.*"),
				OnChord(L"A", 9, L".+(/|on|\\(on) *A.*"),
				OnChord(L"B", 11, L".+(/|on|\\(on) *B.*")
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