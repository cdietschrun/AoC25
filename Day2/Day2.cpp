#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ranges>

int Day2_1(std::ifstream& inputFile)
{
	int answer = 0;
	std::string line;

	// directions state one long line, but making sure.
	for (const std::string& line : std::ranges::istream_view<std::string>(inputFile))
	{		
		std::stringstream stream1(line);
		std::string rangeOfIDs;

		while (std::getline(stream1, rangeOfIDs, ','))
		{
			//std::cout << rangeOfIDs << std::endl;
			std::stringstream stream2(rangeOfIDs);
			std::string startNumStr, endNumStr;
			if (std::getline(stream2, startNumStr, '-') && std::getline(stream2, endNumStr, '-'))
			{
				int startNum = std::stoi(startNumStr);
				int endNum = std::stoi(endNumStr);

				for (int num = startNum; num <= endNum; ++num)
				{

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

}