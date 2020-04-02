#include "cAudioString.h"


#ifdef CAUDIO_PLATFORM_WIN

#include "Windows.h"

const char* cAudio::toUTF8(const cAudioString& str)
{
	static int id = 0;
	static char buffer[8][1024];
	id = ++id & 0x7;

	int buff_size = WideCharToMultiByte(
		CP_UTF8,
		0,
		str.c_str(),
		(int)(str.size() < 1023 ? str.size() : 1023),
		buffer[id],
		1023,
		0,
		false);
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

#endif