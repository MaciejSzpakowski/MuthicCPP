#pragma once

#include "Proto.h"

namespace game
{
	using namespace Viva;

	namespace utils
	{
		// Remove all white spaces from front and back.
		wstring Trim(const wstring& str);

		void GetFontUv(vector<RECT>& uv);

		long long GetUniqueId();

		void WriteBinary(std::ofstream& file, int* value);
		void WriteBinary(std::ofstream& file, float* value);
		void WriteBinary(std::ofstream& file, double* value);
		void WriteBinary(std::ofstream& file, const wstring& value);

		void ReadBinary(std::ifstream& file, int* value);
		void ReadBinary(std::ifstream& file, float* value);
		void ReadBinary(std::ifstream& file, double* value);
		void ReadBinary(std::ifstream& file, wstring* value);
	}
}
