#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ranges>
#include <vector>

int Day3_1(std::ifstream& inputFile)
{
	int answer = 0;

	for (const std::string& line : std::ranges::istream_view<std::string>(inputFile))
	{
		int left = 0, right = 0, leftPos = 0, rightPos = 0;
		for (size_t i = 0; i < line.size() - 1; ++i)
		{
			char c = line[i];
			int value = c - '0'; // Convert character digit to integer
			if (value > left)
			{
				left = value;
				leftPos = i;
			}
		}

		for (size_t i = line.size(); i > leftPos; --i)
		{
			char c = line[i];
			int value = c - '0'; // Convert character digit to integer
			if (value > right)
			{
				right = value;
				rightPos = i;
			}
		}

		answer += (left * 10 + right);
	}

	return answer;
}

long long Day3_2(std::ifstream& inputFile)
{
	long long answer = 0;

	std::vector<int> digits;

	for (const std::string& line : std::ranges::istream_view<std::string>(inputFile))
	{
		digits.clear();
		long long lineAnswer = 0;
		for (size_t i = 0; i < line.size(); ++i)
		{
			char c = line[i];
			int digit = c - '0';

			while (!digits.empty() &&
					digits.back() < digit &&
					((digits.size() - 1) + (line.size() - i) >= 12))
			{
				digits.pop_back();
			}

			if (digits.size() < 12)
				digits.push_back(digit);
		}

		for (size_t i = 0; i < digits.size(); ++i)
		{
			lineAnswer = lineAnswer * 10 + digits[i];
		}
		answer += lineAnswer;
	}

	return answer;
}

int main()
{
	std::ifstream inputFile("day3_input1.txt");
	if (!inputFile)
	{
		std::cerr << "Error opening file." << std::endl;
		return 1;
	}

	std::cout << "Day 3 : " << Day3_1(inputFile) << std::endl;

	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);

	std::cout << "Day 3 part 2 : " << Day3_2(inputFile) << std::endl;
}