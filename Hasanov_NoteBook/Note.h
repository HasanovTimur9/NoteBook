#pragma once
#include <iostream>
#include "Time.h"
#include <vector>
#include <nlohmann/json.hpp>

class Note {
private:
	std::string name;
	std::string text;
	std::string author;
	Time creationTime;
	Time editTime;
	std::vector<std::string> Tags;

public:

	Note(std::string name, std::string text, std::string author, Time creationTime, Time editTime, std::vector<std::string> Tags);

	virtual ~Note();

	void EditNote
	(std::string name, std::string text, std::string author, Time editTime, std::vector<std::string> Tags);

	virtual std::string getType() const;
	std::string getName() const;
	std::string getText() const;
	std::string getAuthor() const;
	Time getCreationTime() const;
	Time getEditTime() const;
	std::vector<std::string> getTags() const;

	void SetName(const std::string& name);
	void SetText(const std::string& text);
	void SetAuthor(const std::string& author);
	void SetEditTime(const Time& editTime);
	void SetTags(const std::vector<std::string>& tags);

	std::string ConvertFromUTF8(const std::string& input);
	std::string ConvertToUTF8(const std::string& input);
	virtual nlohmann::json toJson();
	Note(const nlohmann::json& j);
};