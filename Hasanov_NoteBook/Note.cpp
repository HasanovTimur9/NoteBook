#include "Note.h"
#include <Windows.h>


Note::Note(std::string name, std::string text, std::string author, Time creationTime, Time editTime, std::vector<std::string> Tags):
	name(name), text(text), author(author), creationTime(creationTime), editTime(editTime), Tags(Tags) 
{

}

Note::~Note() {
	
}

void Note::EditNote
(std::string name, std::string text, std::string author, Time editTime, std::vector<std::string> Tags) {
    SetName(name);
    SetText(text);
    SetAuthor(author);
    SetEditTime(editTime);
    SetTags(Tags);
}


std::string Note::getType() const {
	return "Note";
}
std::string Note::getName() const {
	return this->name;
}
std::string Note::getText() const {
	return this->text;
}
std::string Note::getAuthor() const {
	return this->author;
}
Time Note::getCreationTime() const {
	return this->creationTime;
}
Time Note::getEditTime() const {
	return this->editTime;
}
std::vector<std::string> Note::getTags() const {
	return this->Tags;
}

void Note::SetName(const std::string& name) { this->name = name; }
void Note::SetText(const std::string& text) { this->text = text; }
void Note::SetAuthor(const std::string& author) { this->author = author; }
void Note::SetEditTime(const Time& editTime) { this->editTime = editTime; }
void Note::SetTags(const std::vector<std::string>& tags) { this->Tags = tags; }

std::string Note::ConvertToUTF8(const std::string& input) {

    int size = MultiByteToWideChar(1251, 0, input.c_str(), -1, nullptr, 0);
    std::wstring wstr(size, 0);
    MultiByteToWideChar(1251, 0, input.c_str(), -1, &wstr[0], size);

    size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string utf8str(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &utf8str[0], size, nullptr, nullptr);

    return utf8str;
}

std::string Note::ConvertFromUTF8(const std::string& input) {

    int size = MultiByteToWideChar(CP_UTF8, 0, input.c_str(), -1, nullptr, 0);
    std::wstring wstr(size, 0);
    MultiByteToWideChar(CP_UTF8, 0, input.c_str(), -1, &wstr[0], size);

    size = WideCharToMultiByte(1251, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string result(size, 0);
    WideCharToMultiByte(1251, 0, wstr.c_str(), -1, &result[0], size, nullptr, nullptr);

    return result;
}

nlohmann::json Note::toJson() {
	nlohmann::json j{};
	j["type"] = "Note";
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

	return j;
}
Note::Note(const nlohmann::json& j) {
    if (!j.contains("name")) {
        throw std::runtime_error("Отсутствует поле 'name'");
    }
    name = ConvertFromUTF8(j["name"]);

    if (!j.contains("text")) {
        throw std::runtime_error("Отсутствует поле 'text'");
    }
    text = ConvertFromUTF8(j["text"]);

    if (!j.contains("author")) {
        throw std::runtime_error("Отсутствует поле 'author'");
    }
    author = ConvertFromUTF8(j["author"]);

    if (!j.contains("cTime")) {
        throw std::runtime_error("Отсутствует поле 'cTime'");
    }
    creationTime = Time(j["cTime"]);

    if (!j.contains("eTime")) {
        throw std::runtime_error("Отсутствует поле 'eTime'");
    }
    editTime = Time(j["eTime"]);

    if (!j.contains("Tags") ) {
        throw std::runtime_error("Отсутствует поле 'Tags'");
    }

    Tags.clear();
    for (const auto& tag : j["Tags"]) {
        Tags.push_back(ConvertFromUTF8(tag));
    }

}
