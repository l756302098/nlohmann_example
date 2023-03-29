/*
 * main.cpp
 *
 *  Created on: 12 01, 2021
 *      Author: liyanlong
 */
#include <fstream>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

struct DeviceInfo
{
	std::string ncuSn;
    std::string deviceSn;
	std::uint64_t time;
};

struct TestInfo
{
	bool happy;
	float pi;
    void to_json(json& j) {
        j = json{{"happy", this->happy}, {"pi", this->pi}};
    }

    void from_json(const json& j) {
        j.at("happy").get_to(this->happy);
        j.at("pi").get_to(this->pi);
    }
};

int main(int argc, char *argv[])
{
    std::cout << "Start json demo!" << std::endl;
    // read a JSON file
    json j;
    try
    {
        std::ifstream i("file.json");
        i >> j;
    }
    catch(json::exception& e)
    {
        std::cout << "id:" << e.id << " error:"  << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "unknown error." << std::endl;
    }

    std::cout << "is_null:" << j.is_null() << std::endl;
    TestInfo ti;
    if(j.is_null())
    {
        //init
        ti = {true,3.14};
        ti.to_json(j);
    }
    else
    {
        std::string s = j.dump();
        std::cout << "json:" << s << std::endl;
        ti.from_json(j);
        std::cout << "happy:" << ti.happy << " pi:" << ti.pi;
    }

    std::ofstream o("file.json");
    o << j << std::endl;

    /*
    json j1;
    ti.to_json(j1);

    std::ofstream o("pretty.json");
    o << j1 << std::endl;
    */

    return 0;
}

