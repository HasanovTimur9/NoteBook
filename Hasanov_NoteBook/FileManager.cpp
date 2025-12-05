#include "FileManager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager() {
}

FileManager::~FileManager() {
}

void FileManager::DownloadFromFiles(std::vector<std::unique_ptr<Note>>& memory) {
   
    memory.clear();

    std::string files[] = { "Notes.json", "Tasks.json", "Meetings.json" };

    for (const auto& file : files) {
        std::ifstream inputFile(file);
        if (!inputFile.is_open()) {
            std::cerr << "Ошибка открытия файла: " << file << std::endl;
            continue;
        }

        nlohmann::json jsonData;
        try {
            inputFile >> jsonData;  
        }
        catch (const nlohmann::json::parse_error& e) {
            std::cerr << "Ошибка парсинга JSON в файле " << file << ": " << e.what() << std::endl;
            inputFile.close();
            continue;
        }

        for (const auto& item : jsonData) {
            auto note = createNoteFromJson(item);
            if (note) {
                memory.push_back(std::move(note));
            }
        }

        inputFile.close();
    }
}


void FileManager::UploadInFiles(const std::vector<std::unique_ptr<Note>>& memory) {
    
    std::ofstream notesFile("Notes.json", std::ios::trunc);
    std::ofstream tasksFile("Tasks.json", std::ios::trunc);
    std::ofstream meetingsFile("Meetings.json", std::ios::trunc);

    notesFile.close();
    tasksFile.close();
    meetingsFile.close();

    nlohmann::json notesJson = nlohmann::json::array();
    nlohmann::json tasksJson = nlohmann::json::array();
    nlohmann::json meetingsJson = nlohmann::json::array();

    for (const auto& note : memory) {
        if (note->getType() == "Note") {
            notesJson.push_back(note->toJson());
        }
        else if (note->getType() == "Task") {
            tasksJson.push_back(note->toJson());
        }
        else if (note->getType() == "Meeting") {
            meetingsJson.push_back(note->toJson());
        }
    }

    std::ofstream outputFile;

    outputFile.open("Notes.json");
    if (outputFile.is_open()) {
        outputFile << notesJson.dump(4); 
        outputFile.close();
    }
    else {
        std::cerr << "Ошибка открытия файла Notes.json для записи." << std::endl;
    }

    outputFile.open("Tasks.json");
    if (outputFile.is_open()) {
        outputFile << tasksJson.dump(4);
        outputFile.close();
    }
    else {
        std::cerr << "Ошибка открытия файла Tasks.json для записи." << std::endl;
    }

    outputFile.open("Meetings.json");
    if (outputFile.is_open()) {
        outputFile << meetingsJson.dump(4);
        outputFile.close();
    }
    else {
        std::cerr << "Ошибка открытия файла Meetings.json для записи." << std::endl;
    }
}

std::unique_ptr<Note> FileManager::createNoteFromJson(const nlohmann::json& j) {

    std::string type = j.value("type", "");  

    if (type == "Note") {
        return std::make_unique<Note>(j);
    }
    else if (type == "Task") {
        return std::make_unique<Task>(j);
    }
    else if (type == "Meeting") {
        return std::make_unique<Meeting>(j);
    }
    else {
        std::cerr << "Неизвестный тип объекта: " << type << std::endl;
        return nullptr;
    }
}