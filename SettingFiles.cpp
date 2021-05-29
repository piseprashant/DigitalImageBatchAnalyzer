#include "StdAfx.h"
#include "SettingFiles.h"


/**********************************************************************************************
	  setting file constructor with logfilename
**********************************************************************************************/
SettingFiles::SettingFiles(String^ filename)
{

StatusLog=filename;
}


/**********************************************************************************************
	  setting file constructor with required parameters 
	  :Should use
**********************************************************************************************/
SettingFiles::SettingFiles(String^ Logfile, String^ Projectfle, String^ Stackfle)
{

try{
StatusLog=Logfile;
if(SetProjectFileName(Projectfle)!=Success)
	LogStatus("ProjectName not set properly","SettingFiles");
if(SetStackFileName(Stackfle)!=Success)
	LogStatus("Satckfilename not set properly","SettingFiles");
} catch ( Exception^ ex ) {
	ThrowError(ex, "SettingFiles");
	//LogMessage("","");
}

}



/***********************************************************************************************/
//Throw error to the log file
/***********************************************************************************************/
//#include "ErrorLogs.h"
char* GStatusLog;
  void ThrowError(Exception^ e , String^ ID)
{

String^ filename= gcnew String(GStatusLog);
File::AppendAllText(filename, "\r\n----->");
File::AppendAllText(filename,String::Concat(ID, ": Exception\r\n" ));
File::AppendAllText(filename,String::Concat(e->ToString()));
File::AppendAllText(filename, "\r\n****************************************************************************\r\n" );

}

  void LogMessage(String^ Message,String^ ID)
{
String^ filename= gcnew String(GStatusLog);
File::AppendAllText(filename,String::Concat(ID," says::",Message));

}