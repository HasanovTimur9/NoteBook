#include "Worker.h"


void Worker::LoadNotesFromFile() {
    fileManager.DownloadFromFiles(memory);
}

void Worker::SaveNotesToFile() {
    fileManager.UploadInFiles(memory);
}

std::string Worker::trim(const std::string str) {

    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }

    return str.substr(start, end - start + 1);
}

std::string Worker::removeNonPrintable(const std::string& str) {

    std::string result;
    for (char ch : str) {
        if (std::isprint(static_cast<unsigned char>(ch))) {
            result += ch;
        }
    }
    return result;

}

System::String^ Worker::StdStringToSystemString(const std::string& input) {
	return msclr::interop::marshal_as<System::String^>(input);
}

std::string Worker::SystemStringToStdString(System::String^ input) {
	return trim(msclr::interop::marshal_as<std::string>(input));
}

Time Worker::ConvertToTime(System::DateTime dateTime) {
    return Time(dateTime.Year, dateTime.Month, dateTime.Day, dateTime.Hour, dateTime.Minute);
}

std::string JoinWithCommas(const std::vector<std::string>& Tags) {
    std::ostringstream TagsString;
    for (size_t i = 0; i < Tags.size(); ++i) {
        TagsString << Tags[i];
        if (i != Tags.size() - 1) {
            TagsString << ", ";
        }
    }
    return TagsString.str();
}

System::DateTime Worker::ConvertToDateTime(Time time) {
    int year = time.getYear();
    int month = time.getMonth();
    int day = time.getDay();
    int hour = time.getHour();
    int minute = time.getMinute();

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31 ||
        hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        throw std::invalid_argument("Неверный формат даты");
    }
   
    return System::DateTime(year, month, day, hour, minute, 0);
}

void Worker::DeleteNote(int index) {
    if (index >= 0 && index < memory.size()) {
        memory.erase(memory.begin() + index);
    }
}

std::vector<std::string> Worker::ParseTags(std::string strTags) {
    std::vector<std::string> Tags;
    std::istringstream stream(strTags);
    std::string token;

    while (std::getline(stream, token, ',')) {
        Tags.push_back(token);
    }

    for (int i = 0; i < Tags.size(); i++) {
        Tags[i] = trim(Tags[i]);
    }

    return Tags;
}

void Worker::NewNote(std::string name, std::string text, std::string author, std::string strTags) {

    std::vector<std::string> Tags = ParseTags(strTags);
    Time currentTime = Time();

    memory.push_back(std::make_unique<Note>(name, text, author, currentTime, currentTime, Tags));
}

void Worker::NewTask(std::string name, std::string text, std::string author, std::string strTags,
    System::DateTime deadline, bool done) {

    std::vector<std::string> Tags = ParseTags(strTags);
    Time currentTime = Time();
    Time pushingDeadLine = ConvertToTime(deadline);
    memory.push_back(std::make_unique<Task>(name, text, author, currentTime, currentTime, Tags, pushingDeadLine, done));
}

void Worker::NewMeeting(std::string name, std::string text, std::string author, std::string strTags,
    System::DateTime meetingTime, std::string place) {

    std::vector<std::string> Tags = ParseTags(strTags);
    Time currentTime = Time();
    Time pushingMeetTime = ConvertToTime(meetingTime);
    memory.push_back(std::make_unique<Meeting>(name, text, author, currentTime, currentTime, Tags, pushingMeetTime, place));
}


std::string Worker::SendType(int index) {

    return memory[index]->getType();
    
}

int Worker::SendLenth() {
        return memory.size();
}

void Worker::SendNote(int index, std::string& name, std::string& text, std::string& author,
        System::DateTime& creationTime, System::DateTime& editTime, std::string& Tags) {
        name = memory[index]->getName();
        text = memory[index]->getText();
        author = memory[index]->getAuthor();
        creationTime = ConvertToDateTime(memory[index]->getCreationTime());
        editTime = ConvertToDateTime(memory[index]->getEditTime());
        Tags = JoinWithCommas(memory[index]->getTags());
}

void Worker::SendTask(int index, std::string& name, std::string& text, std::string& author,
    System::DateTime& creationTime, System::DateTime& editTime, std::string& Tags, System::DateTime& deadline, bool& done) {
        auto task = dynamic_cast<Task*>(memory[index].get());
        if (task) {
            name = task->getName();
            text = task->getText();
            author = task->getAuthor();
            creationTime = ConvertToDateTime(task->getCreationTime());
            editTime = ConvertToDateTime(task->getEditTime());
            Tags = JoinWithCommas(task->getTags());
            deadline = ConvertToDateTime(task->getDeadline());
            done = task->getDone();
        }
        else {
            throw std::invalid_argument("Объект не является экземпляром класса Task");
        }
}

