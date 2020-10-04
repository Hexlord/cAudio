#include "cAudioString.h"


#ifdef CAUDIO_PLATFORM_WIN

#include <Windows.h>

const char* cAudio::toUTF8(const cAudioString& str)
{
	static int id = 0;
	static char buffer[8][1024];
	id = ++id & 0x7;
    int UsedDefaultChar = 0;
    int buff_size = WideCharToMultiByte(
            CP_UTF8,
            0,
            str.c_str(),
            (int)(str.size() < 1023 ? str.size() : 1023),
            buffer[id],
            1023,
            0,
            &UsedDefaultChar);
	buffer[id][buff_size] = 0;
	buffer[id][1023] = 0;
	return buffer[id];
}

cAudio::cAudioString cAudio::fromUTF8(const char* str)
{
	int str_len = (int)strlen(str);
	int buf_size = MultiByteToWideChar(CP_UTF8, 0, str, str_len, 0, 0);
	cAudioString s(buf_size, L'\0');
	MultiByteToWideChar(CP_UTF8, 0, str, str_len, &s[0], buf_size);
	return s;
}
#else
#include <stdio.h>
#include <stdlib.h>

const char* cAudio::toUTF8(const cAudioString& str)
{
    static int id = 0;
    static char buffer[8][1024];
    id = ++id & 0x7;

    size_t len = wcstombs(buffer[id], str.c_str(), str.size());
    if(len > 0u)
        buffer[id][len] = '\0';

    return buffer[id];
}

cAudio::cAudioString cAudio::fromUTF8(const char* str)
{
    wchar_t buffer[1024];
    size_t str_len = strlen(str);
    mbstowcs(buffer, str, str_len);
    buffer[str_len] = 0;
    return cAudioString(buffer);
}
#endif