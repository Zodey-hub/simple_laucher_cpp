#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace Setting
{
    class Setting
    {
    public:
        struct App
        {
            std::string name;
            std::string path;
        };

        std::vector<App> apps;

    public:
        Setting(const char *filename)
        {
            std::fstream setting_file;
            setting_file.open(filename);
            std::string line;
            size_t split_position;

            while (getline(setting_file, line))
            {
                split_position = line.find("=");
                apps.push_back(App{.name = line.substr(0, split_position), .path = line.substr(split_position + 1)});
            }
            setting_file.close();
        }
    };

}
#endif