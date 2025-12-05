#pragma once
#include <msclr/marshal_cppstd.h>
#include "Task.h"
#include "Meeting.h"
#include "FileManager.h"


class Worker {
private:

	FileManager fileManager;
	std::vector<std::unique_ptr<Note>> memory;

public:

	void LoadNotesFromFile();
	void SaveNotesToFile();

	System::String^ StdStringToSystemString(const std::string& input);
	std::string SystemStringToStdString(System::String^ input);

	std::string trim(const std::string str);
	std::string removeNonPrintable(const std::string& str);
	std::vector<std::string> ParseTags(std::string strTags);

	Time ConvertToTime(System::DateTime dateTime);
	System::DateTime ConvertToDateTime(Time time);

	void NewNote
	(std::string name, std::string text, std::string author, std::string Tags);
	void NewTask
	(std::string name, std::string text, std::string author, std::string Tags, System::DateTime deadline, bool done);
	void NewMeeting
	(std::string name, std::string text, std::string author, std::string Tags, System::DateTime meetingTime, std::string place);
	std::string SendType(int index);
	int SendLenth();
	void SendNote(int index, std::string& name, std::string& text, std::string& author,
		System::DateTime& creationTime, System::DateTime& editTime, std::string& Tags);
	void SendTask(int index, std::string& name, std::string& text, std::string& author,
		System::DateTime& creationTime, System::DateTime& editTime, std::string& Tags, System::DateTime& deadline, bool& done);
	void SendMeeting(int index, std::string& name, std::string& text, std::string& author,
		System::DateTime& creationTime, System::DateTime& editTime, std::string& Tags, System::DateTime& meetingTime, std::string& place);
	void ReturnNote
	(int index, std::string name, std::string text, std::string author, std::string Tags);
	void ReturnTask
	(int index, std::string name, std::string text, std::string author, std::string Tags, System::DateTime deadline, bool done);
	void ReturnMeeting
	(int index, std::string name, std::string text, std::string author, std::string Tags, System::DateTime meetingTime, std::string place);

	void GetStat(System::Collections::Generic::Dictionary<System::String^, int>^ authorStats,
		System::Collections::Generic::Dictionary<System::String^, int>^ tagStats);

	void DeleteNote(int index);

	void Search(const std::string query, bool searchInAuthors, bool searchInTags, bool searchInNames, int& matchCount);

	void SortNotesByCreationTime();
	void SortNotesByEditTime();
	void SortNotesByNames();
	void SortNotesByAuthors();
};