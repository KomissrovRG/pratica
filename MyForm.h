#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <ctime>
#include "MyForm1.h"
using namespace std;

namespace practic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;






	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Комиссаров Руслан";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Дата и время запуска: ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 80);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 25);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Запустить программу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 132);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Комиссаров РГ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		struct tm* date;
		char Current_date[100];
		const time_t timer = time(NULL);
		date = localtime(&timer);
		strftime(Current_date, 100, "%d.%m.%Y %H:%M:%S", date);
		System::String^ strCLR = gcnew System::String(Current_date);     //выводит время и дату запуска программы
		label2->Text += strCLR;
		srand(time(0));
		FILE* f = fopen("numbers.txt", "w");	//создаёт txt файл и заполняет его цифрами от -9 до 9
		for (int i = 0; i < 100; i++)
			fprintf(f, "%d ", rand() % 19 - 9);
		fclose(f);
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (Char::IsPunctuation(e->KeyChar) || Char::IsDigit(e->KeyChar) || Char::IsSymbol(e->KeyChar))        //запрещает ввод любых символов,кроме букв
			e->Handled = true;
		if (Char::IsLetter(e->KeyChar))
			return;
	}
	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (Char::IsPunctuation(e->KeyChar) || Char::IsDigit(e->KeyChar) || Char::IsSymbol(e->KeyChar))
			e->Handled = true;
		if (Char::IsLetter(e->KeyChar))
			return;
}
	private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (Char::IsPunctuation(e->KeyChar) || Char::IsDigit(e->KeyChar) || Char::IsSymbol(e->KeyChar))
			e->Handled = true;
		if (Char::IsLetter(e->KeyChar))
			return;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1^ form = gcnew MyForm1;       //создаёт новую форму
	form->FillData();	//выводит  на экран массив цифр, записанных в файл
	form->ShowDialog();           //выводит новую форму
}
};
}
