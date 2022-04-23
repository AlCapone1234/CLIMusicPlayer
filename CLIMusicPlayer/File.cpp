#include "File.h"

void File::changeSlashes(std::wstring& path)
{
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '\\')
            path[i] = '/';
    }
}