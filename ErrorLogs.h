#pragma once
    using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

void ThrowError(Exception^ e , String^ ID);
 void LogMessage(String^ Message,String^ ID);
extern char* GStatusLog;