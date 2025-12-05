#include "Meeting.h"

Meeting::Meeting(std::string name, std::string text, std::string author, Time creationTime,
	Time editTime, std::vector <std::string> Tags, Time meetingTime, std::string place) :
	Note(name, text, author, creationTime, editTime, Tags), meetingTime(meetingTime), place(place)
{
};

Meeting::~Meeting() {
}

std::string Meeting::getType() const {
	return "Meeting";
}
Time Meeting::getMeetingTime() const {
	return this->meetingTime;
}
std::string Meeting::getPlace() const {
	return this->place;
}

void Meeting::SetMeetingTime(const Time& meetingTime) {
	this->meetingTime = meetingTime;
}
void Meeting::SetPlace(std::string place) {
	this->place = place;
}

void Meeting::EditMeeting(std::string name, std::string text, std::string author,
	Time editTime, std::vector <std::string> Tags, Time meetingTime, std::string place)
{
	Note::EditNote(name, text, author, editTime, Tags);

	SetMeetingTime(meetingTime);
	SetPlace(place);
}

nlohmann::json Meeting::toJson() {
	nlohmann::json j{};
	j["type"] = "Meeting";
	j["name"] = ConvertToUTF8(this->getName());
	j["text"] = ConvertToUTF8(this->getText());
	j["author"] = ConvertToUTF8(this->getAuthor());
	j["cTime"] = this->getCreationTime().toJson();
	j["eTime"] = this->getEditTime().toJson();

	nlohmann::json tagsArray = nlohmann::json::array();
	for (const auto& tag : this->getTags()) {
		tagsArray.push_back(ConvertToUTF8(tag));
	}

	j["Tags"] = tagsArray;

	j["meetingTime"] = this->getMeetingTime().toJson();
	j["place"] = ConvertToUTF8(this->getPlace());
	return j;
}
Meeting::Meeting(const nlohmann::json& j) : Note(j) {
	if (!j.contains("meetingTime")) {
		throw std::runtime_error("Отсутствует поле 'meetingTime'");
	}
	meetingTime = j["meetingTime"];

	if (!j.contains("place")) {
		throw std::runtime_error("Отсутствует поле 'place'");
	}
	place = ConvertFromUTF8(j["place"]);

}

