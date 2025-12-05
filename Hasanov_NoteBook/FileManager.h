#include <vector>
#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "Task.h" 
#include "Meeting.h"  

class FileManager {
public:
    
    FileManager();
    ~FileManager();

    void DownloadFromFiles(std::vector<std::unique_ptr<Note>>& memory);

    void UploadInFiles(const std::vector<std::unique_ptr<Note>>& memory);

private:

    std::unique_ptr<Note> createNoteFromJson(const nlohmann::json& j);
};