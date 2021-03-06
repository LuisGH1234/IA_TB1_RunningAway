#pragma once
#include "Knapsack.h"
#include "Knapsack2.h"
namespace RunningAway {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Algoritmo1 = new Knapsack();
			Algoritmo2 = new Knapsack2();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  OrigenLabel;
	private: System::Windows::Forms::TextBox^  txtPesoMax;
	protected:

	protected:

	private: System::Windows::Forms::ComboBox^  cmbOrigen;

	private: System::Windows::Forms::Button^  btnCalcular;
	private: System::Windows::Forms::GroupBox^  gboxInputs;


	private: System::Windows::Forms::Label^  PresupuestoLabel;
	private: System::Windows::Forms::Label^  pesoMaxMochilaLabel;



	private: System::Windows::Forms::Label^  DestinoLabel;
	private: System::Windows::Forms::ComboBox^  cmbDestino;
	private: System::Windows::Forms::TextBox^  txtPresupuesto;


	private: System::Windows::Forms::Button^  btnLimpiar;
	private: System::Windows::Forms::GroupBox^  gboxOutputs;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  mochilaLabel;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;






	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnGenerar;




	private:
		Knapsack *Algoritmo1;
		Knapsack2 *Algoritmo2;

			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->OrigenLabel = (gcnew System::Windows::Forms::Label());
			this->txtPesoMax = (gcnew System::Windows::Forms::TextBox());
			this->cmbOrigen = (gcnew System::Windows::Forms::ComboBox());
			this->btnCalcular = (gcnew System::Windows::Forms::Button());
			this->gboxInputs = (gcnew System::Windows::Forms::GroupBox());
			this->btnGenerar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbDestino = (gcnew System::Windows::Forms::ComboBox());
			this->txtPresupuesto = (gcnew System::Windows::Forms::TextBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->PresupuestoLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pesoMaxMochilaLabel = (gcnew System::Windows::Forms::Label());
			this->DestinoLabel = (gcnew System::Windows::Forms::Label());
			this->gboxOutputs = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mochilaLabel = (gcnew System::Windows::Forms::Label());
			this->gboxInputs->SuspendLayout();
			this->gboxOutputs->SuspendLayout();
			this->SuspendLayout();
			// 
			// OrigenLabel
			// 
			this->OrigenLabel->AutoSize = true;
			this->OrigenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OrigenLabel->Location = System::Drawing::Point(30, 82);
			this->OrigenLabel->Name = L"OrigenLabel";
			this->OrigenLabel->Size = System::Drawing::Size(44, 15);
			this->OrigenLabel->TabIndex = 0;
			this->OrigenLabel->Text = L"Origen";
			// 
			// txtPesoMax
			// 
			this->txtPesoMax->Location = System::Drawing::Point(124, 158);
			this->txtPesoMax->Name = L"txtPesoMax";
			this->txtPesoMax->Size = System::Drawing::Size(163, 22);
			this->txtPesoMax->TabIndex = 1;
			// 
			// cmbOrigen
			// 
			this->cmbOrigen->FormattingEnabled = true;
			this->cmbOrigen->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"", L"item1", L"item2" });
			this->cmbOrigen->Location = System::Drawing::Point(124, 79);
			this->cmbOrigen->Name = L"cmbOrigen";
			this->cmbOrigen->Size = System::Drawing::Size(163, 24);
			this->cmbOrigen->TabIndex = 2;
			// 
			// btnCalcular
			// 
			this->btnCalcular->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnCalcular->AutoSize = true;
			this->btnCalcular->Location = System::Drawing::Point(33, 277);
			this->btnCalcular->Name = L"btnCalcular";
			this->btnCalcular->Size = System::Drawing::Size(81, 33);
			this->btnCalcular->TabIndex = 3;
			this->btnCalcular->Text = L"Calcular";
			this->btnCalcular->UseVisualStyleBackColor = true;
			this->btnCalcular->Click += gcnew System::EventHandler(this, &MyForm::btnCalcular_Click);
			// 
			// gboxInputs
			// 
			this->gboxInputs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->gboxInputs->Controls->Add(this->btnGenerar);
			this->gboxInputs->Controls->Add(this->label1);
			this->gboxInputs->Controls->Add(this->cmbDestino);
			this->gboxInputs->Controls->Add(this->txtPresupuesto);
			this->gboxInputs->Controls->Add(this->cmbOrigen);
			this->gboxInputs->Controls->Add(this->btnLimpiar);
			this->gboxInputs->Controls->Add(this->PresupuestoLabel);
			this->gboxInputs->Controls->Add(this->label2);
			this->gboxInputs->Controls->Add(this->txtPesoMax);
			this->gboxInputs->Controls->Add(this->btnCalcular);
			this->gboxInputs->Controls->Add(this->pesoMaxMochilaLabel);
			this->gboxInputs->Controls->Add(this->DestinoLabel);
			this->gboxInputs->Controls->Add(this->OrigenLabel);
			this->gboxInputs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gboxInputs->Location = System::Drawing::Point(12, 12);
			this->gboxInputs->Name = L"gboxInputs";
			this->gboxInputs->Size = System::Drawing::Size(348, 547);
			this->gboxInputs->TabIndex = 4;
			this->gboxInputs->TabStop = false;
			this->gboxInputs->Text = L"Ingreso de Datos";
			// 
			// btnGenerar
			// 
			this->btnGenerar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnGenerar->Location = System::Drawing::Point(118, 335);
			this->btnGenerar->Name = L"btnGenerar";
			this->btnGenerar->Size = System::Drawing::Size(81, 33);
			this->btnGenerar->TabIndex = 10;
			this->btnGenerar->Text = L"Generar";
			this->btnGenerar->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(115, 438);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 16);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			// 
			// cmbDestino
			// 
			this->cmbDestino->FormattingEnabled = true;
			this->cmbDestino->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"", L"item3", L"item4" });
			this->cmbDestino->Location = System::Drawing::Point(124, 120);
			this->cmbDestino->Name = L"cmbDestino";
			this->cmbDestino->Size = System::Drawing::Size(163, 24);
			this->cmbDestino->TabIndex = 6;
			// 
			// txtPresupuesto
			// 
			this->txtPresupuesto->Location = System::Drawing::Point(124, 197);
			this->txtPresupuesto->Name = L"txtPresupuesto";
			this->txtPresupuesto->Size = System::Drawing::Size(163, 22);
			this->txtPresupuesto->TabIndex = 5;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnLimpiar->Location = System::Drawing::Point(206, 277);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(81, 33);
			this->btnLimpiar->TabIndex = 4;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = true;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &MyForm::btnLimpiar_Click);
			// 
			// PresupuestoLabel
			// 
			this->PresupuestoLabel->AutoSize = true;
			this->PresupuestoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PresupuestoLabel->Location = System::Drawing::Point(30, 200);
			this->PresupuestoLabel->Name = L"PresupuestoLabel";
			this->PresupuestoLabel->Size = System::Drawing::Size(76, 15);
			this->PresupuestoLabel->TabIndex = 3;
			this->PresupuestoLabel->Text = L"Presupuesto";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(115, 405);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"label2";
			// 
			// pesoMaxMochilaLabel
			// 
			this->pesoMaxMochilaLabel->AutoSize = true;
			this->pesoMaxMochilaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pesoMaxMochilaLabel->Location = System::Drawing::Point(30, 161);
			this->pesoMaxMochilaLabel->Name = L"pesoMaxMochilaLabel";
			this->pesoMaxMochilaLabel->Size = System::Drawing::Size(83, 15);
			this->pesoMaxMochilaLabel->TabIndex = 2;
			this->pesoMaxMochilaLabel->Text = L"Peso Maximo";
			// 
			// DestinoLabel
			// 
			this->DestinoLabel->AutoSize = true;
			this->DestinoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DestinoLabel->Location = System::Drawing::Point(30, 123);
			this->DestinoLabel->Name = L"DestinoLabel";
			this->DestinoLabel->Size = System::Drawing::Size(49, 15);
			this->DestinoLabel->TabIndex = 1;
			this->DestinoLabel->Text = L"Destino";
			// 
			// gboxOutputs
			// 
			this->gboxOutputs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gboxOutputs->Controls->Add(this->label5);
			this->gboxOutputs->Controls->Add(this->label4);
			this->gboxOutputs->Controls->Add(this->label3);
			this->gboxOutputs->Controls->Add(this->mochilaLabel);
			this->gboxOutputs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gboxOutputs->Location = System::Drawing::Point(376, 13);
			this->gboxOutputs->Name = L"gboxOutputs";
			this->gboxOutputs->Size = System::Drawing::Size(785, 546);
			this->gboxOutputs->TabIndex = 5;
			this->gboxOutputs->TabStop = false;
			this->gboxOutputs->Text = L"Resultados";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(573, 96);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 20);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Algoritmo 3";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(328, 96);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 20);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Algoritmo 2";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(91, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Algoritmo 1";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// mochilaLabel
			// 
			this->mochilaLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->mochilaLabel->AutoSize = true;
			this->mochilaLabel->Location = System::Drawing::Point(23, 39);
			this->mochilaLabel->Name = L"mochilaLabel";
			this->mochilaLabel->Size = System::Drawing::Size(70, 20);
			this->mochilaLabel->TabIndex = 8;
			this->mochilaLabel->Text = L"Mochila";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1173, 571);
			this->Controls->Add(this->gboxOutputs);
			this->Controls->Add(this->gboxInputs);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Knapsack";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->gboxInputs->ResumeLayout(false);
			this->gboxInputs->PerformLayout();
			this->gboxOutputs->ResumeLayout(false);
			this->gboxOutputs->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
	
}
private: System::Void btnCalcular_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtPesoMax->Text->Length <= 0)
		return;
	
	Algoritmo1->SetPesoMax(Convert::ToInt32(txtPesoMax->Text));
	label3->Text = Algoritmo1->HillClimbing();
	Algoritmo1->resetItems();
	label5->Text = Algoritmo1->Ramificacion_Poda();
	
	Algoritmo2->SetPesoMax_SetDineroMx(Convert::ToInt32(txtPesoMax->Text), Convert::ToInt32(txtPresupuesto->Text));
	label4->Text = Algoritmo2->HillClimbing();
}
private: System::Void btnLimpiar_Click(System::Object^  sender, System::EventArgs^  e) {
	txtPesoMax->Clear();
	txtPresupuesto->Clear();
	cmbDestino->SelectedIndex = 0;
	cmbOrigen->SelectedIndex = 0;
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
