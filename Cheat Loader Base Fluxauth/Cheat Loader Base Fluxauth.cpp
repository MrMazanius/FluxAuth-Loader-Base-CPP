/*

    <---Credits--->

    FluxAuth:  https://fluxauth.com
    skCrypter: https://github.com/skadro-official/skCrypter/

    <------------->


    ->    Loader Base made by @Obiot882 on Discord
    ->    Credits are appreciated!
    

    <------------->

*/

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "flux.hpp"
#include "xor.h";


auto success()
{
    system(skCrypt("cls"));
    std::cout << skCrypt("\n\n Authentication successful.") << '\n'; 

    system(skCrypt("pause >NUL")); // Continue with your loader here
}

std::string RandomString(int len) // For the Console Title
{
    std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string newstr;
    int pos;
    while (newstr.size() != len) {
        pos = ((rand() % (str.size() - 1)));
        newstr += str.substr(pos, 1);
    }
    return newstr;
}

int main()
{
    auto title = RandomString(24);
    SetConsoleTitleA(title.c_str());

    std::cout << skCrypt("--> Cheat Loader Base <--\n");

    flux::set_application("application_id_here");

    Sleep(500);

    std::string usrKey;
    std::cout << skCrypt("\n\n  Key: ");
    std::cin >> usrKey;

    try {
        flux::authenticate(usrKey);
        success();
    }

    catch (std::runtime_error& e) {
        system(skCrypt("cls"));

        std::cout << '\n' << e.what();

        Sleep(1000);
        exit(1);
    }

    return 0;
}