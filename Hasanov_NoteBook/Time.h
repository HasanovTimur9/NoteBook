#pragma once
#include <iomanip>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>



class Time {
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
public:
    Time(); 
    Time(int day, int month, int year, int hour, int minute); 

    void setTimeToCurrent();

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();


    bool IsEarlierThan(const Time& other) const;

    nlohmann::json Time::toJson() const;
    Time(const nlohmann::json& j);
};