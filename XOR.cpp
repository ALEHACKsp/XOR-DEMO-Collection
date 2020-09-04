#include "Windows.h"
#include <iostream>

/*

XOR Function by Fiereu

*/
int XOR(DWORD adress, UINT size, BYTE* key, UINT KeySize)
{
    //Check for Buffer Overflow
    if (size > 2048)
        return -1;
    BYTE BUFFER[2048];

    DWORD oldProt;

    //Remove Protection
    VirtualProtect((void*)adress, size, PAGE_EXECUTE_READWRITE, &oldProt);
    //Copy String
    memcpy((void*)&BUFFER, (void*)adress, size);
    //Restore Protection
    VirtualProtect((void*)adress, size, oldProt, nullptr);

    //Loop through Buffer
    UINT index = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (index > KeySize)
            index = 0;

        BUFFER[i] = BUFFER[i] ^ key[index];
        index++;
    }

    //Remove Protection
    VirtualProtect((void*)adress, size, PAGE_EXECUTE_READWRITE, &oldProt);
    //Copy String
    memcpy((void*)adress, (const void*)BUFFER, size);
    //Restore Protection
    VirtualProtect((void*)adress, size, oldProt, nullptr);

    //return address
    return (int)adress;
}



int main()
{
    const char* msg = "HELLOWORLD";


    BYTE KEY[5] = { 0xDE,0xAD,0xBE,0xEF,0x00 };


    std::cout << "ORG MSG: " << msg << std::endl << std::endl;

    XOR((DWORD)(const void*)msg, strlen(msg), KEY, 5);

    std::cout << "XOR MSG: " << msg << std::endl << std::endl;

    XOR((DWORD)(const void*)msg, strlen(msg), KEY, 5);

    std::cout << "ORG MSG: " << msg << std::endl << std::endl;
    while (true) {};
}


