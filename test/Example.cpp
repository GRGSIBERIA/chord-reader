#include "gtest\gtest.h"
#include <iostream>
#include <ChordScore.hpp>
#include <Modulation.hpp>
using namespace std;

TEST(Example, example)
{
	auto autumn = score::score::ChordScore("..\\autumn leaves.xml");

	const auto& first = autumn.Chords[0];

	wcout << first.Chord.Name() << endl;
	for (size_t i = 0; i < 7; ++i)
	{
		const auto& mode = first.Scale(i);

		for (const auto u : mode)
			wcout << u << L",";
		wcout << endl;
	}

	for (size_t i = 0; i < 7; ++i)
	{
		const auto& mode = first.Usable(i);

		for (const auto u : mode)
			wcout << u << L",";
		wcout << endl;
	}
}