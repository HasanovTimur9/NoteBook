#pragma once

namespace HasanovNoteBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Editing_Form
	/// </summary>
	public ref class Editing_Form : public System::Windows::Forms::Form
	{
	private:

		bool isFormLoaded = false;
		bool IsDeleteRequested;
	public:

		

		Editing_Form(void)
		{
			InitializeComponent();
			

		}
		void SetData
		(
			bool newlyCreated, String^ type,
			String^ name, String^ text, String^ author, String^ tags,
			DateTime creationDate, DateTime editDate, DateTime deadline,
			DateTime meetingTime, bool done, String^ place
		) {

			CreationTime->Text = "Создано: " + creationDate.ToString("yyyy.MM.dd HH:mm");
			EditTime->Text = "Изменено: " + editDate.ToString("yyyy.MM.dd HH:mm");


			SetupTextBox(Name1, "Название", newlyCreated);
			SetupTextBox(MainText, "Основной текст", newlyCreated);
			SetupTextBox(Author, "Автор", newlyCreated);
			SetupTextBox(Tags, "Тэги, через запятую", newlyCreated);
			SetupTextBox(Place, "Место проведения", newlyCreated);

			if (newlyCreated) {


				Name1->Text = "Название";
				Name1->ForeColor = System::Drawing::Color::Gray;

				MainText->Text = "Основной текст";
				MainText->ForeColor = System::Drawing::Color::Gray;

				Author->Text = "Автор";
				Author->ForeColor = System::Drawing::Color::Gray;

				Tags->Text = "Тэги, через запятую";
				Tags->ForeColor = System::Drawing::Color::Gray;

				Place->Text = "Место проведения";
				Place->ForeColor = System::Drawing::Color::Gray;


				dateTimePicker1->Value = deadline;
				Done_chckbox->Checked = done;

				Delete_btn->Visible = false;
				rbtn_Note->Checked = true;

				ChangeType();
			}
			else {
				Name1->Text = name;
				MainText->Text = text;
				Author->Text = author;
				Tags->Text = tags;
				dateTimePicker1->Value = deadline;
				Done_chckbox->Checked = done;
				Place->Text = place;
				Place->Visible = false;
				dateTimePicker1->Visible = false;
				Done_chckbox->Visible = false;
				DeadLine_MeetingTime->Visible = false;

				if (type == "Task") {	
					rbtn_Task->Checked = true;
					ChangeType();
				}
				if (type == "Meeting") {
					rbtn_Meeting->Checked = true;
					ChangeType();
					dateTimePicker1->Value = meetingTime;
				}

				rbtn_Note->Visible = false;
				rbtn_Task->Visible = false;
				rbtn_Meeting->Visible = false;
			}
			isFormLoaded = true;
		}

		bool GetDeleteRequest() { return IsDeleteRequested; };
		String^ GetName() { return Name1->Text; }
		String^ GetText() { return MainText->Text; }
		String^ GetAuthor() { return Author->Text; }
		String^ GetTags() { return Tags->Text; }
		DateTime GetEditDate() { return DateTime().Now; }
		DateTime GetDeadline() { return dateTimePicker1->Value; }
		DateTime GetMeetingTime() { return dateTimePicker1->Value; }
		bool GetDone() { return Done_chckbox->Checked; }
		String^ GetPlace() { return Place->Text; }
		String^ GetType()
		{
			if (rbtn_Note->Checked) {
				return "Note";
			}
			if (rbtn_Task->Checked) {
				return "Task";
			}
			if (rbtn_Meeting->Checked) {
				return "Meeting";
			}
		}

	protected:
		
		~Editing_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ MainText;
	private: System::Windows::Forms::TextBox^ Name1;
	private: System::Windows::Forms::TextBox^ Tags;
	private: System::Windows::Forms::Button^ Delete_btn;
	private: System::Windows::Forms::Button^ Save_btn;
	private: System::Windows::Forms::TextBox^ Author;
	private: System::Windows::Forms::CheckBox^ Done_chckbox;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ DeadLine_MeetingTime;
	private: System::Windows::Forms::RadioButton^ rbtn_Note;
	private: System::Windows::Forms::RadioButton^ rbtn_Task;
	private: System::Windows::Forms::RadioButton^ rbtn_Meeting;
	private: System::Windows::Forms::Label^ CreationTime;
	private: System::Windows::Forms::Label^ EditTime;
	private: System::Windows::Forms::TextBox^ Place;
	private: System::ComponentModel::IContainer^ components;

	private:
		#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Editing_Form::typeid));
			this->MainText = (gcnew System::Windows::Forms::TextBox());
			this->Name1 = (gcnew System::Windows::Forms::TextBox());
			this->Tags = (gcnew System::Windows::Forms::TextBox());
			this->Delete_btn = (gcnew System::Windows::Forms::Button());
			this->Save_btn = (gcnew System::Windows::Forms::Button());
			this->Author = (gcnew System::Windows::Forms::TextBox());
			this->Done_chckbox = (gcnew System::Windows::Forms::CheckBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->DeadLine_MeetingTime = (gcnew System::Windows::Forms::Label());
			this->rbtn_Note = (gcnew System::Windows::Forms::RadioButton());
			this->rbtn_Task = (gcnew System::Windows::Forms::RadioButton());
			this->rbtn_Meeting = (gcnew System::Windows::Forms::RadioButton());
			this->CreationTime = (gcnew System::Windows::Forms::Label());
			this->EditTime = (gcnew System::Windows::Forms::Label());
			this->Place = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// MainText
			// 
			this->MainText->Location = System::Drawing::Point(12, 112);
			this->MainText->Multiline = true;
			this->MainText->Name = L"MainText";
			this->MainText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->MainText->Size = System::Drawing::Size(891, 621);
			this->MainText->TabIndex = 0;
			this->MainText->Tag = L"Основной текст";
			this->MainText->Text = L"Text";
			// 
			// Name1
			// 
			this->Name1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name1->Location = System::Drawing::Point(12, 12);
			this->Name1->Name = L"Name1";
			this->Name1->Size = System::Drawing::Size(416, 44);
			this->Name1->TabIndex = 2;
			this->Name1->Tag = L"Название";
			this->Name1->Text = L"Name";
			// 
			// Tags
			// 
			this->Tags->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Tags->Location = System::Drawing::Point(12, 68);
			this->Tags->Name = L"Tags";
			this->Tags->Size = System::Drawing::Size(416, 38);
			this->Tags->TabIndex = 3;
			this->Tags->Tag = L"Тэги, через запятую";
			this->Tags->Text = L"Tags";
			// 
			// Delete_btn
			// 
			this->Delete_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Delete_btn->Location = System::Drawing::Point(12, 783);
			this->Delete_btn->Name = L"Delete_btn";
			this->Delete_btn->Size = System::Drawing::Size(231, 93);
			this->Delete_btn->TabIndex = 4;
			this->Delete_btn->Text = L"Удалить";
			this->Delete_btn->UseVisualStyleBackColor = true;
			this->Delete_btn->Click += gcnew System::EventHandler(this, &Editing_Form::Delete_btn_Click);
			// 
			// Save_btn
			// 
			this->Save_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Save_btn->Location = System::Drawing::Point(672, 783);
			this->Save_btn->Name = L"Save_btn";
			this->Save_btn->Size = System::Drawing::Size(231, 93);
			this->Save_btn->TabIndex = 5;
			this->Save_btn->Text = L"Сохранить";
			this->Save_btn->UseVisualStyleBackColor = true;
			this->Save_btn->Click += gcnew System::EventHandler(this, &Editing_Form::Save_btn_Click);
			// 
			// Author
			// 
			this->Author->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Author->Location = System::Drawing::Point(12, 739);
			this->Author->Name = L"Author";
			this->Author->Size = System::Drawing::Size(416, 38);
			this->Author->TabIndex = 6;
			this->Author->Tag = L"Автор";
			this->Author->Text = L"Author";
			// 
			// Done_chckbox
			// 
			this->Done_chckbox->AutoSize = true;
			this->Done_chckbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Done_chckbox->Location = System::Drawing::Point(716, 742);
			this->Done_chckbox->Name = L"Done_chckbox";
			this->Done_chckbox->Size = System::Drawing::Size(187, 35);
			this->Done_chckbox->TabIndex = 7;
			this->Done_chckbox->Text = L"Готовность";
			this->Done_chckbox->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dateTimePicker1->Location = System::Drawing::Point(598, 68);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(305, 38);
			this->dateTimePicker1->TabIndex = 8;
			this->dateTimePicker1->Value = System::DateTime(2025, 2, 26, 0, 0, 0, 0);
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &Editing_Form::dateTimePicker1_ValueChanged);
			// 
			// DeadLine_MeetingTime
			// 
			this->DeadLine_MeetingTime->AutoSize = true;
			this->DeadLine_MeetingTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DeadLine_MeetingTime->Location = System::Drawing::Point(458, 71);
			this->DeadLine_MeetingTime->Name = L"DeadLine_MeetingTime";
			this->DeadLine_MeetingTime->Size = System::Drawing::Size(134, 31);
			this->DeadLine_MeetingTime->TabIndex = 9;
			this->DeadLine_MeetingTime->Text = L"Дедлайн:";
			// 
			// rbtn_Note
			// 
			this->rbtn_Note->AutoSize = true;
			this->rbtn_Note->Checked = true;
			this->rbtn_Note->Location = System::Drawing::Point(249, 818);
			this->rbtn_Note->Name = L"rbtn_Note";
			this->rbtn_Note->Size = System::Drawing::Size(128, 29);
			this->rbtn_Note->TabIndex = 10;
			this->rbtn_Note->TabStop = true;
			this->rbtn_Note->Text = L"Заметка";
			this->rbtn_Note->UseVisualStyleBackColor = true;
			this->rbtn_Note->CheckedChanged += gcnew System::EventHandler(this, &Editing_Form::rbtn_Note_CheckedChanged);
			// 
			// rbtn_Task
			// 
			this->rbtn_Task->AutoSize = true;
			this->rbtn_Task->Location = System::Drawing::Point(390, 818);
			this->rbtn_Task->Name = L"rbtn_Task";
			this->rbtn_Task->Size = System::Drawing::Size(128, 29);
			this->rbtn_Task->TabIndex = 11;
			this->rbtn_Task->Text = L"Задание";
			this->rbtn_Task->UseVisualStyleBackColor = true;
			this->rbtn_Task->CheckedChanged += gcnew System::EventHandler(this, &Editing_Form::rbtn_Task_CheckedChanged);
			// 
			// rbtn_Meeting
			// 
			this->rbtn_Meeting->AutoSize = true;
			this->rbtn_Meeting->Location = System::Drawing::Point(524, 818);
			this->rbtn_Meeting->Name = L"rbtn_Meeting";
			this->rbtn_Meeting->Size = System::Drawing::Size(142, 29);
			this->rbtn_Meeting->TabIndex = 12;
			this->rbtn_Meeting->Text = L"Собрание";
			this->rbtn_Meeting->UseVisualStyleBackColor = true;
			this->rbtn_Meeting->CheckedChanged += gcnew System::EventHandler(this, &Editing_Form::rbtn_Meeting_CheckedChanged);
			// 
			// CreationTime
			// 
			this->CreationTime->AutoSize = true;
			this->CreationTime->Location = System::Drawing::Point(459, 9);
			this->CreationTime->Name = L"CreationTime";
			this->CreationTime->Size = System::Drawing::Size(290, 25);
			this->CreationTime->TabIndex = 13;
			this->CreationTime->Text = L"Создано:yyyy.MM.dd hh:mm";
			// 
			// EditTime
			// 
			this->EditTime->AutoSize = true;
			this->EditTime->Location = System::Drawing::Point(459, 34);
			this->EditTime->Name = L"EditTime";
			this->EditTime->Size = System::Drawing::Size(305, 25);
			this->EditTime->TabIndex = 14;
			this->EditTime->Text = L"Изменено:yyyy.MM.dd hh:mm";
			// 
			// Place
			// 
			this->Place->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Place->Location = System::Drawing::Point(487, 739);
			this->Place->Name = L"Place";
			this->Place->Size = System::Drawing::Size(416, 38);
			this->Place->TabIndex = 15;
			this->Place->Tag = L"Место проведения";
			this->Place->Text = L"Место проведения";
			// 
			// Editing_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 888);
			this->Controls->Add(this->Place);
			this->Controls->Add(this->EditTime);
			this->Controls->Add(this->CreationTime);
			this->Controls->Add(this->rbtn_Meeting);
			this->Controls->Add(this->rbtn_Task);
			this->Controls->Add(this->rbtn_Note);
			this->Controls->Add(this->DeadLine_MeetingTime);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->Done_chckbox);
			this->Controls->Add(this->Author);
			this->Controls->Add(this->Save_btn);
			this->Controls->Add(this->Delete_btn);
			this->Controls->Add(this->Tags);
			this->Controls->Add(this->Name1);
			this->Controls->Add(this->MainText);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Editing_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion

	private: void ChangeType() {

		if (rbtn_Note->Checked) {
			DeadLine_MeetingTime->Visible = false;
			Place->Visible = false;
			dateTimePicker1->Visible = false;
			Done_chckbox->Visible = false;
		}

		if (rbtn_Task->Checked) {
			DeadLine_MeetingTime->Visible = true;
			DeadLine_MeetingTime->Text = "Дедлайн:";
			Done_chckbox->Visible = true;
			dateTimePicker1->Visible = true;
			Place->Visible = false;
		}

		if (rbtn_Meeting->Checked) {
			DeadLine_MeetingTime->Visible = true;
			DeadLine_MeetingTime->Text = "Время:";
			Place->Visible = true;
			dateTimePicker1->Visible = true;
			Done_chckbox->Visible = false;
		}
	}
	

	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	
	if (dateTimePicker1->Value < DateTime().Now)
	{
		if (!isFormLoaded) {
			return;
		}

		if (dateTimePicker1->Value < DateTime::Now) {
			dateTimePicker1->Value = DateTime::Now;
			MessageBox::Show("Выберите время не меньше текущего.");
		}
	}
	}
	void SetupTextBox(TextBox^ textBox, String^ placeholder, bool newlyCreated) {
		if (newlyCreated) {
				   
			textBox->Text = placeholder;
			textBox->ForeColor = Color::Gray;
		}
		else {
			textBox->ForeColor = Color::Black;
		}
		textBox->Enter += gcnew EventHandler(this, &Editing_Form::TextBox_Enter);
		textBox->Leave += gcnew EventHandler(this, &Editing_Form::TextBox_Leave);
	}

	void TextBox_Enter(Object^ sender, EventArgs^ e)
	{
		TextBox^ textBox = (TextBox^)sender;

		if (textBox->Text == textBox->Tag->ToString())
		{
			textBox->Text = "";
			textBox->ForeColor = Color::Black;
		}
	}

	void TextBox_Leave(Object^ sender, EventArgs^ e)
	{
		TextBox^ textBox = (TextBox^)sender;

		if (String::IsNullOrEmpty(textBox->Text))
		{
			textBox->Text = textBox->Tag->ToString();
			textBox->ForeColor = Color::Gray;
		}
	}

	private: System::Void rbtn_Note_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ChangeType();
	}

	private: System::Void rbtn_Task_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ChangeType();
	}

	private: System::Void rbtn_Meeting_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ChangeType();
	}

	private: System::Void Save_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (String::IsNullOrEmpty(MainText->Text) || MainText->Text == MainText->Tag->ToString()) {
			MessageBox::Show("Нельзя сохранить запись без текста!");
			return;
		}

		if (Name1->Text == Name1->Tag->ToString()) {
			Name1->Text = "";
		}
		if (Author->Text == Author->Tag->ToString()) {
			Author->Text = "";
		}
		if (Tags->Text == Tags->Tag->ToString()) {
			Tags->Text = "";
		}
		if (Place->Text == Place->Tag->ToString()) {
			Place->Text = "";
		}

		IsDeleteRequested = false;
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	private: System::Void Delete_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		IsDeleteRequested = true;
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	private: System::Void Cancel_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		IsDeleteRequested = false;
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
};
}
