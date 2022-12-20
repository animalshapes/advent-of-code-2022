#include <iostream>
#include <fstream>

bool contains(int start1, int end1, int start2, int end2)
{
    return start1 <= start2 && end1 >= end2;
}

bool intersects(int start1, int end1, int start2, int end2)
{
    return (start1 <= start2 && end1 >= start2) || (start2 <= start1 && end2 >= start1);
}

int main()
{
    std::string filename{"day4.txt"};
    std::ifstream input{filename};

    int includes{0};
    int overlaps{0};
    for (std::string line; std::getline(input, line);)
    {
        size_t first = line.find_first_of('-');
        size_t middle = line.find(',');
        size_t last = line.find_last_of('-');
        size_t end = line.size();

        int firstStart{std::atoi(line.substr(0, first).data())};
        int firstEnd{std::atoi(line.substr(first + 1, middle - first - 1).data())};
        int secondStart{std::atoi(line.substr(middle + 1, last - middle - 1).data())};
        int secondEnd{std::atoi(line.substr(last + 1, end - last - 1).data())};

        if (contains(firstStart, firstEnd, secondStart, secondEnd) || contains(secondStart, secondEnd, firstStart, firstEnd))
        {
            includes++;
        }
        if (intersects(firstStart, firstEnd, secondStart, secondEnd))
        {
            overlaps++;
        }
    }

    std::cout << includes << std::endl;
    std::cout << overlaps << std::endl;

    return 0;
}