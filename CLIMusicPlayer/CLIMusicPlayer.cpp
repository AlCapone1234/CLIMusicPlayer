#include <iostream>
#include <windows.h>
#include <filesystem>
#include <string>
#include <vector>
#include <conio.h>

#include "Music.h"
#include "File.h"

void OutputScreen()
{
    for (size_t i = 0; i < Music::musics.size(); i++)
    {
        std::cout << Music::musics.at(i).fileIndex << ": ";
        std::wcout << Music::musics.at(i).fileName << std::endl;
    }

    std::cout << "________________________________________" << std::endl;
    std::cout << "0: Stop" << std::endl;
}

int main()
{
    // Check if music directory exits and create it
    if (std::filesystem::is_directory("music") || !std::filesystem::exists("music"))
    {
        std::filesystem::create_directory("music");
        Music::currentFiles = 0;
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
        Music::currentFiles++;
        Music::musics.at(i).fileIndex = Music::currentFiles;
    }
    
    OutputScreen();

    int pick;

    // Loop
    while (1)
    {
        std::cin >> pick;

        if (pick == 0)
        {
            PlaySound(NULL, 0, 0);
        }
        else
        {
            for (int i = 0; i < Music::musics.size(); i++)
            {
                if (pick == Music::musics.at(i).fileIndex)
                {
                    PlaySound(Music::musics.at(i).path.c_str(), NULL, SND_ASYNC);
                }
            }
        }

        system("cls");
        OutputScreen();
    }

    //bool played = PlaySound(path.c_str(), NULL, SND_ASYNC);
    //std::cout << played;

    std::cin.get();
    return 0;
}