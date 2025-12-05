#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include "Menu_Form.h"
#include "Task.h"
#include "Meeting.h"
#include "Worker.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Russian");

	Worker worker;
	worker.LoadNotesFromFile();
	
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	HasanovNoteBook::Menu_Form form(worker);
	Application::Run(% form);

	worker.SaveNotesToFile();
	return 0;
}