#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include "mtTools.h"
void get_need_file(std::string path, std::vector<std::string>& file, std::string ext)
{
	intptr_t file_handle = 0;
	struct _finddata_t file_info;
	std::string temp;
	if ((file_handle = _findfirst(temp.assign(path).append("\\*" + ext).c_str(), &file_info)) != -1)
	{
		do
		{
			file.push_back(temp.assign(path).append("\\").append(file_info.name));
		} while (_findnext(file_handle, &file_info) == 0);
		_findclose(file_handle);
	}
}