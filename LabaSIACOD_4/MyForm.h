#pragma once
#include "Cont.h"
#include "Graf.h"
namespace LabaSIACOD4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(223, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(241, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ќбход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(351, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 25);
			this->label1->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(937, 530);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int N = 65;
		int j = 0;
		int count = 0;
		int tmpX = 0;
		int tmp;
		int tmpY = 0;
		int count_lighat = 0;
		//array<System::Windows::Forms::TextBox^>^ txt_box_mas = gcnew array<System::Windows::Forms::TextBox^>(N);


	private: System::Void txt_box_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ a = (Button^)sender;
		count++;
		if (count % 2 == 0) {
			Graphics^ g = this->CreateGraphics();
			g->DrawLine(gcnew Pen(Color::Black), tmpX+20, tmpY+10, Convert::ToInt32(a->Location.X)+20, Convert::ToInt32(a->Location.Y)+10);
			//this->Invalidate();
			lst[tmp].add(Convert::ToInt32(a->Text), &lst[Convert::ToInt32(a->Text)]);
			lst[Convert::ToInt32(a->Text)].add(tmp, &lst[tmp]);
		}
		tmp = Convert::ToInt32(a->Text);
		tmpX = Convert::ToInt32(a->Location.X);
		tmpY = Convert::ToInt32(a->Location.Y);
	}

		   List<Graf> lst;
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Graf a(j);
		lst.push_back(a);
		System::Windows::Forms::Button^ txt_box = (gcnew System::Windows::Forms::Button());
		txt_box->Location = System::Drawing::Point(e->X, e->Y);
		txt_box->Name = L"txt_box" + j;
		txt_box->Size = System::Drawing::Size(30, 30);
		txt_box->TabIndex = j;
		txt_box->Tag = j;
		txt_box->Text = j.ToString();
		txt_box->Click += gcnew System::EventHandler(this, &MyForm::txt_box_Click);
		//txt_box_mas[j] = txt_box;
		this->Controls->Add(txt_box);
		j++;
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = (textBox1->Text) + " " +  (Convert::ToString(lst[Convert::ToInt32(textBox1->Text)].obhod()));
		for (int i = 0; i<j; i++)
			lst[i].setVisited(false);
	}
};
}
