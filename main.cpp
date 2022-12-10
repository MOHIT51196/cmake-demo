#include<iostream>
#include"math.hpp"

int main(){
    int inp1, inp2;

    std::cout<<"Enter first number = ";
    std::cin>>inp1;
    std::cout<<std::endl;
    std::cout<<"Enter second number = ";
    std::cin>>inp2;
    std::cout<<std::endl;

    std::cout<<"ADD = "<<Math::add(inp1 , inp2)<<std::endl;
    std::cout<<"MUL = "<<(inp1 * inp2)<<std::endl;
    if(inp2 != 0) std::cout<<"DIV = "<<Math::divd(inp1 , inp2)<<std::endl;
    std::cout<<"SUB = "<<(inp1 - inp2)<<std::endl;

    return EXIT_SUCCESS;
}