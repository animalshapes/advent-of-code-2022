#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int normalize(char c)
{
    if (c >= 65 && c <= 90)
    {
        return c - 65 + 26;
    }
    else if (c >= 97 && c <= 122)
    {
        return c - 97;
    }
    else
    {
        return -1;
    }
}

int main()
{
    std::string filename{"day3.txt"};
    std::ifstream input{filename};

    if (!input.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    int sackTotal{0};
    int badgeTotal{0};
    std::vector<int> first(52);
    std::vector<int> second(52);
    std::vector<std::vector<int>> groups(3, std::vector<int>(52));
    int groupParity{0};
    for (std::string line; std::getline(input, line);)
    {
        int lineLength = line.length();
        for (int i = 0; i < lineLength / 2; i++)
        {
            int index = normalize(line[i]);
            first[index]++;
            groups[groupParity][index]++;
        }
        for (int i = lineLength / 2; i < lineLength; i++)
        {
            int index = normalize(line[i]);
            second[index]++;
            groups[groupParity][index]++;
        }
        for (int i = 0; i < 52; i++)
        {
            if (first[i] > 0 && second[i] > 0)
            {
                sackTotal += (++i);
                break;
            }
        }

        groupParity++;

        std::fill(first.begin(), first.end(), 0);
        std::fill(second.begin(), second.end(), 0);
        if (groupParity == 3)
        {
            for (int i = 0; i < 52; i++)
            {
                if (groups[0][i] > 0 && groups[1][i] > 0 && groups[2][i] > 0)
                {
                    badgeTotal += (++i);
                    break;
                }
            }

            for (auto &row : groups)
            {
                std::fill(row.begin(), row.end(), 0);
            }
            groupParity = 0;
        }
    }

    std::cout << sackTotal << std::endl;
    std::cout << badgeTotal << std::endl;

    return 0;
}