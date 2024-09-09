#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: no file to read" << '\n';
        return 1;
    }
    std::ifstream file(argv[1]);
    char out;
    char mass[16];
    for(int x_counter = 0; out != EOF; x_counter++)
    {
        if(x_counter % 16 == 0)
        {
            if (x_counter != 0) 
            {
                std::cout << '|' << mass << '|' << '\n';
            }
            std::cout << std::setw(8) << std::setfill('0') << std::hex << " ";
        }
        out = file.get();
        mass[x_counter%16] = (out > ' ' && out < '~') ? out : '.';
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)out << " ";
        if(x_counter % 8 == 0) std::cout <<" ";
    }
    std::cout << '\n';
}