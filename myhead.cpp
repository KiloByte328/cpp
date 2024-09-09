#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc == 2 || argc == 4)
    {
        if(argv[1][0] != '-')
        {
            std::ifstream out(argv[1]);
            if(!out)
            {
                std::cerr << "Error: cannot open file";
                out.close();
                return 3;
            }
            if(!argv[3][0] || argv[3][0] <= '0')
            {
                std::cerr << "Error: the number must be positive";
                out.close();
                return 4;
            }
            if(argc == 4)
            { 
                if(argv[2][1] == 'n')
                {
                    int tmp = argv[3][0] - '0';
                    for(int i = 0; i <= tmp;i++)
                    {
                        std::string line;
                        std::getline(out, line);
                        std::cout << line << '\n';
                    }
                    std::cout << '\n';
                    out.close();
                    return 0;
                }
                if (argv[2][1] == 'c')
                {
                    int tmp = argv[3][0] - '0';
                    for (int i = 0; i < tmp; i++)
                    {
                        char output = out.get();
                        std::cout << output;
                    }
                    std::cout << '\n';
                    out.close();
                    return 0;
                }
            else
            {
                std::cerr << "Error: arguments need to be -n <lines> or -c <bytes>";
                out.close();
                return 2;
            }
            }
            else
            {
                for(;!out.eof();)
                {
                    std::string line;
                    std::getline(out, line);
                    std::cout << line << '\n';
                }
            }
        }
    }
    else
    {
        std::string c;
        std::cin >> c;
        std::cout << '\n' << c;
        return 0;
    }
}