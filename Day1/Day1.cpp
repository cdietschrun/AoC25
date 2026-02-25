#include <iostream>
#include <fstream>
#include <string>
#include <ranges>

int Day1_1(std::ifstream& inputFile)
{
	int password = 0;
	int dial = 50;

	for (const std::string& line : std::ranges::istream_view<std::string>(inputFile))
	{
		if (line.size() < 2)
		{
			std::cerr << "Invalid line: " << line << std::endl;
			return 1;
		}

		int amount = stoi(line.substr(1)) % 100;

		switch (line[0])
		{
		case 'L':
			dial -= amount;
			if (dial < 0) dial += 100;
			break;
		case 'R':
			dial += amount;
			if (dial > 99) dial -= 100;
			break;
		}

		if (dial == 0)
			password++;
	}

	return password;
}

int countZeroHits(int start, int amount, bool left)
{
	int hits = 0;
	int pos = start;
	int step = left ? -1 : 1;
	for (int i = 1; i <= amount; ++i)
	{
		pos = (pos + step + 100) % 100;
		if (pos == 0)
			++hits;
	}
	return hits;
}

int Day1_2(std::ifstream& inputFile)
{
	int password = 0;
	int dial = 50;

	for (const std::string& line : std::ranges::istream_view<std::string>(inputFile))
	{
		if (line.size() < 2)
		{
			std::cerr << "Invalid line: " << line << std::endl;
			return 1;
		}

		int amount = std::stoi(line.substr(1));
		bool left = line[0] == 'L';

		password += countZeroHits(dial, amount, line[0] == 'L');

		if (left)
			dial = (dial - amount + 100) % 100;
		else
			dial = (dial + amount) % 100;
	}

	return password;
}

int main()
{
	std::ifstream inputFile("input.txt");
	if (!inputFile)
	{
		std::cerr << "Error opening file." << std::endl;
		return 1;
	}

	std::cout << "Day 1 Password: " << Day1_1(inputFile) << std::endl;

	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);

	std::cout << "Day 1 part 2 Password: " << Day1_2(inputFile) << std::endl;
}