#include <iostream>
#include <windows.h>
#include <filesystem>
#include <string>
#include <vector>

#include "Music.h"
#include "File.h"

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
    File::changeSlashes(path);

    std::wstring defaultPath = path;

    // Check for music files in the music folder
    for (const auto& file : std::filesystem::directory_iterator(defaultPath))
    {
        std::wstring currentPath = file.path().wstring();
        File::changeSlashes(currentPath);
        Music::musics.push_back(Music(currentPath));
    }

    for (size_t i = 0; i < Music::musics.size(); i++)
    {
        std::wcout << Music::musics.at(i).fileName << std::endl;
        std::wcout << Music::musics.at(i).path << std::endl;
    }



    //bool played = PlaySound(path.c_str(), NULL, SND_ASYNC);
    //std::cout << played;

    std::cin.get();
    return 0;
}