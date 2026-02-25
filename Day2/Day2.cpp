#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ranges>

bool IsRepeatedPattern(const std::string& numStr)
{
	size_t len = numStr.size();

	// Try all possible pattern lengths from 1 to len/2
	for (size_t patternLen = 1; patternLen <= len / 2; ++patternLen)
	{
		// Check if the total length is divisible by the pattern length
		if (len % patternLen == 0)
		{
			std::string pattern = numStr.substr(0, patternLen);
			bool isMatch = true;

			// Check if the entire string is made of this pattern repeated
			for (size_t i = patternLen; i < len; i += patternLen)
			{
				if (numStr.substr(i, patternLen) != pattern)
				{
					isMatch = false;
					break;
				}
			}

			if (isMatch)
			{
				return true;
			}
		}
	}

	return false;
}

long long Day2_1(std::ifstream& inputFile)
{
	long long answer = 0;
	std::string line;

	// directions state one long line, but making sure.
	for (const std::string& line : std::ranges::istream_view<std::string>(inputFile))
	{
		std::stringstream stream1(line);
		std::string rangeOfIDs;

		while (std::getline(stream1, rangeOfIDs, ','))
		{
			std::stringstream stream2(rangeOfIDs);
			std::string startNumStr, endNumStr;
			if (std::getline(stream2, startNumStr, '-') && std::getline(stream2, endNumStr, '-'))
			{
				long long startNum = std::stoll(startNumStr);
				long long endNum = std::stoll(endNumStr);

				for (long long num = startNum; num <= endNum; ++num)
				{
					std::string numStr = std::to_string(num);

					// Original Day2_1 logic: only even length, split in half exactly
					if (numStr.size() % 2 != 0)
					{
						continue;
					}

					size_t halfLen = numStr.size() / 2;
					std::string leftHalf = numStr.substr(0, halfLen);
					std::string rightHalf = numStr.substr(halfLen, halfLen);

					if (leftHalf == rightHalf)
					{
						answer += num;
					}
				}
			}
		}
	}

	return answer;
}

long long Day2_2(std::ifstream& inputFile)
{
	long long answer = 0;
	std::string line;

	// directions state one long line, but making sure.
	for (const std::string& line : std::ranges::istream_view<std::string>(inputFile))
	{
		std::stringstream stream1(line);
		std::string rangeOfIDs;

		while (std::getline(stream1, rangeOfIDs, ','))
		{
			std::stringstream stream2(rangeOfIDs);
			std::string startNumStr, endNumStr;
			if (std::getline(stream2, startNumStr, '-') && std::getline(stream2, endNumStr, '-'))
			{
				long long startNum = std::stoll(startNumStr);
				long long endNum = std::stoll(endNumStr);

				for (long long num = startNum; num <= endNum; ++num)
				{
					std::string numStr = std::to_string(num);
					if (IsRepeatedPattern(numStr))
					{
						answer += num;
					}
				}
			}
		}
	}

	return answer;
}

int main()
{
	std::ifstream inputFile("input1.txt");
	if (!inputFile)
	{
		std::cerr << "Error opening file." << std::endl;
		return 1;
	}

	std::cout << "Day 2 : " << Day2_1(inputFile) << std::endl;
	
	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);

	std::cout << "Day 2 : " << Day2_2(inputFile) << std::endl;
}