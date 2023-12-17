#include <bitset>
#include <iostream>

int main() {
    std::string s = std::bitset< 64 >( 5 ).to_string(); // string conversion

    std::cout << std::bitset< 64 >( 5 ) << ' '; // direct output

    std::bitset< 64 > input;
    std::cin >> input;
    unsigned long ul = input.to_ulong();
    std::cout << ul << std::endl;
}