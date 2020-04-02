// Copyright (c) 2008-2011 Raynaldo (Wildicv) Rivera, Joshua (Dark_Kilauea) Jones, Murat (wolfmanfx) Sari
// This file is part of the "cAudio Engine"
// For conditions of distribution and use, see copyright notice in cAudio.h

#pragma once

#include "cAudioPlatform.h"
#include "cSTLAllocator.h"
#include "cAudioString.h"

#ifdef CAUDIO_PLATFORM_WIN
#  include <direct.h>
#  include <io.h>
#endif

#ifdef CAUDIO_PLATFORM_LINUX
#	include <dirent.h> 
#	include <stdio.h> 
#	include <cstring>
#endif

namespace cAudio
{

//! Grabs the current extention of a given string.
inline cAudioString getExt(const cAudioString& filename)
{
	if(filename.find_last_of(_CTEXT(".")) == cAudioString::npos) return filename;
	return filename.substr(filename.find_last_of(_CTEXT(".")) + 1, filename.length()-filename.find_last_of(_CTEXT("."))-1);
}

//! Returns a list of files/directories in the supplied directory.  Used internally for auto-installation of plugins.
cAudioVector<cAudioString>::Type getFilesInDirectory(cAudioString path);
};
