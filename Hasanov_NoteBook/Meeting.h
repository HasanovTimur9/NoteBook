#pragma once
#include "Note.h"

class Meeting : public Note {
private:
	Time meetingTime;
	std::string place;

public:
	Meeting(std::string name, std::string text, std::string author, Time creationTime,
		Time editTime, std::vector <std::string> Tags, Time meetingTime, std::string place);
	~Meeting();

	std::string getType() const override;
	Time getMeetingTime() const;
	std::string getPlace() const;

	void SetMeetingTime(const Time& meetingTime);
	void SetPlace(std::string place);

	void EditMeeting(std::string name, std::string text, std::string author,
		Time editTime, std::vector <std::string> Tags, Time meetingTime, std::string place);

	nlohmann::json toJson()  override;
	Meeting(const nlohmann::json& j);
};