void Worker::SendMeeting(int index, std::string& name, std::string& text, std::string& author,
    System::DateTime& creationTime, System::DateTime& editTime, std::string& Tags, System::DateTime& meetingTime, std::string& place) {
    auto meeting = dynamic_cast<Meeting*>(memory[index].get());
    if (meeting) {
        name = meeting->getName();
        text = meeting->getText();
        author = meeting->getAuthor();
        creationTime = ConvertToDateTime(meeting->getCreationTime());
        editTime = ConvertToDateTime(meeting->getEditTime());
        Tags = JoinWithCommas(meeting->getTags());
        meetingTime = ConvertToDateTime(meeting->getMeetingTime());
        place = meeting->getPlace();
    }
    else {
        throw std::invalid_argument("Объект не является экземпляром класса Meeting");
    }
}

void Worker::ReturnNote
(int index, std::string name, std::string text, std::string author, std::string strTags) {

    std::vector<std::string> Tags = ParseTags(strTags);
    Time currentTime = Time();

    memory[index]->EditNote(name, text, author, currentTime, Tags);
}

void Worker::ReturnTask
(int index, std::string name, std::string text, std::string author, std::string strTags,
    System::DateTime deadline, bool done) {

    std::vector<std::string> Tags = ParseTags(strTags);
    Time currentTime = Time();
    Time pushingTime = ConvertToTime(deadline);

    auto task = dynamic_cast<Task*>(memory[index].get());
    if (task) {
        task->EditTask(name, text, author, currentTime, Tags, pushingTime, done);
    }
    else {
        throw std::invalid_argument("Объект не является экземпляром класса Task");
    }
 
}

void Worker::ReturnMeeting
(int index, std::string name, std::string text, std::string author, std::string strTags,
    System::DateTime meetingTime, std::string place) {

    std::vector<std::string> Tags = ParseTags(strTags);
    Time currentTime = Time();
    Time pushingTime = ConvertToTime(meetingTime);

    auto meeting = dynamic_cast<Meeting*>(memory[index].get());
    if (meeting) {
        meeting->EditMeeting(name, text, author, currentTime, Tags, pushingTime, place);
    }
    else {
        throw std::invalid_argument("Объект не является экземпляром класса Meeting");
    }
}

void Worker::SortNotesByCreationTime() {
	std::sort(memory.begin(), memory.end(), [](const std::unique_ptr<Note>& a, const std::unique_ptr<Note>& b) {
		return !a->getCreationTime().IsEarlierThan(b->getCreationTime());
		});
}

void Worker::SortNotesByEditTime() {
	std::sort(memory.begin(), memory.end(), [](const std::unique_ptr<Note>& a, const std::unique_ptr<Note>& b) {
		return !a->getEditTime().IsEarlierThan(b->getEditTime());
		});
}

void Worker::SortNotesByNames() {
    std::sort(memory.begin(), memory.end(), [](const std::unique_ptr<Note>& a, const std::unique_ptr<Note>& b) {
        return a->getName() < b->getName(); 
        });
}

void Worker::SortNotesByAuthors() {
    std::sort(memory.begin(), memory.end(), [](const std::unique_ptr<Note>& a, const std::unique_ptr<Note>& b) {
        return a->getAuthor() < b->getAuthor();
        });
}

void Worker::GetStat(System::Collections::Generic::Dictionary<System::String^, int>^ authorStats,
    System::Collections::Generic::Dictionary<System::String^, int>^ tagStats) {

    authorStats->Clear();
    tagStats->Clear();

    for (const auto& note : memory) {
      
        std::string author = removeNonPrintable(note->getAuthor());
        System::String^ authorStr = StdStringToSystemString(author);

        if (!authorStats->ContainsKey(authorStr)) {
            authorStats[authorStr] = 0;
        }
        authorStats[authorStr]++;

        for (const auto& tag : note->getTags()) {
          
            std::string tagCleaned = removeNonPrintable(tag);
            System::String^ tagStr = StdStringToSystemString(tagCleaned);

            if (!tagStats->ContainsKey(tagStr)) {
                tagStats[tagStr] = 0;
            }
            tagStats[tagStr]++;
        }
    }
}

void Worker::Search(const std::string query, bool searchInAuthors, bool searchInTags, bool searchInNames, int& matchCount) {

    matchCount = 0;

    auto hasMatch = [&](const std::unique_ptr<Note>& note) -> bool {
        if (note->getText().find(query) != std::string::npos) {
            return true;
        }
        if (searchInAuthors && note->getAuthor().find(query) != std::string::npos) {
            return true;
        }
        if (searchInNames && note->getName().find(query) != std::string::npos) {
            return true;
        }
        if (searchInTags) {
            for (const auto& tag : note->getTags()) {
                if (tag.find(query) != std::string::npos) {
                    return true;
                }
            }
        }
        return false;
        };

    for (const auto& note : memory) {
        if (hasMatch(note)) {
            matchCount++;
        }
    }

    std::sort(memory.begin(), memory.end(), [&](const std::unique_ptr<Note>& a, const std::unique_ptr<Note>& b) {
        bool aMatch = hasMatch(a);
        bool bMatch = hasMatch(b);

        
        return aMatch && !bMatch;
        });
}