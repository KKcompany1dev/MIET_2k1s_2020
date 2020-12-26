#ifndef CONFIG_ACCESS_H
#define CONFIG_ACCESS_H

#include <list>
#include <fstream>
#include <string>
#include <iostream>

#include <codecvt>

void fillListFromConfigFile(std::list<std::wstring>& list, std::wstring filePath, std::wstring query);

#endif // !CONFIG_ACCESS_H
