

#include <iostream>
#include <bitset>
#include <windows.h>
using namespace std;


void ChangeOneBit(int &Number1, int &Number2, int Bit)
{


    //HOW TO USE BITSET
    //WE CONVERT OUR NUMBERS TO A BIT USING THE CONSTRUCTOR AND THEN PRINT ON THE SCREEN
    std::bitset<sizeof(int) * 4> Number1toBit(Number1);
    std::bitset<sizeof(int) * 4> Number2toBit(Number2);

    std::cout << "The bit to change : " << Bit << '\n';
    std::cout << "In bit number one : " << Number1toBit.to_string() << " and the number is: " << Number1 << '\n';
    std::cout << "In bit number two : " << Number2toBit.to_string() << " and the number is: " << Number2 << '\n';

    //TO HAVE AN AUXILIAR
    std::bitset<1> Axuliar;

    //CHANGE THE BIT
    Axuliar[0] = Number1toBit[Bit -1 ];
    Number1toBit[Bit - 1] = Number2toBit[Bit - 1];
    Number2toBit[Bit - 1] = Axuliar[0];

    Axuliar.reset();
    //WE KNOW CHANGE THE BITS, WE CAN PRINT TO SEE THEN IN THE SCREEN 

    Number1 = Number1toBit.to_ulong();
    Number2 = Number2toBit.to_ulong();

    std::cout << "In bit number one changed: " << Number1toBit.to_string() << " and the number is: " << Number1 << '\n';
    std::cout << "In bit number two changed: " << Number2toBit.to_string() << " and the number is: " << Number2 << '\n';

}


int main()
{
    //WE CAN USE THIS TO CHANGE THE CONSOLE COLOR ONLY IN WINDOS
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    //THE SEND NUMBERS
    int num = 11, num2 = 10;
    ChangeOneBit(num, num2, 1);
}

