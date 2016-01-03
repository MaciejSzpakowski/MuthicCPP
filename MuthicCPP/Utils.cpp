#include "Utils.h"

#define ISWHITE(c) (c==' ' || c=='\t')

namespace game
{
	namespace utils
	{
		wstring rtrim(const wstring& input, int l, int r)
		{			
			if (ISWHITE(input[l]) && l<r)
				return rtrim(input, l + 1, r);
			else if (ISWHITE(input[r]) && l<r)
				return rtrim(input, l, r - 1);
			else
				return wstring(input.begin() + l, input.begin() + r + 1);
		}

		wstring Trim(const wstring& str)
		{
			return rtrim(str, 0, (int)str.length() - 1);
		}

		void GetFontUv(vector<RECT>& uv)
		{
			uv.push_back({ 0,0,5,10 });
			uv.push_back({ 9,0,10,10 });
			uv.push_back({ 11,0,14,10 });
			uv.push_back({ 15,0,20,10 });
			uv.push_back({ 21,0,26,10 });
			uv.push_back({ 27,0,36,10 });
			uv.push_back({ 37,0,43,10 });
			uv.push_back({ 44,0,45,10 });
			uv.push_back({ 46,0,49,10 });
			uv.push_back({ 50,0,53,10 });
			uv.push_back({ 54,0,57,10 });
			uv.push_back({ 58,0,63,10 });
			uv.push_back({ 65,0,66,10 });
			uv.push_back({ 67,0,70,10 });
			uv.push_back({ 72,0,73,10 });
			uv.push_back({ 74,0,77,10 });
			uv.push_back({ 77,0,82,10 });
			uv.push_back({ 83,0,86,10 });
			uv.push_back({ 89,0,94,10 });
			uv.push_back({ 95,0,100,10 });
			uv.push_back({ 101,0,106,10 });
			uv.push_back({ 107,0,112,10 });
			uv.push_back({ 113,0,118,10 });
			uv.push_back({ 119,0,124,10 });
			uv.push_back({ 125,0,130,10 });
			uv.push_back({ 131,0,136,10 });
			uv.push_back({ 137,0,138,10 });
			uv.push_back({ 140,0,141,10 });
			uv.push_back({ 143,0,148,10 });
			uv.push_back({ 149,0,154,10 });
			uv.push_back({ 155,0,160,10 });
			uv.push_back({ 161,0,166,10 });
			uv.push_back({ 167,0,177,10 });
			uv.push_back({ 178,0,185,10 });
			uv.push_back({ 186,0,192,10 });
			uv.push_back({ 193,0,199,10 });
			uv.push_back({ 200,0,206,10 });
			uv.push_back({ 207,0,213,10 });
			uv.push_back({ 213,0,219,10 });
			uv.push_back({ 219,0,226,10 });
			uv.push_back({ 227,0,233,10 });
			uv.push_back({ 234,0,235,10 });
			uv.push_back({ 236,0,240,10 });
			uv.push_back({ 241,0,247,10 });
			uv.push_back({ 248,0,253,10 });
			uv.push_back({ 254,0,261,10 });
			uv.push_back({ 262,0,268,10 });
			uv.push_back({ 269,0,276,10 });
			uv.push_back({ 277,0,282,10 });
			uv.push_back({ 283,0,290,10 });
			uv.push_back({ 291,0,297,10 });
			uv.push_back({ 298,0,304,10 });
			uv.push_back({ 305,0,310,10 });
			uv.push_back({ 311,0,317,10 });
			uv.push_back({ 318,0,325,10 });
			uv.push_back({ 325,0,336,10 });
			uv.push_back({ 336,0,342,10 });
			uv.push_back({ 343,0,350,10 });
			uv.push_back({ 351,0,357,10 });
			uv.push_back({ 358,0,360,10 });
			uv.push_back({ 361,0,365,10 });
			uv.push_back({ 366,0,368,10 });
			uv.push_back({ 369,0,374,10 });
			uv.push_back({ 374,0,380,10 });
			uv.push_back({ 380,0,382,10 });
			uv.push_back({ 384,0,389,10 });
			uv.push_back({ 390,0,395,10 });
			uv.push_back({ 396,0,401,10 });
			uv.push_back({ 402,0,407,10 });
			uv.push_back({ 408,0,413,10 });
			uv.push_back({ 414,0,417,10 });
			uv.push_back({ 418,0,423,10 });
			uv.push_back({ 424,0,429,10 });
			uv.push_back({ 430,0,431,10 });
			uv.push_back({ 431,0,433,10 });
			uv.push_back({ 434,0,438,10 });
			uv.push_back({ 439,0,440,10 });
			uv.push_back({ 441,0,448,10 });
			uv.push_back({ 449,0,454,10 });
			uv.push_back({ 455,0,460,10 });
			uv.push_back({ 461,0,466,10 });
			uv.push_back({ 467,0,472,10 });
			uv.push_back({ 473,0,476,10 });
			uv.push_back({ 477,0,482,10 });
			uv.push_back({ 482,0,485,10 });
			uv.push_back({ 486,0,491,10 });
			uv.push_back({ 492,0,497,10 });
			uv.push_back({ 498,0,507,10 });
			uv.push_back({ 508,0,513,10 });
			uv.push_back({ 514,0,519,10 });
			uv.push_back({ 520,0,525,10 });
			uv.push_back({ 526,0,529,10 });
			uv.push_back({ 530,0,531,10 });
			uv.push_back({ 533,0,536,10 });
			uv.push_back({ 536,0,541,10 });
		}

		void WriteBinary(std::ofstream& file, int* value)
		{
			file.write((const char*)value, 4);
		}
		void WriteBinary(std::ofstream& file, float* value)
		{
			file.write((const char*)value, 4);
		}
		void WriteBinary(std::ofstream& file, double* value)
		{
			file.write((const char*)value, 8);
		}
		void WriteBinary(std::ofstream& file, const wstring& value)
		{
			for (int i = 0; i < value.length() + 1; i++)
				file.write((const char*)value.data() + i*2, 1);
		}

		void ReadBinary(std::ifstream& file, int* value)
		{
			file.read((char*)value, 4);
		}

		void ReadBinary(std::ifstream& file, float* value)
		{
			file.read((char*)value, 4);
		}

		void ReadBinary(std::ifstream& file, double* value)
		{
			file.read((char*)value, 8);
		}

		void ReadBinary(std::ifstream& file, wstring* value)
		{
			int c = 0;
			while (true)
			{
				file.read((char*)(&c), 1);
				if (c == 0)
					return;
				else
					value->push_back(c);
			}
		}
	}
}