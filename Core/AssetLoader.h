#pragma once
#include "Header.h"
#include "Buffer.h"

class AssetLoader
{
public:
	enum FileMode {
		OPEN_MODE_TEXT,
		OPEN_MODE_BIT,
	};

	static void AddSearchPath(const std::string& path);
	static FILE* FileOpen(const std::string& fileName, FileMode fileMode = OPEN_MODE_TEXT);
	static bool FileExist(const std::string& fileName);
	static Buffer ReadText(const std::string& fileName);
	static size_t GetFileSize(FILE* fp);
protected:
	static std::set<std::string> m_SearchPaths;
};

