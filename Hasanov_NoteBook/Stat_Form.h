#pragma once

namespace HasanovNoteBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class Stat_Form : public System::Windows::Forms::Form
	{
	private:
		Dictionary<String^, int>^ authorStats;
		Dictionary<String^, int>^ tagStats;

	public:

		Stat_Form(Dictionary<String^, int>^ authorStats, Dictionary<String^, int>^ tagStats) {

			this->authorStats = authorStats;
			this->tagStats = tagStats;

			InitializeComponent();
			UpdateDataGridViews();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Stat_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ AuthorStat_dataGridView;
	private: System::Windows::Forms::DataGridView^ TagsStat_dataGridView;
	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stat_Form::typeid));
			this->TagsStat_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->AuthorStat_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TagsStat_dataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AuthorStat_dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// TagsStat_dataGridView
			// 
			this->TagsStat_dataGridView->AllowUserToAddRows = false;
			this->TagsStat_dataGridView->AllowUserToDeleteRows = false;
			this->TagsStat_dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->TagsStat_dataGridView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->TagsStat_dataGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->TagsStat_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TagsStat_dataGridView->Dock = System::Windows::Forms::DockStyle::Left;
			this->TagsStat_dataGridView->GridColor = System::Drawing::SystemColors::Control;
			this->TagsStat_dataGridView->Location = System::Drawing::Point(0, 0);
			this->TagsStat_dataGridView->Name = L"TagsStat_dataGridView";
			this->TagsStat_dataGridView->ReadOnly = true;
			this->TagsStat_dataGridView->RowHeadersVisible = false;
			this->TagsStat_dataGridView->RowHeadersWidth = 82;
			this->TagsStat_dataGridView->RowTemplate->Height = 33;
			this->TagsStat_dataGridView->Size = System::Drawing::Size(465, 663);
			this->TagsStat_dataGridView->TabIndex = 0;
			// 
			// AuthorStat_dataGridView
			// 
			this->AuthorStat_dataGridView->AllowUserToAddRows = false;
			this->AuthorStat_dataGridView->AllowUserToDeleteRows = false;
			this->AuthorStat_dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->AuthorStat_dataGridView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->AuthorStat_dataGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->AuthorStat_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->AuthorStat_dataGridView->Dock = System::Windows::Forms::DockStyle::Right;
			this->AuthorStat_dataGridView->GridColor = System::Drawing::SystemColors::Control;
			this->AuthorStat_dataGridView->Location = System::Drawing::Point(469, 0);
			this->AuthorStat_dataGridView->Name = L"AuthorStat_dataGridView";
			this->AuthorStat_dataGridView->ReadOnly = true;
			this->AuthorStat_dataGridView->RowHeadersVisible = false;
			this->AuthorStat_dataGridView->RowHeadersWidth = 82;
			this->AuthorStat_dataGridView->RowTemplate->Height = 33;
			this->AuthorStat_dataGridView->Size = System::Drawing::Size(465, 663);
			this->AuthorStat_dataGridView->TabIndex = 1;
			// 
			// Stat_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 663);
			this->Controls->Add(this->AuthorStat_dataGridView);
			this->Controls->Add(this->TagsStat_dataGridView);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Stat_Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TagsStat_dataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AuthorStat_dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion

		void UpdateDataGridViews() {
			UpdateDataGridView(AuthorStat_dataGridView, authorStats, "Автор", "Количество записей");
			UpdateDataGridView(TagsStat_dataGridView, tagStats, "Тег", "Количество записей");
		}

		void UpdateDataGridView(DataGridView^ dataGridView, Dictionary<String^, int>^ stats, String^ column1, String^ column2) {
			dataGridView->Rows->Clear();
			dataGridView->Columns->Clear();

			dataGridView->Columns->Add(gcnew DataGridViewTextBoxColumn());
			dataGridView->Columns->Add(gcnew DataGridViewTextBoxColumn());
			dataGridView->Columns[0]->HeaderText = column1;
			dataGridView->Columns[1]->HeaderText = column2;

			for each (auto pair in stats) {
				dataGridView->Rows->Add(pair.Key, pair.Value);
			}
		}
	};
}
