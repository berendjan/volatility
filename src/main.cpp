#include <Variance.cpp>

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Check lib directory for code" << std::endl;

    volatility::StreamingSlidingWindowVolatility vola;

    for (int i = 0; i < 4320; i++)
    {
        vola.add_point(2.0, i);
    }

    for (int i = 0; i < 4320 / 2; i++)
    {
        vola.add_point(4.0, i);
    }

    std::cout << "volatility: " << vola.get_volatility() << std::endl;

    return 0;
}
