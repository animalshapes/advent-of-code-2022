#include <fstream>
#include <iostream>

int main()
{
    std::string filename{"day2.txt"};
    std::ifstream input{filename};

    if (!input.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    int first{0};
    int second{0};

    for (std::string line; std::getline(input, line);)
    {
        if (line.empty())
            continue;

        switch (line.back())
        {
        case 'X':
            first += 1;
            switch (line.front())
            {
            case 'A':
                first += 3;
                second += 3;
                break;
            case 'B':
                second += 1;
                break;
            case 'C':
                first += 6;
                second += 2;
                break;
            default:
                break;
            }
            break;
        case 'Y':
            first += 2;
            second += 3;
            switch (line.front())
            {
            case 'A':
                first += 6;
                second += 1;
                break;
            case 'B':
                first += 3;
                second += 2;
                break;
            case 'C':
                second += 3;
                break;
            default:
                break;
            }
            break;
        case 'Z':
            first += 3;
            second += 6;
            switch (line.front())
            {
            case 'A':
                second += 2;
                break;
            case 'B':
                first += 6;
                second += 3;
                break;
            case 'C':
                first += 3;
                second += 1;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }

    std::cout << first << std::endl;
    std::cout << second << std::endl;

    return 0;
}