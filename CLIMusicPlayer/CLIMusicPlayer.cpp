#include <iostream>
#include <windows.h>
#include <filesystem>
#include <string>

int main()
{
    // Check if music directory exits and create it
    if (std::filesystem::is_directory("music") || !std::filesystem::exists("music"))
    {
        std::filesystem::create_directory("music");
    }

   
    // get the path for music folder
    std::wstring path = std::filesystem::current_path().wstring() + L"/music";
    

    // Change it to correct the /
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '\\')
            path[i] = '/';
    }


    bool played = PlaySound(path.c_str(), NULL, SND_SYNC);
    std::cout << played;

    std::cin.get();
    return 0;
}