// Copyright (c) 2008-2011 Raynaldo (Wildicv) Rivera, Joshua (Dark_Kilauea) Jones, Murat (wolfmanfx) Sari
// This file is part of the "cAudio Engine"
// For conditions of distribution and use, see copyright notice in cAudio.h

#pragma once

#include "cAudioDefines.h"
#include "cAudioPlatform.h"
#include "cAudioMemory.h"
#include "cSTLAllocator.h"

#include <string>
#include <stdlib.h>

#ifdef CAUDIO_PLATFORM_WIN
#  include <direct.h>
#  include <io.h>
#endif

namespace cAudio
{

#if defined(UNICODE) || defined(_UNICODE)
#	define _CTEXT(x)	L ## x
#	define cstrcmp		wcscmp
#	define cAudioChar	wchar_t
#	define cfopen(N, M)	_wfopen((N).c_str(), L ## M)
#else
#	define _CTEXT(x) x
#	define cstrcmp		strcmp
#	define cAudioChar	char
#	define cfopen(N, M)	fopen(toUTF8(N), M)
#endif

#if CAUDIO_REROUTE_STRING_ALLOCATIONS == 1
	typedef std::basic_string< cAudioChar, std::char_traits<cAudioChar>, cSTLAllocator<cAudioChar> > cAudioString;
#else
#	if defined(UNICODE) || defined(_UNICODE)
		typedef std::basic_string<cAudioChar> cAudioString;
#	else
	typedef std::string cAudioString;
#	endif
#endif


	const char* toUTF8(const cAudioString& str);
	cAudioString fromUTF8(const char* str);
};

