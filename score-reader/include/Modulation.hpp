#pragma once
#include "Modal.hpp"
#include "RelatedKey.hpp"
#include "ScaleDatabase.hpp"

namespace score
{
	namespace scale
	{
		// 未定義のRelatedKeyが投げられた場合の例外
		class UndefinedRelatedKeyException : public std::exception
		{
		public:
			UndefinedRelatedKeyException() : exception("なんかよーわからん") {}
		};

		// 文字列を転調させる
		class Modulation
		{
		private:
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const int chordIndex, const RelatedKey related, const KeyChordModalizer& base);

		public:
			static const std::wstring Modulate(const RelatedKey relate, const std::wstring& key);
			static const std::wstring Parallel(const std::wstring& key);			// 同主調(I)
			static const std::wstring Relative(const std::wstring& key);			// 平行調(maj=VIm, min=III)
			static const std::wstring Dominant(const std::wstring& key);			// 属調(V)
			static const std::wstring SubDominant(const std::wstring& key);			// 下属調(IV)
			static const std::wstring MinorDominant(const std::wstring& key);		// 属調2(maj=IIIm, min=VII)
			static const std::wstring MinorSubDominant(const std::wstring& key);	// 下属調2(maj=IIm, min=VI)

			// 遷移したいコードをIとして，Vのコードを求める，2次ドミナント
			static const scale::ChordScale SecondaryDominant(const std::wstring& targetChord, const bool useMinor);

			// モーダルインターチェンジ
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const std::wstring& chord, const RelatedKey related);
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const size_t scaleIndex, const RelatedKey related);

			// 裏コード，代理ドミナント，一般的にはVの代理
			static const scale::ChordScale SubstituteDominant(const std::wstring& key, const std::wstring& chord);
		};
	}
}