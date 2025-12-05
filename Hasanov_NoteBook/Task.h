#pragma once
#include "Note.h"

class Task : public Note {
private:
	Time deadline;
	bool done;
public:

	Task(std::string name, std::string text, std::string author, Time creationTime, 
		Time editTime, std::vector <std::string> Tags, Time deadline, bool done);
	~Task();

	std::string getType() const override;
	Time getDeadline() const;
	bool getDone() const;

	void SetDeadline(const Time& deadline);
	void SetDone(bool done);

	void EditTask(std::string name, std::string text, std::string author,
		Time editTime, std::vector<std::string> tags,
		Time deadline, bool done) ;
 
	nlohmann::json toJson() override;
	Task(const nlohmann::json& j);
};