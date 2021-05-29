#include "StdAfx.h"
#include "ParameterObject.h"
#include "OpenCV.h"


/**********************************************************************************************
	 Image processing part of Parameter object
**********************************************************************************************/
 void ParameterObject::Execuite()
		{
try{			
			System::String^ Results;
			Bitmap^ Output;
			OpenCV ImageHandler;
			ImageHandler.ImageProc(Input, Properties, Results,Output,UniqueID);
			this->Result=Output;
			//this->Result=gcnew Bitmap(Output);
			this->ExtraResults=Results;
 }catch ( System::Exception^ ex ) {
ThrowError(ex, "Execuite");
//LogMessage("","");
}
		}