#include "..\include\song.h"
#include <Windows.h>
#include <string>

#pragma comment(lib, "Winmm.lib")

Song::Song(std::string path) : m_path(path) {
	this->m_alias = path.substr(0, path.size() - 4);
}

Song& Song::open() {
	const std::string str = "open \"" + this->m_path + "\" type mpegvideo alias " + this->m_alias;
	const std::wstring widestr = std::wstring(str.begin(), str.end());
	const wchar_t* widecstr = widestr.c_str();
	mciSendString(widecstr, NULL, 0, NULL);
	this->m_opened = true;
	return *this;
}

Song& Song::play() {
	if (this->m_opened) {
		const std::string str = "play " + this->m_alias + (this->m_wait ? " wait" : "");
		const std::wstring widestr = std::wstring(str.begin(), str.end());
		const wchar_t* widecstr = widestr.c_str();
		mciSendString(widecstr, NULL, 0, NULL);
	}
	return *this;
}

Song& Song::wait(bool wait) {
	this->m_wait = wait;
	return *this;
}

void Song::close() {
	if (this->m_opened) {
		const std::string str = "close " + this->m_alias;
		const std::wstring widestr = std::wstring(str.begin(), str.end());
		const wchar_t* widecstr = widestr.c_str();
		mciSendString(widecstr, NULL, 0, NULL);
		this->m_opened = false;
	}
}