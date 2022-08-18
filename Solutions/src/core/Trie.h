#pragma once
#include <core/Common.h>
using namespace std;

namespace cds {


	template<typename T, size_t range_start, size_t range_end>
	class Trie {
	private:
		struct TrieNode {
			array<TrieNode*, range_end - range_start> dict;
			bool isWord;
			size_t prefixCount;
		};

		TrieNode* root_;

	public:
		Trie() {
			root_ = new TrieNode();
		}

		template<typename FwdIt>
		inline auto Insert(FwdIt _first, FwdIt _last)
			-> enable_if_t<is_same_v<typename FwdIt::value_type, T>, void>
		{
			TrieNode* currentNode = root_;

			while (_first != _last) {
				const auto offsetValue = *_first - range_start;
				if (!currentNode->dict[offsetValue])
					break;

				_first++;
				currentNode = currentNode->dict[offsetValue];
				currentNode->prefixCount++;

			}

			while (_first != _last) {
				const auto offsetValue = *_first - range_start;
				TrieNode* newNode = new TrieNode{};
				newNode->prefixCount++;
				currentNode->dict[offsetValue] = newNode;

				currentNode = newNode;
				_first++;

			}
			currentNode->isWord = true;

		}

		template<typename FwdIt>
		inline auto Search(FwdIt _first, FwdIt _last) const noexcept
			-> enable_if_t<is_same_v<typename FwdIt::value_type, T>, bool>
		{
			auto* currentNode = root_;

			while (_first != _last) {
				const auto offsetValue = *_first - range_start;
				if (!currentNode->dict[offsetValue])
					break;

				_first++;
				currentNode = currentNode->dict[offsetValue];

			}

			return (_first == _last && currentNode->isWord && currentNode->prefixCount > 0) ? true : false;
		}

		template<typename FwdIt>
		inline auto StartsWith(FwdIt _first, FwdIt _last) const noexcept
			-> enable_if_t<is_same_v<typename FwdIt::value_type, T>, bool>
		{
			auto* currentNode = root_;

			while (_first != _last) {
				const auto offsetValue = *_first - range_start;
				if (!currentNode->dict[offsetValue])
					break;

				_first++;
				currentNode = currentNode->dict[offsetValue];
			}

			return (_first == _last && currentNode->prefixCount > 0) ? true : false;
		}

		template<typename FwdIt>
		inline auto countWordsEqualTo(FwdIt _first, FwdIt _last) const noexcept
			-> enable_if_t<is_same_v<typename FwdIt::value_type, T>, size_t>
		{
			auto* currentNode = root_;

			while (_first != _last) {
				const auto offsetValue = *_first - range_start;
				if (!currentNode->dict[offsetValue])
					break;

				_first++;
				currentNode = currentNode->dict[offsetValue];
			}

			return (_first == _last && currentNode->isWord) ? currentNode->prefixCount : 0;

		}

		template<typename FwdIt>
		inline auto countWordsStartingWith(FwdIt _first, FwdIt _last) const noexcept
			-> enable_if_t<is_same_v<typename FwdIt::value_type, T>, size_t>
		{
			size_t count = 0;
			auto* currentNode = root_;

			while (_first != _last) {
				const auto offsetValue = *_first - range_start;
				if (!currentNode->dict[offsetValue])
					break;

				_first++;
				currentNode = currentNode->dict[offsetValue];
			}

			return _first == _last ? currentNode->prefixCount : 0;
		}

		template<typename FwdIt>
		inline auto erase(FwdIt _first, FwdIt _last)
			-> enable_if_t<is_same_v<typename FwdIt::value_type, T>, void>
		{
			auto* currentNode = root_;

			while (_first != _last) {
				const auto offsetValue = *_first - range_start;
				if (!currentNode->dict[offsetValue])
					break;

				_first++;
				currentNode = currentNode->dict[offsetValue];
				currentNode->prefixCount--;
			}

		}

	};

}