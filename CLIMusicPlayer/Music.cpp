#include "Music.h"

Music::Music(std::wstring path)
{
	this->path = path;

	bool hasFoundSlash = false;

	// Finds the first slash going backwards and then deletes all the characters
	// before the slash
	for (int i = path.length(); i >= 0; i--)
	{
		if (!hasFoundSlash && path[i] == '/' || path[i] == '\\')
		{
			hasFoundSlash = true;
		}

		if (hasFoundSlash)
		{
			path[i] = ' ';
		}

	}

	// Goes through the string again to find the fileName because the other characters that are not
	// the filename already got deleted.
	for (int i = 0; i < path.length(); i++)
	{
		if (path[i] != ' ')
		{
			fileName += path[i];
		}
	}

}