#include "cUtils.h"

#ifdef CAUDIO_PLATFORM_WIN

#include "Windows.h"

#endif

cAudio::cAudioVector<std::basic_string<wchar_t>>::Type cAudio::getFilesInDirectory(cAudioString path)
{
	cAudioVector<cAudioString>::Type FileList;
#ifdef CAUDIO_PLATFORM_WIN
	cAudioString search = path + _CTEXT("\\") + cAudioString(_CTEXT("*.*"));
	WIN32_FIND_DATA info;
	HANDLE h = FindFirstFile(search.c_str(), &info);
	if (h != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(cstrcmp(info.cFileName, _CTEXT(".")) == 0 || cstrcmp(info.cFileName, _CTEXT("..")) == 0))
			{
				FileList.push_back(info.cFileName);
			}
		}
		while (FindNextFile(h, &info));
		FindClose(h);
	}
#endif

#ifdef CAUDIO_PLATFORM_LINUX
	DIR           *d;
	struct dirent *dir;
	d = opendir(path.c_str());
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if( strcmp( dir->d_name, "." ) == 0 || strcmp( dir->d_name, ".." ) == 0 ) { continue; }
			if( dir->d_type == DT_DIR ) continue;
			FileList.push_back(dir->d_name);
		}

		closedir(d);
	}
#endif

	return FileList;
}
