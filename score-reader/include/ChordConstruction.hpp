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
			const std::wstring full_name;
			const std::wstring name;
			const int interval;
			const std::wregex reg;

		public:
			ConstructionBase(const std::wstring& name, int interval, const std::wstring& re, const std::wstring& fullName) : full_name(fullName), name(name), reg(re), interval(interval) {}
			ConstructionBase(const std::wstring& name, int interval, const std::wstring& re) : full_name(name), name(name), reg(re), interval(interval) {}
			ConstructionBase(const std::wstring& name, int interval) : full_name(name), name(name), reg(std::wstring(L"^.+") + name + L".*"), interval(interval) {}

			const std::wstring& Name() const { return name; }
			int Interval() const { return interval; }
			const std::wregex& Regex() const { return reg; }
			const std::wstring& FullName() const { return full_name; }
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
			CLASS_NAME(const std::wstring& name, int interval, const std::wstring& re, const std::wstring& fullName) : ConstructionBase(name, interval, re, fullName) {}\
			CLASS_NAME(const std::wstring& name, int interval, const std::wstring& re) : ConstructionBase(name, interval, re) {}\
			CLASS_NAME(const std::wstring& name, int interval) : ConstructionBase(name, interval) {}\
		}

		DEFINE_CONSTRUCTION(Root, 根音);
		DEFINE_CONSTRUCTION(Tone, 第3音);
		DEFINE_CONSTRUCTION(Fifth, 第5音);
		DEFINE_CONSTRUCTION(Dominant, 第7音);
		DEFINE_CONSTRUCTION(Tension, 修飾音);
		DEFINE_CONSTRUCTION(OnChord, オンコード);

		typedef std::array<Root, 17> Roots; // vertex -> vertices -> s
		typedef std::array<Tone, 2>	 Tones;
		typedef std::array<Fifth, 4>  Fifths;
		typedef std::array<Dominant, 3>  Dominants;
		typedef std::array<Tension, 9>  Tensions;
		typedef std::array<OnChord, 17> OnChords;

		/**
		* コードの解析を行うクラス
		* シングルトンクラスなのでGet()でインスタンスを取得
		*/
		class ChordConstructions
		{
		private:
			template <typename T>
			const ConstructionBase& MatchArray(const T& constructions, const std::wstring& str) const;

//#define TEST_CHORD

		public:
			const ConstructionBase none = None();

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
				Tone(L"m", 3, L"^.+m.*",L"minor"),
				Tone(L"",  4, L"^.*",	L"major")
					} };

			const Fifths fifthes = Fifths{ {
				Fifth(L"-5",	6),
				Fifth(L"+5",	8, L"^.+\\+5.*"),
				Fifth(L"sus4",	5),
				Fifth(L"",		7, L"^.*", L"P5"),
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
				OnChord(L"onDb", 1, L".+(/|on|\\(on) *Db.*"),
				OnChord(L"onEb", 3, L".+(/|on|\\(on) *Eb.*"),
				OnChord(L"onGb", 6, L".+(/|on|\\(on) *Gb.*"),
				OnChord(L"onAb", 8, L".+(/|on|\\(on) *Ab.*"),
				OnChord(L"onBb", 10, L".+(/|on|\\(on) *Bb.*"),
				OnChord(L"onC#", 1, L".+(/|on|\\(on) *C#.*"),
				OnChord(L"onD#", 3, L".+(/|on|\\(on) *D#.*"),
				OnChord(L"onF#", 6, L".+(/|on|\\(on) *F#.*"),
				OnChord(L"onG#", 8, L".+(/|on|\\(on) *G#.*"),
				OnChord(L"onA#", 10, L".+(/|on|\\(on) *A#.*"),
				OnChord(L"onC", 0, L".+(/|on|\\(on) *C.*"),
				OnChord(L"onD", 2, L".+(/|on|\\(on) *D.*"),
				OnChord(L"onE", 4, L".+(/|on|\\(on) *E.*"),
				OnChord(L"onF", 5, L".+(/|on|\\(on) *F.*"),
				OnChord(L"onG", 7, L".+(/|on|\\(on) *G.*"),
				OnChord(L"onA", 9, L".+(/|on|\\(on) *A.*"),
				OnChord(L"onB", 11, L".+(/|on|\\(on) *B.*")
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
			static const std::shared_ptr<ChordConstructions> GetPtr();
		};
	}
}