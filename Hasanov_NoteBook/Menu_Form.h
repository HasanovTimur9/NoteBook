#pragma once
#include <msclr/marshal_cppstd.h> 
#include "Task.h"
#include "Meeting.h"
#include "Worker.h"
#include "Editing_Form.h"
#include "Stat_Form.h"

namespace HasanovNoteBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Menu_Form
	/// </summary>
	public ref class Menu_Form : public System::Windows::Forms::Form
	{
	private:
		Worker& worker;
		int currentIndex;
		int capacity;
		Dictionary<String^, int>^ authorStats = gcnew Dictionary<String^, int>();
		Dictionary<String^, int>^ tagStats = gcnew Dictionary<String^, int>();
	
	private: System::Windows::Forms::Button^ Stat_btn;
	private: System::Windows::Forms::RadioButton^ NameSort_rbtn;
	private: System::Windows::Forms::RadioButton^ AuthorSort_ebtn;
	private: System::Windows::Forms::Button^ Sort_btn;

	public:

		Menu_Form(Worker& worker) : worker(worker) {
			InitializeComponent();
			
			LoadNotesToScreen();
		}

	protected:

		~Menu_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ Name1;
	private: System::Windows::Forms::Label^ Creation_Date1;
	private: System::Windows::Forms::Label^ Author1;
	private: System::Windows::Forms::Label^ Edit_Date1;
	private: System::Windows::Forms::Label^ EDate_const1;
	private: System::Windows::Forms::Label^ CDate_const1;
	private: System::Windows::Forms::Label^ Author_const1;
	private: System::Windows::Forms::Button^ Down_btn;
	private: System::Windows::Forms::Label^ text1;
	private: System::Windows::Forms::Label^ Tags_const1;
	private: System::Windows::Forms::Label^ Tags1;
	private: System::Windows::Forms::Button^ NewNote_btn;
	private: System::Windows::Forms::Button^ Up_btn;
	private: System::Windows::Forms::TextBox^ Search;
	private: System::Windows::Forms::CheckBox^ AuthorSearch_chbox;
	private: System::Windows::Forms::CheckBox^ TagsSearch_chbox;
	private: System::Windows::Forms::CheckBox^ NameSearch_chbox;
	private: System::Windows::Forms::RadioButton^ CreationSort_rbtn;
	private: System::Windows::Forms::RadioButton^ EditSort_rbtn;
	private: System::Windows::Forms::Label^ const_Time_DeadLine_1;
	private: System::Windows::Forms::Label^ Name2;
	private: System::Windows::Forms::Label^ Creation_Date2;
	private: System::Windows::Forms::Label^ Edit_Date2;
	private: System::Windows::Forms::Label^ Author2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ Text2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ Tags2;
	private: System::Windows::Forms::Label^ const_Time_Deadline2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ Name3;
	private: System::Windows::Forms::Label^ Creation_Date3;
	private: System::Windows::Forms::Label^ Edit_Date3;
	private: System::Windows::Forms::Label^ Author3;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ Text3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ Tags3;
	private: System::Windows::Forms::Label^ const_Time_Deadline3;
	private: System::Windows::Forms::Panel^ panel3;

	private:
		System::ComponentModel::Container^ components;
		#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Menu_Form::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->const_Time_DeadLine_1 = (gcnew System::Windows::Forms::Label());
			this->Tags1 = (gcnew System::Windows::Forms::Label());
			this->Tags_const1 = (gcnew System::Windows::Forms::Label());
			this->text1 = (gcnew System::Windows::Forms::Label());
			this->Author_const1 = (gcnew System::Windows::Forms::Label());
			this->EDate_const1 = (gcnew System::Windows::Forms::Label());
			this->CDate_const1 = (gcnew System::Windows::Forms::Label());
			this->Author1 = (gcnew System::Windows::Forms::Label());
			this->Edit_Date1 = (gcnew System::Windows::Forms::Label());
			this->Creation_Date1 = (gcnew System::Windows::Forms::Label());
			this->Name1 = (gcnew System::Windows::Forms::Label());
			this->Down_btn = (gcnew System::Windows::Forms::Button());
			this->NewNote_btn = (gcnew System::Windows::Forms::Button());
			this->Up_btn = (gcnew System::Windows::Forms::Button());
			this->Search = (gcnew System::Windows::Forms::TextBox());
			this->AuthorSearch_chbox = (gcnew System::Windows::Forms::CheckBox());
			this->TagsSearch_chbox = (gcnew System::Windows::Forms::CheckBox());
			this->NameSearch_chbox = (gcnew System::Windows::Forms::CheckBox());
			this->CreationSort_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->EditSort_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->Name2 = (gcnew System::Windows::Forms::Label());
			this->Creation_Date2 = (gcnew System::Windows::Forms::Label());
			this->Edit_Date2 = (gcnew System::Windows::Forms::Label());
			this->Author2 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Text2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Tags2 = (gcnew System::Windows::Forms::Label());
			this->const_Time_Deadline2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Name3 = (gcnew System::Windows::Forms::Label());
			this->Creation_Date3 = (gcnew System::Windows::Forms::Label());
			this->Edit_Date3 = (gcnew System::Windows::Forms::Label());
			this->Author3 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Text3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Tags3 = (gcnew System::Windows::Forms::Label());
			this->const_Time_Deadline3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->NameSort_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->AuthorSort_ebtn = (gcnew System::Windows::Forms::RadioButton());
			this->Sort_btn = (gcnew System::Windows::Forms::Button());
			this->Stat_btn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->CausesValidation = false;
			this->panel1->Controls->Add(this->const_Time_DeadLine_1);
			this->panel1->Controls->Add(this->Tags1);
			this->panel1->Controls->Add(this->Tags_const1);
			this->panel1->Controls->Add(this->text1);
			this->panel1->Controls->Add(this->Author_const1);
			this->panel1->Controls->Add(this->EDate_const1);
			this->panel1->Controls->Add(this->CDate_const1);
			this->panel1->Controls->Add(this->Author1);
			this->panel1->Controls->Add(this->Edit_Date1);
			this->panel1->Controls->Add(this->Creation_Date1);
			this->panel1->Controls->Add(this->Name1);
			this->panel1->ForeColor = System::Drawing::Color::Black;
			this->panel1->Location = System::Drawing::Point(9, 142);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(952, 270);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &Menu_Form::panel1_Click);
			// 
			// const_Time_DeadLine_1
			// 
			this->const_Time_DeadLine_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->const_Time_DeadLine_1->Location = System::Drawing::Point(-4, 45);
			this->const_Time_DeadLine_1->Name = L"const_Time_DeadLine_1";
			this->const_Time_DeadLine_1->Size = System::Drawing::Size(933, 31);
			this->const_Time_DeadLine_1->TabIndex = 11;
			this->const_Time_DeadLine_1->Text = L"Время встречи/Дедлайн:";
			// 
			// Tags1
			// 
			this->Tags1->Location = System::Drawing::Point(294, 232);
			this->Tags1->Name = L"Tags1";
			this->Tags1->Size = System::Drawing::Size(506, 25);
			this->Tags1->TabIndex = 9;
			this->Tags1->Text = L"Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1";
			// 
			// Tags_const1
			// 
			this->Tags_const1->AutoSize = true;
			this->Tags_const1->Location = System::Drawing::Point(294, 207);
			this->Tags_const1->Name = L"Tags_const1";
			this->Tags_const1->Size = System::Drawing::Size(62, 25);
			this->Tags_const1->TabIndex = 8;
			this->Tags_const1->Text = L"Тэги:";
			// 
			// text1
			// 
			this->text1->Location = System::Drawing::Point(5, 100);
			this->text1->Name = L"text1";
			this->text1->Size = System::Drawing::Size(946, 107);
			this->text1->TabIndex = 7;
			this->text1->Text = resources->GetString(L"text1.Text");
			// 
			// Author_const1
			// 
			this->Author_const1->AutoSize = true;
			this->Author_const1->Location = System::Drawing::Point(799, 207);
			this->Author_const1->Name = L"Author_const1";
			this->Author_const1->Size = System::Drawing::Size(77, 25);
			this->Author_const1->TabIndex = 6;
			this->Author_const1->Text = L"Автор:";
			// 
			// EDate_const1
			// 
			this->EDate_const1->AutoSize = true;
			this->EDate_const1->Location = System::Drawing::Point(160, 207);
			this->EDate_const1->Name = L"EDate_const1";
			this->EDate_const1->Size = System::Drawing::Size(119, 25);
			this->EDate_const1->TabIndex = 5;
			this->EDate_const1->Text = L"Изменено:";
			// 
			// CDate_const1
			// 
			this->CDate_const1->AutoSize = true;
			this->CDate_const1->Location = System::Drawing::Point(3, 207);
			this->CDate_const1->Name = L"CDate_const1";
			this->CDate_const1->Size = System::Drawing::Size(104, 25);
			this->CDate_const1->TabIndex = 4;
			this->CDate_const1->Text = L"Создано:";
			// 
			// Author1
			// 
			this->Author1->Location = System::Drawing::Point(799, 232);
			this->Author1->Name = L"Author1";
			this->Author1->Size = System::Drawing::Size(149, 25);
			this->Author1->TabIndex = 3;
			this->Author1->Text = L"Author1";
			// 
			// Edit_Date1
			// 
			this->Edit_Date1->AutoSize = true;
			this->Edit_Date1->Location = System::Drawing::Point(161, 232);
			this->Edit_Date1->Name = L"Edit_Date1";
			this->Edit_Date1->Size = System::Drawing::Size(118, 25);
			this->Edit_Date1->TabIndex = 2;
			this->Edit_Date1->Text = L"Edit_Date1";
			// 
			// Creation_Date1
			// 
			this->Creation_Date1->AutoSize = true;
			this->Creation_Date1->Location = System::Drawing::Point(3, 232);
			this->Creation_Date1->Name = L"Creation_Date1";
			this->Creation_Date1->Size = System::Drawing::Size(158, 25);
			this->Creation_Date1->TabIndex = 1;
			this->Creation_Date1->Text = L"creation_Date1";
			// 
			// Name1
			// 
			this->Name1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name1->Location = System::Drawing::Point(-4, 4);
			this->Name1->Name = L"Name1";
			this->Name1->Size = System::Drawing::Size(845, 41);
			this->Name1->TabIndex = 0;
			this->Name1->Text = L"Name1";
			// 
			// Down_btn
			// 
			this->Down_btn->Location = System::Drawing::Point(9, 970);
			this->Down_btn->Name = L"Down_btn";
			this->Down_btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->Down_btn->Size = System::Drawing::Size(428, 60);
			this->Down_btn->TabIndex = 3;
			this->Down_btn->Text = L"Вниз";
			this->Down_btn->UseVisualStyleBackColor = true;
			this->Down_btn->Click += gcnew System::EventHandler(this, &Menu_Form::Down_btn_Click);
			// 
			// NewNote_btn
			// 
			this->NewNote_btn->Location = System::Drawing::Point(877, 970);
			this->NewNote_btn->Name = L"NewNote_btn";
			this->NewNote_btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->NewNote_btn->Size = System::Drawing::Size(87, 60);
			this->NewNote_btn->TabIndex = 9;
			this->NewNote_btn->Text = L"+";
			this->NewNote_btn->UseVisualStyleBackColor = true;
			this->NewNote_btn->Click += gcnew System::EventHandler(this, &Menu_Form::NewNote_btn_Click);
			// 
			// Up_btn
			// 
			this->Up_btn->Location = System::Drawing::Point(443, 970);
			this->Up_btn->Name = L"Up_btn";
			this->Up_btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->Up_btn->Size = System::Drawing::Size(428, 60);
			this->Up_btn->TabIndex = 11;
			this->Up_btn->Text = L"Вверх";
			this->Up_btn->UseVisualStyleBackColor = true;
			this->Up_btn->Click += gcnew System::EventHandler(this, &Menu_Form::Up_btn_Click);
			// 
			// Search
			// 
			this->Search->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->Search->Location = System::Drawing::Point(9, 12);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(357, 31);
			this->Search->TabIndex = 12;
			this->Search->Text = L"Поиск";
			this->Search->Enter += gcnew System::EventHandler(this, &Menu_Form::Search_Enter);
			this->Search->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Menu_Form::Search_KeyPress);
			this->Search->Leave += gcnew System::EventHandler(this, &Menu_Form::Search_Leave);
			// 
			// AuthorSearch_chbox
			// 
			this->AuthorSearch_chbox->AutoSize = true;
			this->AuthorSearch_chbox->Location = System::Drawing::Point(263, 58);
			this->AuthorSearch_chbox->Name = L"AuthorSearch_chbox";
			this->AuthorSearch_chbox->Size = System::Drawing::Size(103, 29);
			this->AuthorSearch_chbox->TabIndex = 13;
			this->AuthorSearch_chbox->Text = L"Автор";
			this->AuthorSearch_chbox->UseVisualStyleBackColor = true;
			// 
			// TagsSearch_chbox
			// 
			this->TagsSearch_chbox->AutoSize = true;
			this->TagsSearch_chbox->Location = System::Drawing::Point(165, 58);
			this->TagsSearch_chbox->Name = L"TagsSearch_chbox";
			this->TagsSearch_chbox->Size = System::Drawing::Size(88, 29);
			this->TagsSearch_chbox->TabIndex = 14;
			this->TagsSearch_chbox->Text = L"Тэги";
			this->TagsSearch_chbox->UseVisualStyleBackColor = true;
			// 
			// NameSearch_chbox
			// 
			this->NameSearch_chbox->AutoSize = true;
			this->NameSearch_chbox->Location = System::Drawing::Point(9, 58);
			this->NameSearch_chbox->Name = L"NameSearch_chbox";
			this->NameSearch_chbox->Size = System::Drawing::Size(141, 29);
			this->NameSearch_chbox->TabIndex = 15;
			this->NameSearch_chbox->Text = L"Название";
			this->NameSearch_chbox->UseVisualStyleBackColor = true;
			// 
			// CreationSort_rbtn
			// 
			this->CreationSort_rbtn->AutoSize = true;
			this->CreationSort_rbtn->Location = System::Drawing::Point(672, 14);
			this->CreationSort_rbtn->Name = L"CreationSort_rbtn";
			this->CreationSort_rbtn->Size = System::Drawing::Size(129, 29);
			this->CreationSort_rbtn->TabIndex = 17;
			this->CreationSort_rbtn->Text = L"Создано";
			this->CreationSort_rbtn->UseVisualStyleBackColor = true;
			// 
			// EditSort_rbtn
			// 
			this->EditSort_rbtn->AutoSize = true;
			this->EditSort_rbtn->Checked = true;
			this->EditSort_rbtn->Location = System::Drawing::Point(672, 58);
			this->EditSort_rbtn->Name = L"EditSort_rbtn";
			this->EditSort_rbtn->Size = System::Drawing::Size(144, 29);
			this->EditSort_rbtn->TabIndex = 18;
			this->EditSort_rbtn->TabStop = true;
			this->EditSort_rbtn->Text = L"Изменено";
			this->EditSort_rbtn->UseVisualStyleBackColor = true;
			// 
			// Name2
			// 
			this->Name2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name2->Location = System::Drawing::Point(-4, 4);
			this->Name2->Name = L"Name2";
			this->Name2->Size = System::Drawing::Size(845, 41);
			this->Name2->TabIndex = 0;
			this->Name2->Text = L"label11";
			// 
			// Creation_Date2
			// 
			this->Creation_Date2->AutoSize = true;
			this->Creation_Date2->Location = System::Drawing::Point(3, 232);
			this->Creation_Date2->Name = L"Creation_Date2";
			this->Creation_Date2->Size = System::Drawing::Size(158, 25);
			this->Creation_Date2->TabIndex = 1;
			this->Creation_Date2->Text = L"creation_Date1";
			// 
			// Edit_Date2
			// 
			this->Edit_Date2->AutoSize = true;
			this->Edit_Date2->Location = System::Drawing::Point(161, 232);
			this->Edit_Date2->Name = L"Edit_Date2";
			this->Edit_Date2->Size = System::Drawing::Size(70, 25);
			this->Edit_Date2->TabIndex = 2;
			this->Edit_Date2->Text = L"label9";
			// 
			// Author2
			// 
			this->Author2->Location = System::Drawing::Point(799, 232);
			this->Author2->Name = L"Author2";
			this->Author2->Size = System::Drawing::Size(149, 25);
			this->Author2->TabIndex = 3;
			this->Author2->Text = L"label8";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 207);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(104, 25);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Создано:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(160, 207);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Изменено:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(799, 207);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 25);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Автор:";
			// 
			// Text2
			// 
			this->Text2->Location = System::Drawing::Point(5, 100);
			this->Text2->Name = L"Text2";
			this->Text2->Size = System::Drawing::Size(946, 107);
			this->Text2->TabIndex = 7;
			this->Text2->Text = resources->GetString(L"Text2.Text");
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(294, 207);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Тэги:";
			// 
			// Tags2
			// 
			this->Tags2->Location = System::Drawing::Point(294, 232);
			this->Tags2->Name = L"Tags2";
			this->Tags2->Size = System::Drawing::Size(506, 25);
			this->Tags2->TabIndex = 9;
			this->Tags2->Text = L"Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1";
			// 
			// const_Time_Deadline2
			// 
			this->const_Time_Deadline2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->const_Time_Deadline2->Location = System::Drawing::Point(-4, 45);
			this->const_Time_Deadline2->Name = L"const_Time_Deadline2";
			this->const_Time_Deadline2->Size = System::Drawing::Size(933, 31);
			this->const_Time_Deadline2->TabIndex = 11;
			this->const_Time_Deadline2->Text = L"Время встречи/Дедлайн:";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->CausesValidation = false;
			this->panel2->Controls->Add(this->const_Time_Deadline2);
			this->panel2->Controls->Add(this->Tags2);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->Text2);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->Author2);
			this->panel2->Controls->Add(this->Edit_Date2);
			this->panel2->Controls->Add(this->Creation_Date2);
			this->panel2->Controls->Add(this->Name2);
			this->panel2->ForeColor = System::Drawing::Color::Black;
			this->panel2->Location = System::Drawing::Point(9, 418);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(952, 270);
			this->panel2->TabIndex = 23;
			this->panel2->Click += gcnew System::EventHandler(this, &Menu_Form::panel2_Click);
			// 
			// Name3
			// 
			this->Name3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name3->Location = System::Drawing::Point(-4, 4);
			this->Name3->Name = L"Name3";
			this->Name3->Size = System::Drawing::Size(845, 41);
			this->Name3->TabIndex = 0;
			this->Name3->Text = L"label15";
			// 
			// Creation_Date3
			// 
			this->Creation_Date3->AutoSize = true;
			this->Creation_Date3->Location = System::Drawing::Point(3, 232);
			this->Creation_Date3->Name = L"Creation_Date3";
			this->Creation_Date3->Size = System::Drawing::Size(158, 25);
			this->Creation_Date3->TabIndex = 1;
			this->Creation_Date3->Text = L"creation_Date1";
			// 
			// Edit_Date3
			// 
			this->Edit_Date3->AutoSize = true;
			this->Edit_Date3->Location = System::Drawing::Point(161, 232);
			this->Edit_Date3->Name = L"Edit_Date3";
			this->Edit_Date3->Size = System::Drawing::Size(82, 25);
			this->Edit_Date3->TabIndex = 2;
			this->Edit_Date3->Text = L"label13";
			// 
			// Author3
			// 
			this->Author3->Location = System::Drawing::Point(799, 232);
			this->Author3->Name = L"Author3";
			this->Author3->Size = System::Drawing::Size(149, 25);
			this->Author3->TabIndex = 3;
			this->Author3->Text = L"label12";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 207);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(104, 25);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Создано:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(160, 207);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(119, 25);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Изменено:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(799, 207);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(77, 25);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Автор:";
			// 
			// Text3
			// 
			this->Text3->Location = System::Drawing::Point(5, 100);
			this->Text3->Name = L"Text3";
			this->Text3->Size = System::Drawing::Size(946, 107);
			this->Text3->TabIndex = 7;
			this->Text3->Text = resources->GetString(L"Text3.Text");
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(294, 207);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 25);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Тэги:";
			// 
			// Tags3
			// 
			this->Tags3->Location = System::Drawing::Point(294, 232);
			this->Tags3->Name = L"Tags3";
			this->Tags3->Size = System::Drawing::Size(506, 25);
			this->Tags3->TabIndex = 9;
			this->Tags3->Text = L"Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1Tags1";
			// 
			// const_Time_Deadline3
			// 
			this->const_Time_Deadline3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->const_Time_Deadline3->Location = System::Drawing::Point(-4, 45);
			this->const_Time_Deadline3->Name = L"const_Time_Deadline3";
			this->const_Time_Deadline3->Size = System::Drawing::Size(933, 31);
			this->const_Time_Deadline3->TabIndex = 11;
			this->const_Time_Deadline3->Text = L"Время встречи/Дедлайн:";
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->CausesValidation = false;
			this->panel3->Controls->Add(this->const_Time_Deadline3);
			this->panel3->Controls->Add(this->Tags3);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->Text3);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label11);
			this->panel3->Controls->Add(this->Author3);
			this->panel3->Controls->Add(this->Edit_Date3);
			this->panel3->Controls->Add(this->Creation_Date3);
			this->panel3->Controls->Add(this->Name3);
			this->panel3->ForeColor = System::Drawing::Color::Black;
			this->panel3->Location = System::Drawing::Point(9, 694);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(952, 270);
			this->panel3->TabIndex = 24;
			this->panel3->Click += gcnew System::EventHandler(this, &Menu_Form::panel3_Click);
			// 
			// NameSort_rbtn
			// 
			this->NameSort_rbtn->AutoSize = true;
			this->NameSort_rbtn->Location = System::Drawing::Point(824, 14);
			this->NameSort_rbtn->Name = L"NameSort_rbtn";
			this->NameSort_rbtn->Size = System::Drawing::Size(140, 29);
			this->NameSort_rbtn->TabIndex = 25;
			this->NameSort_rbtn->Text = L"Название";
			this->NameSort_rbtn->UseVisualStyleBackColor = true;
			// 
			// AuthorSort_ebtn
			// 
			this->AuthorSort_ebtn->AutoSize = true;
			this->AuthorSort_ebtn->Location = System::Drawing::Point(824, 57);
			this->AuthorSort_ebtn->Name = L"AuthorSort_ebtn";
			this->AuthorSort_ebtn->Size = System::Drawing::Size(102, 29);
			this->AuthorSort_ebtn->TabIndex = 26;
			this->AuthorSort_ebtn->Text = L"Автор";
			this->AuthorSort_ebtn->UseVisualStyleBackColor = true;
			// 
			// Sort_btn
			// 
			this->Sort_btn->Location = System::Drawing::Point(474, 10);
			this->Sort_btn->Name = L"Sort_btn";
			this->Sort_btn->Size = System::Drawing::Size(192, 77);
			this->Sort_btn->TabIndex = 27;
			this->Sort_btn->Text = L"Сортировать";
			this->Sort_btn->UseVisualStyleBackColor = true;
			this->Sort_btn->Click += gcnew System::EventHandler(this, &Menu_Form::Sort_btn_Click);
			// 
			// Stat_btn
			// 
			this->Stat_btn->Location = System::Drawing::Point(9, 93);
			this->Stat_btn->Name = L"Stat_btn";
			this->Stat_btn->Size = System::Drawing::Size(162, 43);
			this->Stat_btn->TabIndex = 28;
			this->Stat_btn->Text = L"Статистика";
			this->Stat_btn->UseVisualStyleBackColor = true;
			this->Stat_btn->Click += gcnew System::EventHandler(this, &Menu_Form::Stat_btn_Click);
			// 
			// Menu_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(976, 1039);
			this->Controls->Add(this->Stat_btn);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->Sort_btn);
			this->Controls->Add(this->AuthorSort_ebtn);
			this->Controls->Add(this->NameSort_rbtn);
			this->Controls->Add(this->EditSort_rbtn);
			this->Controls->Add(this->CreationSort_rbtn);
			this->Controls->Add(this->NameSearch_chbox);
			this->Controls->Add(this->TagsSearch_chbox);
			this->Controls->Add(this->AuthorSearch_chbox);
			this->Controls->Add(this->Search);
			this->Controls->Add(this->Up_btn);
			this->Controls->Add(this->NewNote_btn);
			this->Controls->Add(this->Down_btn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Menu_Form";
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
			this->Load += gcnew System::EventHandler(this, &Menu_Form::Menu_Form_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
	


	private: void LoadNotesToScreen() {
		currentIndex = 0;
		capacity = worker.SendLenth();

		for each (Control ^ control in panel1->Controls)
		{
			control->Click += gcnew EventHandler(this, &Menu_Form::panel1_Click);
		}

		for each (Control ^ control in panel2->Controls)
		{
			control->Click += gcnew EventHandler(this, &Menu_Form::panel2_Click);
		}

		for each (Control ^ control in panel3->Controls)
		{
			control->Click += gcnew EventHandler(this, &Menu_Form::panel3_Click);
		}
		UpdatePanels();
	}

	private: void UpdatePanels() {
		std::string Name;
		std::string Text;
		std::string Author;
		std::string Tags;
		System::DateTime creationDate;
		System::DateTime editDate;
		System::DateTime deadline;
		System::DateTime meetingTime;
		bool done;
		std::string place;

		if (capacity == 0) {
			panel1->Visible = false;
			panel2->Visible = false;
			panel3->Visible = false;
		}

		if (capacity - currentIndex >= 3) {
			panel1->Visible = true;
			panel2->Visible = true;
			panel3->Visible = true;
			if (worker.SendType(currentIndex) == "Note") {
				worker.SendNote(currentIndex, Name, Text, Author, creationDate, editDate, Tags);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = false;
			}

			if (worker.SendType(currentIndex) == "Task") {
				worker.SendTask(currentIndex, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = true;
				const_Time_DeadLine_1->Text = "Дедлайн: " + deadline.ToString("yyyy.MM.dd HH:mm");
			}

			if (worker.SendType(currentIndex) == "Meeting") {
				worker.SendMeeting(currentIndex, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = true;
				const_Time_DeadLine_1->Text = "Время встречи: " + meetingTime.ToString("yyyy.MM.dd HH:mm");
			}

			//========================================================================================
			if (worker.SendType(currentIndex+1) == "Note") {
				worker.SendNote(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags);
				Name2->Text = worker.StdStringToSystemString(Name);
				Text2->Text = worker.StdStringToSystemString(Text);
				Author2->Text = worker.StdStringToSystemString(Author);
				Tags2->Text = worker.StdStringToSystemString(Tags);
				Creation_Date2->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date2->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline2->Visible = false;
			}

			if (worker.SendType(currentIndex + 1) == "Task") {
				worker.SendTask(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
				Name2->Text = worker.StdStringToSystemString(Name);
				Text2->Text = worker.StdStringToSystemString(Text);
				Author2->Text = worker.StdStringToSystemString(Author);
				Tags2->Text = worker.StdStringToSystemString(Tags);
				Creation_Date2->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date2->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline2->Visible = true;
				const_Time_Deadline2->Text = "Дедлайн: " + deadline.ToString("yyyy.MM.dd HH:mm");
			}

			if (worker.SendType(currentIndex + 1) == "Meeting") {
				worker.SendMeeting(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
				Name2->Text = worker.StdStringToSystemString(Name);
				Text2->Text = worker.StdStringToSystemString(Text);
				Author2->Text = worker.StdStringToSystemString(Author);
				Tags2->Text = worker.StdStringToSystemString(Tags);
				Creation_Date2->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date2->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline2->Visible = true;
				const_Time_Deadline2->Text = "Время встречи: " + meetingTime.ToString("yyyy.MM.dd HH:mm");
			}

			//========================================================================================
			if (worker.SendType(currentIndex + 2) == "Note") {
				worker.SendNote(currentIndex + 2, Name, Text, Author, creationDate, editDate, Tags);
				Name3->Text = worker.StdStringToSystemString(Name);
				Text3->Text = worker.StdStringToSystemString(Text);
				Author3->Text = worker.StdStringToSystemString(Author);
				Tags3->Text = worker.StdStringToSystemString(Tags);
				Creation_Date3->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date3->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline3->Visible = false;
				
			}

			if (worker.SendType(currentIndex + 2) == "Task") {
				worker.SendTask(currentIndex + 2, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
				Name3->Text = worker.StdStringToSystemString(Name);
				Text3->Text = worker.StdStringToSystemString(Text);
				Author3->Text = worker.StdStringToSystemString(Author);
				Tags3->Text = worker.StdStringToSystemString(Tags);
				Creation_Date3->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date3->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline3->Visible = true;
				const_Time_Deadline3->Text = "Дедлайн: " + deadline.ToString("yyyy.MM.dd HH:mm");
			}

			if (worker.SendType(currentIndex + 2) == "Meeting") {
				worker.SendMeeting(currentIndex + 2, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
				Name3->Text = worker.StdStringToSystemString(Name);
				Text3->Text = worker.StdStringToSystemString(Text);
				Author3->Text = worker.StdStringToSystemString(Author);
				Tags3->Text = worker.StdStringToSystemString(Tags);
				Creation_Date3->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date3->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline3->Visible = true;
				const_Time_Deadline3->Text = "Время встречи: " + meetingTime.ToString("yyyy.MM.dd HH:mm");
			}
		}

		if (capacity - currentIndex == 2) {

			panel1->Visible = true;
			panel2->Visible = true;

			if (worker.SendType(currentIndex) == "Note") {
				worker.SendNote(currentIndex, Name, Text, Author, creationDate, editDate, Tags);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = false;
			}

			if (worker.SendType(currentIndex) == "Task") {
				worker.SendTask(currentIndex, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = true;
				const_Time_DeadLine_1->Text = "Дедлайн: " + deadline.ToString("yyyy.MM.dd HH:mm");
			}

			if (worker.SendType(currentIndex) == "Meeting") {
				worker.SendMeeting(currentIndex, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = true;
				const_Time_DeadLine_1->Text = "Время встречи: " + meetingTime.ToString("yyyy.MM.dd HH:mm");
			}

			//========================================================================================
			if (worker.SendType(currentIndex + 1) == "Note") {
				worker.SendNote(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags);
				Name2->Text = worker.StdStringToSystemString(Name);
				Text2->Text = worker.StdStringToSystemString(Text);
				Author2->Text = worker.StdStringToSystemString(Author);
				Tags2->Text = worker.StdStringToSystemString(Tags);
				Creation_Date2->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date2->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline2->Visible = false;
			}

			if (worker.SendType(currentIndex + 1) == "Task") {
				worker.SendTask(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
				Name2->Text = worker.StdStringToSystemString(Name);
				Text2->Text = worker.StdStringToSystemString(Text);
				Author2->Text = worker.StdStringToSystemString(Author);
				Tags2->Text = worker.StdStringToSystemString(Tags);
				Creation_Date2->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date2->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline2->Visible = true;
				const_Time_Deadline2->Text = "Дедлайн: " + deadline.ToString("yyyy.MM.dd HH:mm");
			}

			if (worker.SendType(currentIndex + 1) == "Meeting") {
				worker.SendMeeting(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
				Name2->Text = worker.StdStringToSystemString(Name);
				Text2->Text = worker.StdStringToSystemString(Text);
				Author2->Text = worker.StdStringToSystemString(Author);
				Tags2->Text = worker.StdStringToSystemString(Tags);
				Creation_Date2->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date2->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_Deadline2->Visible = true;
				const_Time_Deadline2->Text = "Время встречи: " + meetingTime.ToString("yyyy.MM.dd HH:mm");
			}

			panel3->Visible = false;
		}


		if (capacity - currentIndex == 1) {
			panel1->Visible = true;
			if (worker.SendType(currentIndex) == "Note") {
				worker.SendNote(currentIndex, Name, Text, Author, creationDate, editDate, Tags);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = false;
			}

			if (worker.SendType(currentIndex) == "Task") {
				worker.SendTask(currentIndex, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = true;
				const_Time_DeadLine_1->Text = "Дедлайн: " + deadline.ToString("yyyy.MM.dd HH:mm");
			}

			if (worker.SendType(currentIndex) == "Meeting") {
				worker.SendMeeting(currentIndex, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
				Name1->Text = worker.StdStringToSystemString(Name);
				text1->Text = worker.StdStringToSystemString(Text);
				Author1->Text = worker.StdStringToSystemString(Author);
				Tags1->Text = worker.StdStringToSystemString(Tags);
				Creation_Date1->Text = creationDate.ToString("yyyy.MM.dd");
				Edit_Date1->Text = editDate.ToString("yyyy.MM.dd");
				const_Time_DeadLine_1->Visible = true;
				const_Time_DeadLine_1->Text = "Время встречи: " + meetingTime.ToString("yyyy.MM.dd HH:mm");
			}
			
			panel2->Visible = false;
			panel3->Visible = false;
		}
	}

	private: System::Void Menu_Form_Load(System::Object^ sender, System::EventArgs^ e) {
		Search->Text= "Поиск";
		Search->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	private: System::Void Search_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (Search->Text == "Поиск") {
			Search->Text = "";
			Search->ForeColor = System::Drawing::SystemColors::InfoText;
		}
	}
	private: System::Void Search_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (Search->Text == "") {
			Search->Text = "Поиск";
			Search->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}

	private: System::Void NewNote_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string Name, Text, Author, Tags;
		System::DateTime creationDate = DateTime().Now;
		System::DateTime deadline = DateTime().Now;
		System::DateTime meetingTime = DateTime().Now;
		System::DateTime editDate = DateTime().Now;
		bool done = false;
		std::string place;

		Editing_Form^ editDialog = gcnew Editing_Form();

		editDialog->SetData(
			true,
			worker.StdStringToSystemString("Note"),
			worker.StdStringToSystemString(Name),
			worker.StdStringToSystemString(Text),
			worker.StdStringToSystemString(Author),
			worker.StdStringToSystemString(Tags),
			creationDate,
			editDate,
			deadline,
			meetingTime,
			done,
			worker.StdStringToSystemString(place)
		);

		if (editDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			System::String^ newName = editDialog->GetName();
			System::String^ newText = editDialog->GetText();
			System::String^ newAuthor = editDialog->GetAuthor();
			System::String^ newTags = editDialog->GetTags();
			System::DateTime newEditDate = editDialog->GetEditDate();
			System::DateTime newDeadline = editDialog->GetDeadline();
			System::DateTime newMeetingTime = editDialog->GetMeetingTime();
			bool newDone = editDialog->GetDone();
			System::String^ newPlace = editDialog->GetPlace();

			if (editDialog->GetType() == "Note") {
				worker.NewNote(
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags)
				);
			}
			if (editDialog->GetType() == "Task") {
				worker.NewTask(
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newDeadline,
					newDone
				);
			}
			if (editDialog->GetType() == "Meeting") {
				worker.NewMeeting(
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newMeetingTime,
					worker.SystemStringToStdString(newPlace)
				);
			}

			capacity = worker.SendLenth();
			UpdatePanels();
		}
	}

	private: System::Void Sort_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (CreationSort_rbtn->Checked) {
			worker.SortNotesByCreationTime();
		}
		if (EditSort_rbtn->Checked) {
			worker.SortNotesByEditTime();
		}
		if (NameSort_rbtn->Checked) {
			worker.SortNotesByNames();
		}
		if (AuthorSort_ebtn->Checked) {
			worker.SortNotesByAuthors();
		}
		currentIndex = 0;
		capacity = worker.SendLenth();
		UpdatePanels();
	}

	private: System::Void Search_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
	{
		if (e->KeyChar == '\r')
		{
			int matches;
			e->Handled = true;
			worker.Search(worker.SystemStringToStdString(Search->Text), 
				AuthorSearch_chbox->Checked , TagsSearch_chbox->Checked, NameSearch_chbox->Checked, matches);

			capacity = matches;
			currentIndex = 0;
			UpdatePanels();
		}
	}

	private: System::Void Down_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentIndex + 3 < capacity) { 

			currentIndex += 3;
			UpdatePanels();
		}
	}

	private: System::Void Up_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentIndex - 3 >= 0) {
			currentIndex -= 3;
			UpdatePanels();
		}
	}

	private: System::Void panel1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string Name, Text, Author, Tags;
		System::DateTime creationDate = DateTime().Now;
		System::DateTime deadline = DateTime().Now;
		System::DateTime meetingTime = DateTime().Now;
		System::DateTime editDate;
		bool done = false;
		std::string place;

		if (worker.SendType(currentIndex) == "Note") {
			worker.SendNote(currentIndex, Name, Text, Author, creationDate, editDate, Tags);
		}
		if (worker.SendType(currentIndex) == "Task") {
			worker.SendTask(currentIndex, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
		}
		if (worker.SendType(currentIndex) == "Meeting") {
			worker.SendMeeting(currentIndex, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
		}

		Editing_Form^ editDialog = gcnew Editing_Form();

		editDialog->SetData(
			false,
			worker.StdStringToSystemString(worker.SendType(currentIndex)),
			worker.StdStringToSystemString(Name),
			worker.StdStringToSystemString(Text),
			worker.StdStringToSystemString(Author),
			worker.StdStringToSystemString(Tags),
			creationDate,
			editDate,
			deadline,
			meetingTime,
			done,
			worker.StdStringToSystemString(place)
		);
		if (editDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (editDialog->GetDeleteRequest()) {
				worker.DeleteNote(currentIndex);
				capacity = worker.SendLenth();
				UpdatePanels();
				if (capacity == currentIndex) {
					Up_btn_Click(sender, e);
				}
				return;
			}
			System::String^ newName = editDialog->GetName();
			System::String^ newText = editDialog->GetText();
			System::String^ newAuthor = editDialog->GetAuthor();
			System::String^ newTags = editDialog->GetTags();
			System::DateTime newEditDate = editDialog->GetEditDate();
			System::DateTime newDeadline = editDialog->GetDeadline();
			System::DateTime newMeetingTime = editDialog->GetMeetingTime();
			bool newDone = editDialog->GetDone();
			System::String^ newPlace = editDialog->GetPlace();

			if (worker.SendType(currentIndex) == "Note") {
				worker.ReturnNote(
					currentIndex,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags)
				);
			}
			if (worker.SendType(currentIndex) == "Task") {
				worker.ReturnTask(
					currentIndex,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newDeadline,
					newDone
				);
			}
			if (worker.SendType(currentIndex) == "Meeting") {
				worker.ReturnMeeting(
					currentIndex,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newMeetingTime,
					worker.SystemStringToStdString(newPlace)
				);
			}

			capacity = worker.SendLenth();
			UpdatePanels();
		}
	};

	private: System::Void panel2_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string Name, Text, Author, Tags;
		System::DateTime creationDate = DateTime().Now;
		System::DateTime deadline = DateTime().Now;
		System::DateTime meetingTime = DateTime().Now;
		System::DateTime editDate;
		bool done = false;
		std::string place;

		if (worker.SendType(currentIndex + 1) == "Note") {
			worker.SendNote(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags);
		}
		if (worker.SendType(currentIndex + 1) == "Task") {
			worker.SendTask(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
		}
		if (worker.SendType(currentIndex + 1) == "Meeting") {
			worker.SendMeeting(currentIndex + 1, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
		}

		Editing_Form^ editDialog = gcnew Editing_Form();

		editDialog->SetData(
			false,
			worker.StdStringToSystemString(worker.SendType(currentIndex + 1)),
			worker.StdStringToSystemString(Name),
			worker.StdStringToSystemString(Text),
			worker.StdStringToSystemString(Author),
			worker.StdStringToSystemString(Tags),
			creationDate,
			editDate,
			deadline,
			meetingTime,
			done,
			worker.StdStringToSystemString(place)
		);

		if (editDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (editDialog->GetDeleteRequest()) {
				worker.DeleteNote(currentIndex + 1);
				capacity = worker.SendLenth();
				UpdatePanels();
				return;
			}

			System::String^ newName = editDialog->GetName();
			System::String^ newText = editDialog->GetText();
			System::String^ newAuthor = editDialog->GetAuthor();
			System::String^ newTags = editDialog->GetTags();
			System::DateTime newEditDate = editDialog->GetEditDate();
			System::DateTime newDeadline = editDialog->GetDeadline();
			System::DateTime newMeetingTime = editDialog->GetMeetingTime();
			bool newDone = editDialog->GetDone();
			System::String^ newPlace = editDialog->GetPlace();

			if (worker.SendType(currentIndex + 1) == "Note") {
				worker.ReturnNote(
					currentIndex + 1,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags)
				);
			}
			if (worker.SendType(currentIndex + 1) == "Task") {
				worker.ReturnTask(
					currentIndex + 1,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newDeadline,
					newDone
				);
			}
			if (worker.SendType(currentIndex + 1) == "Meeting") {
				worker.ReturnMeeting(
					currentIndex + 1,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newMeetingTime,
					worker.SystemStringToStdString(newPlace)
				);
			}

			capacity = worker.SendLenth();
			UpdatePanels();
			return;
		}
	}

	private: System::Void panel3_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string Name, Text, Author, Tags;
		System::DateTime creationDate = DateTime().Now;
		System::DateTime deadline = DateTime().Now;
		System::DateTime meetingTime = DateTime().Now;
		System::DateTime editDate;
		bool done = false;
		std::string place;

		if (worker.SendType(currentIndex + 2) == "Note") {
			worker.SendNote(currentIndex + 2, Name, Text, Author, creationDate, editDate, Tags);
		}
		if (worker.SendType(currentIndex + 2) == "Task") {
			worker.SendTask(currentIndex + 2, Name, Text, Author, creationDate, editDate, Tags, deadline, done);
		}
		if (worker.SendType(currentIndex + 2) == "Meeting") {
			worker.SendMeeting(currentIndex + 2, Name, Text, Author, creationDate, editDate, Tags, meetingTime, place);
		}

		Editing_Form^ editDialog = gcnew Editing_Form();

		editDialog->SetData(
			false,
			worker.StdStringToSystemString(worker.SendType(currentIndex + 2)),
			worker.StdStringToSystemString(Name),
			worker.StdStringToSystemString(Text),
			worker.StdStringToSystemString(Author),
			worker.StdStringToSystemString(Tags),
			creationDate,
			editDate,
			deadline,
			meetingTime,
			done,
			worker.StdStringToSystemString(place)
		);

		if (editDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (editDialog->GetDeleteRequest()) {
				worker.DeleteNote(currentIndex + 2);
				capacity = worker.SendLenth();
				UpdatePanels();
				return;
			}

			System::String^ newName = editDialog->GetName();
			System::String^ newText = editDialog->GetText();
			System::String^ newAuthor = editDialog->GetAuthor();
			System::String^ newTags = editDialog->GetTags();
			System::DateTime newEditDate = editDialog->GetEditDate();
			System::DateTime newDeadline = editDialog->GetDeadline();
			System::DateTime newMeetingTime = editDialog->GetMeetingTime();
			bool newDone = editDialog->GetDone();
			System::String^ newPlace = editDialog->GetPlace();

			if (worker.SendType(currentIndex + 2) == "Note") {
				worker.ReturnNote(
					currentIndex + 2,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags)
				);
			}
			if (worker.SendType(currentIndex + 2) == "Task") {
				worker.ReturnTask(
					currentIndex + 2,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newDeadline,
					newDone
				);
			}
			if (worker.SendType(currentIndex + 2) == "Meeting") {
				worker.ReturnMeeting(
					currentIndex + 2,
					worker.SystemStringToStdString(newName),
					worker.SystemStringToStdString(newText),
					worker.SystemStringToStdString(newAuthor),
					worker.SystemStringToStdString(newTags),
					newMeetingTime,
					worker.SystemStringToStdString(newPlace)
				);
			}

			capacity = worker.SendLenth();
			UpdatePanels();
		}
	}

	private: System::Void Stat_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		worker.GetStat(authorStats, tagStats);
		Stat_Form^ statsForm = gcnew Stat_Form(authorStats, tagStats);
		statsForm->ShowDialog();

	}
};
}