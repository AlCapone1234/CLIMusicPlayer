#pragma once
#include <iostream>
#include <vector>

class Music
{
public:
	std::wstring path;
    int fileIndex;
	std::wstring fileName;
	inline static std::vector<Music> musics;
	inline static int currentFiles;

	Music(std::wstring path);
};

