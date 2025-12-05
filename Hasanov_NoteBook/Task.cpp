#include "Task.h"

Task::Task(std::string name, std::string text, std::string author, Time creationTime,
	Time editTime, std::vector <std::string> Tags, Time deadline, bool done) :
	Note(name, text, author, creationTime, editTime, Tags), deadline(deadline) , done(done)
{
};

Task::~Task() {
}

std::string Task::getType() const {
	return "Task";
}
Time Task::getDeadline() const {
	return this->deadline;
}
bool Task::getDone() const {
	return this->done;
}

void Task::SetDeadline(const Time& deadline) { 
	this->deadline = deadline; 
}
void Task::SetDone(bool done) { 
	this->done = done; 
}

void Task::EditTask( std::string name, std::string text, std::string  author,
	Time editTime, std::vector<std::string> tags,
	Time deadline, bool done) {
	
	Note::EditNote(name, text, author, editTime, tags);

	SetDeadline(deadline);
	SetDone(done);
}
nlohmann::json Task::toJson() {

	nlohmann::json j{};
	j["type"] = "Task";
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

	j["deadLine"] = this->getDeadline().toJson();
	j["done"] = this->getDone();
	return j;

}

Task::Task(const nlohmann::json& j): Note(j) {
	if (!j.contains("deadLine")) {
		throw std::runtime_error("Отсутствует поле 'deadLine'");
	}
	deadline = j["deadLine"];

	if (!j.contains("done")) {
		throw std::runtime_error("Отсутствует поле 'done'");
	}
	done = j["done"];

}

