#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

int main()
{
    std::string filename{"day1.txt"};
    std::ifstream input{filename};

    if (!input.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::priority_queue<int> pq = {};
    pq.push(0);
    pq.push(0);
    pq.push(0);

    int counter{0};
    for (std::string line; std::getline(input, line);)
    {
        if (line.empty())
        {
            if (pq.top() > counter)
            {
                pq.pop();
                pq.push(counter);
            }
            counter = 0;
        }
        else
        {
            const char *data = line.data();
            counter -= std::atoi(data);
        }
    }

    int total{0};
    int last{0};
    while (!pq.empty())
    {
        last = pq.top();
        total += last;
        pq.pop();
    }

    std::cout << "Part 1: " << last * -1 << std::endl;
    std::cout << "Part 2: " << total * -1 << std::endl;

    return 0;
}