#include "Time.h"

Time::Time() {
    setTimeToCurrent();
}

Time::Time(int year, int month, int day, int hour, int minute):
    day(day), month(month), year(year), hour(hour), minute(minute) {}

void Time::setTimeToCurrent() {
    auto now = std::chrono::system_clock::now();
    time_t now_c = std::chrono::system_clock::to_time_t(now);
    tm* now_tm = std::localtime(&now_c);

    this->day = now_tm->tm_mday;
    this->month = now_tm->tm_mon + 1; 
    this->year = now_tm->tm_year + 1900; 
    this->hour = now_tm->tm_hour; 
    this->minute = now_tm->tm_min; 
}

int Time::getYear() {
    return this->year;
}
int Time::getMonth() {
    return this->month;
}
int Time::getDay() {
    return this->day;
}
int Time::getHour() {
    return this->hour;
}
int Time::getMinute() {
    return this->minute;
}

bool Time::IsEarlierThan(const Time& other) const {
    if (this->year < other.year) return true;
    if (this->year > other.year) return false;
    if (this->month < other.month) return true;
    if (this->month > other.month) return false;
    if (this->day < other.day) return true;
    if (this->day > other.day) return false;
    if (this->hour < other.hour) return true;
    if (this->hour > other.hour) return false;
    return this->minute < other.minute;
}

nlohmann::json Time::toJson() const {
    nlohmann::json j;
    j["day"] = this->day;
    j["month"] = this->month;
    j["year"] = this->year;
    j["hour"] = this->hour;
    j["minute"] = this->minute;
    return j;
}

Time::Time(const nlohmann::json& j): 
    day(j["day"]), month(j["month"]), year(j["year"]), hour(j["hour"]), minute(j["minute"]) {}