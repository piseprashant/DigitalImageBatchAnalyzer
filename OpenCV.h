#pragma once
#include"stdafx.h"
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include "SettingFiles.h"
#include "ErrorLogs.h"


	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	using namespace System::Drawing::Imaging;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::Text;
	using namespace cv;
	using namespace std;

class OpenCV
{
public:
	

public:
	OpenCV(void);
	~OpenCV(void);
	// Convert .NET Bitmap to an OpenCV IplImage.

/***********************************************************************************************/
//Function to convert Bitmap to Opencv Mat
/***********************************************************************************************/
public: static Mat  BitmapToMat (Bitmap^ bitmap)
{
	
try{
	IplImage* tmp;
	Mat tmpmat;

	BitmapData^ bmData = bitmap->LockBits( System::Drawing::Rectangle( 0, 0, bitmap->Width, bitmap->Height) , System::Drawing::Imaging::ImageLockMode::ReadWrite, bitmap->PixelFormat );
	if(bitmap->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed){
			tmp = cvCreateImage( cvSize(bitmap->Width , bitmap->Height) , IPL_DEPTH_8U , 1);
			tmpmat.create(cv::Size(bitmap->Width , bitmap->Height), CV_8UC1);
	}
	else{ 
			tmp = cvCreateImage( cvSize(bitmap->Width , bitmap->Height) , IPL_DEPTH_8U , 3);
			tmpmat.create(cv::Size(bitmap->Width , bitmap->Height), CV_8UC3);
	}

	//memcpy(tmp->imageData,(char*)bmData->Scan0.ToPointer(),tmp->widthStep*bitmap->Height);
	//tmp=(IplImage*)&tmpmat;
	Int32 despos=0;
	Int32 srcpos=0;
	for(int i=0;i<tmp->height;i++){
		memcpy(((char*)tmp->imageData+despos),((char*)bmData->Scan0.ToPointer()+srcpos),tmp->widthStep );
		despos+= tmp->widthStep;
		srcpos+= bmData->Stride;
	}

	bitmap->UnlockBits(bmData);
	Mat matr=tmp;
	matr.copyTo(tmpmat);
	cvReleaseImage(&tmp);

	//Mat tmpmat=cvarrToMat(tmp);
	return tmpmat;

} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BitmapToMat");
	//LogMessage("","");
}

}

/***********************************************************************************************/
//Function to convert Opencv Mat to Bitmap
/***********************************************************************************************/
public: static Bitmap^ MatToBitmap( Mat img)
{
try{
	IplImage tmp1=img;
    IplImage* ipl=&tmp1;
	
	//TODO: Bitmap to mat convertion stride length problem have to be solved
	
	Bitmap^ tmp;
	if(ipl->nChannels == 3)
	tmp=gcnew Bitmap(ipl->width, ipl->height,System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	else
	tmp=gcnew Bitmap(ipl->width, ipl->height,System::Drawing::Imaging::PixelFormat::Format8bppIndexed);


	BitmapData^ bmDatades = tmp->LockBits( System::Drawing::Rectangle( 0, 0, tmp->Width, tmp->Height) , System::Drawing::Imaging::ImageLockMode::ReadWrite, tmp->PixelFormat );
	Int32 despos=0;
	Int32 srcpos=0;

	for(int i=0;i<ipl->height;i++){
		memcpy(((char*)bmDatades->Scan0.ToPointer()+despos),((char*)ipl->imageData+srcpos),ipl->widthStep );
		despos+=bmDatades->Stride;
		srcpos+= ipl->widthStep;
	}

	tmp->UnlockBits(bmDatades);
	return tmp;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "MatToBitmap");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to Read a property from the property string
/***********************************************************************************************/
public:static System::String^ ReadProperty(System::String^ Property, System::String^ List)
		{
			
try{			
			array <System::String^>^ delimiter = {PROPERTYEND,VALUEEND};
			array <System::String^>^ arr = List->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
			

			int index=Array::IndexOf(arr,Property);
			if(index<0)
			{
				return "";
			}
			else{
				return (System::String^)arr->GetValue(index+1);
			}

} catch ( System::Exception^ ex ) {
	ThrowError(ex, "ReadProperty");
	//LogMessage("","");
}
			
		}

/***********************************************************************************************/
//Convert the results to string with delimiters
/***********************************************************************************************/
public:static System::String^ Results2Str(array<System::String^>^ arr)
	   {
try{	
			System::String^ str;
			if(arr->Length%2==0)
			{
			
			for (int i=0;i<arr->Length;i+=2)
			{
			str= System::String::Concat(str, System::String::Concat(arr->GetValue(i),PROPERTYEND));
			str= System::String::Concat(str, System::String::Concat(arr->GetValue( i+1),VALUEEND));
			}
			}
			
			return str;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "Results2Str");
	//LogMessage("","");
}

		}

/***********************************************************************************************/
//Function to convert Opencv Mat to Bitmap
/***********************************************************************************************/
public:static IPOErrors ImageProc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output,Stack_Section ID ){

try{
	
	if((ID>=Enum_BinaryThreshold)&&ID<=(Enum_BinaryThreshold+MAXSTACKIPO))
	BinaryThreshold(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_RGBThreshold)&&ID<=(Enum_RGBThreshold+MAXSTACKIPO))
	RGBThreshold(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_Crop)&&ID<=(Enum_Crop+MAXSTACKIPO))
	Crop(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_RGBPercentage)&&ID<=(Enum_RGBPercentage+MAXSTACKIPO))
	RGBPercentage(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_BWPercentage)&&ID<=(Enum_BWPercentage+MAXSTACKIPO))
	BWPercentage(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_Edges)&&ID<=(Enum_Edges+MAXSTACKIPO))
	CannyEdge(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_BackgroundSubstraction)&&ID<=(Enum_BackgroundSubstraction+MAXSTACKIPO))
	MogBackgroundSubstraction(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_Brightness)&&ID<=(Enum_Brightness+MAXSTACKIPO))
	AdjustBrightness(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_Contrast)&&ID<=(Enum_Contrast+MAXSTACKIPO))
	AdjustContrast(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_Saturation)&&ID<=(Enum_Saturation+MAXSTACKIPO))
	AdjustSaturation(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_CounterSearch)&&ID<=(Enum_CounterSearch+MAXSTACKIPO))
	FindContours(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_IMCalculator)&&ID<=(Enum_IMCalculator+MAXSTACKIPO))
	IMCalculateFunc(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_BoundingShape)&&ID<=(Enum_BoundingShape+MAXSTACKIPO))
	BoundingShapeFunc(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_ColorCNV)&&ID<=(Enum_ColorCNV+MAXSTACKIPO))
	ConversionFunc(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_AreaThreshold)&&ID<=(Enum_AreaThreshold+MAXSTACKIPO))
	AreaThresFunc(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_ParameterThreshold)&&ID<=(Enum_ParameterThreshold+MAXSTACKIPO))
	ParamThresFunc(Input, Parameters, ExtraResults, Output);	
	else if((ID>=Enum_AVGBrightness)&&ID<=(Enum_AVGBrightness+MAXSTACKIPO))
	AvgBrightnessFunc(Input, Parameters, ExtraResults, Output);	
	else if((ID>=Enum_AVGRGB)&&ID<=(Enum_AVGRGB+MAXSTACKIPO))
	AvgRGBFunc(Input, Parameters, ExtraResults, Output);	
	else if((ID>=Enum_Luma)&&ID<=(Enum_Luma+MAXSTACKIPO))
	LumaFunc(Input, Parameters, ExtraResults, Output);	
	else if((ID>=Enum_AVGLightness)&&ID<=(Enum_AVGLightness+MAXSTACKIPO))
	AvgLightnessFunc(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_AVGIntensity)&&ID<=(Enum_AVGIntensity+MAXSTACKIPO))
	AvgIntensityFunc(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_DePixalate)&&ID<=(Enum_DePixalate+MAXSTACKIPO))
	DePixalateFunc(Input, Parameters, ExtraResults, Output);
	else if((ID>=Enum_Counter)&&ID<=(Enum_Counter+MAXSTACKIPO))
	CounterFunc(Input, Parameters, ExtraResults, Output);
	else
	LogMessage("Unexpected ID Detected","ImageProc");
	
	return Success;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "ImageProc");
	//LogMessage("","");
}	   
}
/***********************************************************************************************/
//Function to deep copy a bitmap image
/***********************************************************************************************/

private:static void DeepCopyBitmap(Bitmap^ &Im, Int32 widthStep)
{
try{
	BitmapData^ bmDatasrc = Im->LockBits( System::Drawing::Rectangle( 0, 0, Im->Width, Im->Height) , System::Drawing::Imaging::ImageLockMode::ReadWrite, Im->PixelFormat );
	
	Bitmap^ tmp;
	tmp=gcnew Bitmap(Im->Width, Im->Height,Im->PixelFormat);
	BitmapData^ bmDatades = tmp->LockBits( System::Drawing::Rectangle( 0, 0, tmp->Width, tmp->Height) , System::Drawing::Imaging::ImageLockMode::ReadWrite, tmp->PixelFormat );
	
	if(Im->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed)
	memcpy((char*)bmDatades->Scan0.ToPointer(),(char*)bmDatasrc->Scan0.ToPointer(),Math::Abs(bmDatades->Stride) * Im->Height);
	else
	memcpy((char*)bmDatades->Scan0.ToPointer(),(char*)bmDatasrc->Scan0.ToPointer(),Math::Abs(bmDatades->Stride) * Im->Height);

	Im->UnlockBits(bmDatades);
	tmp->UnlockBits(bmDatasrc);

	Im=gcnew Bitmap(tmp);
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "DeepCopyBitmap");
	//LogMessage("","");
}
}

/**********************************************************************************************
	  Canny edge detection algorithm
**********************************************************************************************/

private:static IPOErrors CannyEdge(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,Out,tmp;
	bool tmprelease=false;
	//Taking input
	if(Input->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed)
	
	In=BitmapToMat(Input);
	else{
		tmp=BitmapToMat(Input);
		cvtColor(tmp, In, CV_BGR2GRAY);
		tmprelease=true;
	}

	//Reading parameters
	Int32 threshold1, threshold2;
	Int32::TryParse( ReadProperty("threshold1",Parameters),threshold1);
	Int32::TryParse( ReadProperty("threshold2",Parameters),threshold2);
	

	

	
	Canny(In,Out,threshold1,threshold2,3,false);
	
	
	
	
	Output=MatToBitmap(Out);
	
	//DeepCopyBitmap(Output);

	if(tmprelease)
		tmp.release();
	else
	In.release();

		
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "CannyEdge");
	//LogMessage("","");
}
}

/**********************************************************************************************
	  Mog Background substraction algorithm
**********************************************************************************************/

private:static IPOErrors MogBackgroundSubstraction(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp;
	bool tmprelease=false;
	//Taking input
	//if(Input->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed)
	
	In=BitmapToMat(Input);
	/*else{
		tmp=BitmapToMat(Input);
		cvtColor(tmp, In, CV_BGR2GRAY);
		tmprelease=true;
	}*/
/*******************************Process the In image******************************************/
	//Reading parameters
	Int32 learningRate;
	Int32::TryParse( ReadProperty("History",Parameters),learningRate);
	
#ifdef SCIENTIFIC

	Int32 History,nmixtures,backgroundRatio,noiseSigma;
	Int32::TryParse( ReadProperty("History",Parameters),History);
	Int32::TryParse( ReadProperty("nmixtures",Parameters),nmixtures);
	Int32::TryParse( ReadProperty("backgroundRatio",Parameters),backgroundRatio);
	Int32::TryParse( ReadProperty("noiseSigma",Parameters),noiseSigma);

	static BackgroundSubtractorMOG mog=BackgroundSubtractorMOG(History,nmixtures,backgroundRatio,noiseSigma);

#else

	static BackgroundSubtractorMOG mog=BackgroundSubtractorMOG();

#endif
	Mat foreground;
	Mat Out;
	mog(In,foreground,learningRate);

	In.copyTo(Out,foreground);
	

	
	
	
	
/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	
	//DeepCopyBitmap(Output);

	//if(tmprelease)
	//	tmp.release();
	//else
	In.release();

		
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "MogBackgroundSubstraction");
	//LogMessage("","");
}
}


		
/**********************************************************************************************
	  Function to Adjust Brightness of the image
**********************************************************************************************/

private:static IPOErrors AdjustBrightness(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	//Reading parameters
	Int32 Brightness;
	Int32::TryParse( ReadProperty("Value",Parameters),Brightness);
	

	if(In.channels()>1){
	Mat HSVImage;
	
	cvtColor(In,HSVImage,CV_BGR2HSV);
	for( int y = 0; y < HSVImage.rows; y++ ){
		for( int x = 0; x <HSVImage.cols; x++ ){
			HSVImage.at<Vec3b>(y,x)[2] = saturate_cast<uchar>( ( HSVImage.at<Vec3b>(y,x)[2] ) + Brightness ); 
		}
	}
	cvtColor(HSVImage,Out,CV_HSV2BGR);
	}
	else{
		Out=In;
		for( int y = 0; y < Out.rows; y++ ){
		for( int x = 0; x <Out.cols; x++ ){
			Out.at<uchar>(x,y) = saturate_cast<uchar>( ( Out.at<uchar>(x,y) ) + Brightness ); 
		}
	}
	}

	

/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	
	//DeepCopyBitmap(Output);

	
	In.release();

		
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "AdjustBrightness");
	//LogMessage("","");
}
}


			
/**********************************************************************************************
	  Calculator Function to process image
**********************************************************************************************/

private:static IPOErrors IMCalculateFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	//Reading parameters
	System::String^ Operation;
	Operation = ReadProperty("Operation",Parameters);
	Mat secondSrc;
	// To do parseSrc
	switch(In.channels() ){
	case 1:
	case 3: 
			
			if(In.channels()==3)
				secondSrc = Mat::zeros(In.rows, In.cols, CV_8UC3);
			else if (In.channels()==1)
				secondSrc = Mat::zeros(In.rows, In.cols, CV_8UC1);
		
	
	if(Operation == "Add") 	{
		cv::add(In,secondSrc,Out,noArray(),-1);
	}
	else if(Operation == "Sub") {
		cv::subtract(In,secondSrc,Out,noArray(),-1);
	}
	else if(Operation == "Bit And") {
		cv::bitwise_and(In,secondSrc,Out,noArray());

	}
	else if(Operation == "Bit Or") {
		cv::bitwise_or(In,secondSrc,Out,noArray());
	}
	else if(Operation == "Bit Xor") {
		cv::bitwise_xor(In,secondSrc,Out,noArray());
	}
	else if(Operation == "Bit Not") {
		cv::bitwise_not(In,Out,noArray());
	}

	break;

	default : break;
}


/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "IMCalculatorFunc");
	//LogMessage("","");
}
}
	
/**********************************************************************************************
	  Function to process bounding shape for the image
**********************************************************************************************/

private:static IPOErrors BoundingShapeFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	 
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	Mat dst = Mat::zeros(In.rows, In.cols, CV_8UC1);
	Mat gray;
	if(In.channels()>1)
		cvtColor(In, gray, CV_RGB2GRAY, 0 );
	else
		gray=In;
		


	//Reading parameters
	System::String^ Shape;
	Shape = ReadProperty("BoundingShape",Parameters);

	//Reading parameters
	vector<vector<cv::Point> > contours;
	vector<Vec4i> hierarchy;

	// Finds contours
	findContours(gray,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_NONE); 

	
	vector<vector<cv::Point> > contours_poly( contours.size() );
	if(Shape=="Rectangle") {
		
		vector<Rect> boundRect( contours.size() );

		for( unsigned int i = 0; i < contours.size(); i++ ) {
			boundRect[i] = boundingRect( Mat(contours_poly[i]) );
			rectangle( dst, boundRect[i].tl(), boundRect[i].br(), Scalar(255,0,0), 2, 8, 0 );

		}
	}else if(Shape=="Circle") {
	//	void minEnclosingCircle(InputArray points, Point2f& center, float& radius);
		 vector<Point2f>center( contours.size() );
		 vector<float>radius( contours.size() );
		 for( unsigned int i = 0; i < contours.size(); i++ ) {
			minEnclosingCircle( contours_poly[i], center[i], radius[i] );
			circle( dst, center[i], (int)radius[i], Scalar(255,0,0), 2, 8, 0 );

		 }
	}else if(Shape=="Elipse") {

		//RotatedRect fitEllipse(InputArray points)
		vector<RotatedRect> boundRotatedRect( contours.size() );
		for( unsigned int i = 0; i < contours.size(); i++ ) {
			boundRotatedRect[i] = fitEllipse(Mat(contours_poly[i]));
			ellipse(dst,boundRotatedRect[i],Scalar(255,0,0),1,8);
		}
	}
	

/**************************************************************************************/
	
	Output=MatToBitmap(dst);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	
				
/**********************************************************************************************
	  Function to convert image for the image
**********************************************************************************************/

private:static IPOErrors ConversionFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	
	//Reading parameters
	System::String^ Conversion;
	Conversion = ReadProperty("ColorCNV",Parameters);
	
	unsigned int conversion=0;
	
	if(Conversion=="RGB2GRAY")		conversion=CV_RGB2GRAY;
	if(Conversion=="BGR2Luv")		conversion=CV_BGR2Luv;
	if(Conversion=="BGR2XYZ")		conversion=CV_BGR2XYZ;
	if(Conversion=="RGB2XYZ")		conversion=CV_RGB2XYZ;
	if(Conversion=="XYZ2BGR")		conversion=CV_XYZ2BGR;
	if(Conversion=="XYZ2RGB")		conversion=CV_XYZ2RGB;
	if(Conversion=="BGR2YCrCb")		conversion=CV_BGR2YCrCb;
	if(Conversion=="RGB2YCrCb")		conversion=CV_RGB2YCrCb;
	if(Conversion=="YCrCb2BGR")		conversion=CV_YCrCb2BGR;
	if(Conversion=="YCrCb2RGB" )	conversion=CV_YCrCb2RGB;
	if(Conversion=="BGR2HSV")		conversion=CV_BGR2HSV;
	if(Conversion=="RGB2HSV")		conversion=CV_RGB2HSV;
	if(Conversion=="HSV2BGR")		conversion=CV_HSV2BGR;
	if(Conversion=="HSV2RGB")		conversion=CV_HSV2RGB;
	if(Conversion=="BGR2HLS")		conversion=CV_BGR2HLS;
	if(Conversion=="RGB2HLS")		conversion=CV_RGB2HLS;
	if(Conversion=="HLS2BGR")		conversion=CV_HLS2BGR;
	if(Conversion=="HLS2RGB")		conversion=CV_HLS2RGB;
	if(Conversion=="BGR2Lab")		conversion=CV_BGR2Lab;
	if(Conversion=="RGB2Lab")		conversion=CV_RGB2Lab;
	if(Conversion=="Lab2BGR")		conversion=CV_Lab2BGR;
	if(Conversion=="Lab2RGB")		conversion=CV_Lab2RGB;
	if(Conversion=="BGR2Luv")		conversion=CV_BGR2Luv;
	if(Conversion=="RGB2Luv")		conversion=CV_RGB2Luv;
	if(Conversion=="Luv2BGR")		conversion=CV_Luv2BGR;
	if(Conversion=="Luv2RGB")		conversion=CV_Luv2RGB;

	cvtColor(In, Out, conversion, 0 );

/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	


/**********************************************************************************************
	  Function to extract the image above the marked area threshold 
**********************************************************************************************/

private:static IPOErrors AreaThresFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	//contourArea

	Int32 threshold;
	Int32::TryParse( ReadProperty("AreaThreshold",Parameters),threshold);
	

	Mat dst = Mat::zeros(In.rows, In.cols, CV_8UC1);

	

	//Reading parameters
	vector<vector<cv::Point> > contours;
	vector<Vec4i> hierarchy;

	// Finds contours
	findContours(In,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_NONE); 

	
	//vector<vector<cv::Point> > contours_poly( contours.size() );
	

		for( unsigned int i = 0; i < contours.size(); i++ ) {
			if( contourArea( contours[i] )>threshold)
			drawContours( dst, contours, i, Scalar(255,255,255), CV_FILLED, 8, hierarchy );
		}
	
/**************************************************************************************/
	
	Output=MatToBitmap(dst);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	

		
/**********************************************************************************************
	  Function to extract the image above the marked parameter threshold.
**********************************************************************************************/

private:static IPOErrors ParamThresFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	//arcLength

	Int32 threshold;
	Int32::TryParse( ReadProperty("PerimeterThreshold",Parameters),threshold);
	

	Mat dst = Mat::zeros(In.rows, In.cols, CV_8UC1);

	

	//Reading parameters
	vector<vector<cv::Point> > contours;
	vector<Vec4i> hierarchy;

	// Finds contours
	findContours(In,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_NONE); 

	
	//vector<vector<cv::Point> > contours_poly( contours.size() );
	

		for( unsigned int i = 0; i < contours.size(); i++ ) {
			if( arcLength( contours[i] ,1)>threshold)
			drawContours( dst, contours, i, Scalar(255,255,255), CV_FILLED, 8, hierarchy );
		}
	
/**************************************************************************************/
	
	Output=MatToBitmap(dst);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	



/**********************************************************************************************
	  Function to process average brightness of the image.
**********************************************************************************************/

private:static IPOErrors AvgBrightnessFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);
		
/*******************************Process the In image******************************************/
//1.     convert 3-ch image to HSV (cvtcolor)
//2.      take average (avg) of V channel
//3.     Out=In
//4.     Dump results to database
	
	Mat HSVimage = Mat::zeros(In.rows, In.cols, CV_8UC3);
	cvtColor(In, HSVimage, CV_RGB2HSV,0);
	Mat InChannels[4];
	split(HSVimage,InChannels);
	
	cv::Scalar average = mean(InChannels[2],noArray()); 
	array<System::String^>^ s ={"Average Brightness",System::String::Format("{0}",average(0))};
	ExtraResults=Results2Str(s);
	
	Out = In;
/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "AvgBrightnessFunc");
	//LogMessage("","");
}
}	

		
/**********************************************************************************************
	  Function to process average RGB of the image.
**********************************************************************************************/

private:static IPOErrors AvgRGBFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);
	
/*******************************Process the In image******************************************/
//1. only for 3 channel images
//2. split 3 channels to three arrays (splitchannel)
//3. take average of each channels (avg)
//4. dump to results
//5. Out=In
	if(In.channels()==3)
	{
		Mat InChannels[4];
		split(In,InChannels);
	
		cv::Scalar average1 = mean(InChannels[0],noArray());
		cv::Scalar average2 = mean(InChannels[1],noArray());
		cv::Scalar average3 = mean(InChannels[2],noArray());
		array<System::String^>^ s ={"Average Red",System::String::Format("{0}",average1(0)),"Average Green",System::String::Format("{0}",average2(0)),"Average Blue",System::String::Format("{0}",average3(0))};
		ExtraResults=Results2Str(s);
	}
	
	Out=In;
/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	

		
/**********************************************************************************************
	  Function to process average RGB of the image.
**********************************************************************************************/

private:static IPOErrors LumaFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

/*******************************Process the In image******************************************/
//1. only for 3 channel images
//2. apply histogramEq on image
//3. Luma = 0.2126 R + 0.7152 G + 0.0722 B 
//4. calculate for each pixel
//5. take average
//6. dump the results
//7. Out=In
	if(In.channels()==3)
	{
		Mat HistImage = Mat::zeros(In.rows, In.cols, CV_8UC3);
		Mat SingleChnImage = Mat::zeros(In.rows, In.cols, CV_32FC1);
		
		equalizeHist(In,HistImage);


		float Red=0,Blue=0,Green=0;
		float Luma;
		for(int i=0;i<In.rows;i++){
			for(int j=0;j<In.cols;j++){
				Scalar Intensity=HistImage.at<Vec3b>(i, j);
				Red=(Int32) Intensity.val[2];
				Green=(Int32) Intensity.val[1];
				Blue=(Int32) Intensity.val[0];
				Luma = 0.2126*Red + 0.7152*Green + 0.0722*Blue; 
				SingleChnImage.at<float>(i,j) = Luma;
			}
		}

		cv::Scalar average = mean(SingleChnImage,noArray()); 
		array<System::String^>^ s ={"Average Intensity",System::String::Format("{0}",average(0))};
		ExtraResults=Results2Str(s);

		Out=In;

	}
/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	
		
/**********************************************************************************************
	  Function to process average Lightness of the image.
**********************************************************************************************/

private:static IPOErrors AvgLightnessFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
//1. only for 3 channel images
//2. convert to HSL
//3. take average of L channel
//4. dump average L to results
//5. Out=In

	if(In.channels()==3)
	{	
		Mat HSLimage = Mat::zeros(In.rows, In.cols, CV_8UC3);
		cvtColor(In, HSLimage, CV_RGB2HLS,0);
		Mat InChannels[4];
		split(HSLimage,InChannels);
	
		cv::Scalar average = mean(InChannels[2],noArray()); 
		array<System::String^>^ s ={"Average Lightness",System::String::Format("{0}",average(0))};
		ExtraResults=Results2Str(s);
	}
	Out = In;
/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "AvgLightnessFunc");
	//LogMessage("","");
}
}	


		
		
/**********************************************************************************************
	  Function to process average Intensity of the image.
**********************************************************************************************/

private:static IPOErrors AvgIntensityFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
//1. only for 3 channel images
//2. I= (R+G+B)/3
//3. apply this to each pixel and take average of entire image
//4. dump average L to results
//5. Out=In
	if(In.channels()==3)
	{
		Mat SingleChnImage = Mat::zeros(In.rows, In.cols, CV_8UC1);
		float Red=0,Blue=0,Green=0;
		float avg;
		for(int i=0;i<In.rows;i++){
			for(int j=0;j<In.cols;j++){
				Scalar Intensity=In.at<Vec3b>(i, j);
				Red=(Int32) Intensity.val[2];
				Green=(Int32) Intensity.val[1];
				Blue=(Int32) Intensity.val[0];
				avg = (Red + Green + Blue)/3;
				SingleChnImage.at<float>(i,j) = avg;
			}
		}
		cv::Scalar average = mean(SingleChnImage,noArray()); 
		array<System::String^>^ s ={"Average Intensity",System::String::Format("{0}",average(0))};
		ExtraResults=Results2Str(s);
	}
	Out=In;
/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	
		

/**********************************************************************************************
	  Function to for PreProcessing kernel size.
**********************************************************************************************/

private:static IPOErrors DePixalateFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	//Size ksize;
/*******************************Process the In image******************************************/
	tmp = Mat::zeros(In.rows, In.cols, CV_8UC1);
	Mat dst = Mat::zeros(In.rows, In.cols, CV_8UC1);
	cvtColor(In, tmp, CV_BGR2GRAY);
	//getGaussianKernel(ksize,0,CV_32FC1);
	//getDerivKernels
	//GaussianBlur(tmp, dst, cv::Size(In.rows,In.cols), 0, 0);
	GaussianBlur(tmp, dst, cv::Size(In.cols,In.rows), 0, 0);
	//Smooth
	Out=dst;
/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BoundingShapeFunc");
	//LogMessage("","");
}
}	
/**********************************************************************************************
	  Function to Adjust Contrast of the image
**********************************************************************************************/

private:static IPOErrors AdjustContrast(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	//Reading parameters
	Double Contrast;
	Double::TryParse( ReadProperty("Value",Parameters),Contrast);
	

	if(In.channels()>1){
	Mat HSVImage;
	
	cvtColor(In,HSVImage,CV_BGR2HSV);
	/*for( int y = 0; y < HSVImage.rows; y++ ){
		for( int x = 0; x <HSVImage.cols; x++ ){
			HSVImage.at<Vec3b>(y,x)[2] = saturate_cast<uchar>(cv::Round( (double)HSVImage.at<Vec3b>(y,x)[2]  * (double)Contrast )); 
		}
	}
	cvtColor(HSVImage,Out,CV_HSV2BGR);*/
	In.convertTo(Out,-1,Contrast,0);
	}
	else{
		Out=In;
		for( int y = 0; y < Out.rows; y++ ){
		for( int x = 0; x <Out.cols; x++ ){
			Out.at<uchar>(x,y) = saturate_cast<uchar>( ( Out.at<uchar>(x,y) ) * Contrast ); 
		}
	}
	}

	

/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	
	//DeepCopyBitmap(Output);

	
	In.release();

		
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "AdjustContrast");
	//LogMessage("","");
}
}

	
/**********************************************************************************************
	  Function to Search Contour of the image
**********************************************************************************************/

private:static IPOErrors FindContours(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);
/*******************************Process the In image******************************************/
	//Reading parameters
	System::String^ Contour_Str;
	//int Contour;
	Contour_Str= ReadProperty("Contour",Parameters);
	
	//"All","OnlyExternal", "OnlyInternal"
	Mat GRAYImage;
	if(In.channels()>1){
		cvtColor(In,GRAYImage,CV_BGR2GRAY);
	}
	else{
		GRAYImage=In;
	}
	Mat BinaryImage;
	threshold(GRAYImage,BinaryImage,128,255,THRESH_BINARY);
	
	vector<vector<cv::Point> > contours;
	vector<Vec4i> hierarchy;
	findContours( BinaryImage, contours, hierarchy,
	CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
// iterate through all the top-level contours,
// draw each connected component with its own random color

	int level= (Contour_Str=="All")?level=2:(Contour_Str=="OnlyExternal")?level=0:(Contour_Str=="OnlyInternal")?level=1:0;
	
	int idx = 0;
	Out = Mat::zeros(In.rows, In.cols, CV_8UC3);
	for( ; idx >= 0; idx = hierarchy[idx][0] )
	{
		
		Scalar color( rand()&255, rand()&255, rand()&255 );
		drawContours(Out,contours,idx,color,CV_FILLED,8,hierarchy,level);
		//drawContours( Out, contours, idx, color, CV_FILLED, 8, hierarchy );
	}
/**************************************************************************************/
	Output=MatToBitmap(Out);
	In.release();
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "AdjustContrast");
	//LogMessage("","");
}
}

		
/**********************************************************************************************
	  Function to Search Contour of the image
**********************************************************************************************/

private:static IPOErrors CounterFunc(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
	try{
		Mat In,tmp,Out;
		bool tmprelease=false;
		//Taking input
		In=BitmapToMat(Input);	
/*******************************Process the In image******************************************/
		Mat gray;
		if(In.channels()>1)
			cvtColor(In, gray, CV_RGB2GRAY, 0 );
		vector<vector<cv::Point> > contours;
		vector<Vec4i> hierarchy;
		cv::findContours( gray, contours, hierarchy,	CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE );
		//array<System::String^>^ s ={"Pixel Counter",System::String::Format("{0}",contours.size())};		// remove size and give length count PDP
		array<System::String^>^ s ={"Pixel Counter",System::String::Format("{0}",contours.size())};
		ExtraResults=Results2Str(s);
		
		Out = In;
/**************************************************************************************/
		Output=MatToBitmap(Out);
		In.release();
	return Success;	
	} catch ( System::Exception^ ex ) {
		ThrowError(ex, "AdjustContrast");
		//LogMessage("","");
	}
}

		
/**********************************************************************************************
	  Function to Adjust Saturation of the image
**********************************************************************************************/

private:static IPOErrors AdjustSaturation(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,tmp,Out;
	bool tmprelease=false;
	//Taking input
	In=BitmapToMat(Input);

	
/*******************************Process the In image******************************************/
	//Reading parameters
	Int32 Saturation;
	Int32::TryParse( ReadProperty("Value",Parameters),Saturation);
	

	if(In.channels()>1){
	Mat HSVImage;
	
	cvtColor(In,HSVImage,CV_BGR2HSV);
	for( int y = 0; y < HSVImage.rows; y++ ){
		for( int x = 0; x <HSVImage.cols; x++ ){
			HSVImage.at<Vec3b>(y,x)[1] = saturate_cast<uchar>( ( HSVImage.at<Vec3b>(y,x)[1] ) + Saturation ); 
		}
	}
	cvtColor(HSVImage,Out,CV_HSV2BGR);
	}
	else{
		Out=In;
		
	}

	

/**************************************************************************************/
	
	Output=MatToBitmap(Out);
	
	//DeepCopyBitmap(Output);

	
	In.release();

		
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "AdjustSaturation");
	//LogMessage("","");
}
}



/**********************************************************************************************
	  Binary Thresholded output image.
	  White pixel percentage and Black Pixel Percentage as Extra output
**********************************************************************************************/

private:static IPOErrors BinaryThreshold(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,Out,tmp;
	bool tmprelease=false;
	//Taking input
	if(Input->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed)
	
	In=BitmapToMat(Input);
	else{
		tmp=BitmapToMat(Input);
		cvtColor(tmp, In, CV_BGR2GRAY);
		tmprelease=true;
	}
	//Reading parameters
	Int32 Threshold;
	Int32::TryParse( ReadProperty("Threshold",Parameters),Threshold);
	threshold(	In,Out,Threshold,255,THRESH_BINARY);
	
	/*
	Int32 White=0,Black=0;

	for(int i=0;i<Out.rows;i++){
		for(int j=0;j<Out.cols;j++){
			Scalar Intensity=Out.at<uchar>(i, j);
			if(Intensity.val[0]) 
				White++;
			else 
				Black++;
		}
	}


	float WhitePercentage = ((float)White/(float)(Out.rows*Out.cols)) * 100;
	float BlackPercentage = ((float)Black/(float)(Out.rows*Out.cols)) * 100;

	array<System::String^>^ s ={"White Pixel Percentage",System::String::Format("{0}",WhitePercentage),"Black Pixels Percentage",System::String::Format("{0}",BlackPercentage)};
	ExtraResults=Results2Str(s);
	*/
	Output=MatToBitmap(Out);
	
	//DeepCopyBitmap(Output);

	if(tmprelease)
		tmp.release();
	else
	In.release();

		
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BinaryThreshold");
	//LogMessage("","");
}
}

/**********************************************************************************************
	  BW Percentage .
	  White pixel percentage and Black Pixel Percentage as Extra output
**********************************************************************************************/

private:static IPOErrors BWPercentage(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,Out,tmp;
	bool tmprelease=false;
	//Taking input

	
	if(Input->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed)
	
	In=BitmapToMat(Input);
	else{
		tmp=BitmapToMat(Input);
		cvtColor(tmp, In, CV_BGR2GRAY);
		tmprelease=true;
	}
	//Reading parameters
	
	
	
	Int32 White=0,Black=0;

	for(int i=0;i<In.rows;i++){
		for(int j=0;j<In.cols;j++){
			Scalar Intensity=In.at<uchar>(i, j);
			if(Intensity.val[0]) 
				White++;
			else 
				Black++;
		}
	}


	float WhitePercentage = ((float)White/(float)(In.rows*In.cols)) * 100;
	float BlackPercentage = ((float)Black/(float)(In.rows*In.cols)) * 100;

	array<System::String^>^ s ={"White Pixel Percentage",System::String::Format("{0}",WhitePercentage),"Black Pixels Percentage",System::String::Format("{0}",BlackPercentage)};
	ExtraResults=Results2Str(s);
	
	//DeepCopyBitmap(Output);

	if(tmprelease)
		tmp.release();
	else
	In.release();

	Output=Input;

		
return Success;	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BinaryThreshold");
	//LogMessage("","");
}
}

/**********************************************************************************************
	  Output: Each layer will be thresholded using the values specified.
	  Amount of blue, green and red in the thresholded image
	  Kind : PreProcessing
			  
**********************************************************************************************/

private:static IPOErrors RGBThreshold(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,Out,tmp;
	bool SingleCh=false;
	//Taking input

	if(Input->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed)
	{
		tmp=BitmapToMat(Input);
		cvtColor(tmp, In, CV_GRAY2BGR);
		SingleCh=true;
	}
	else
	In=BitmapToMat(Input);
	
	

	//Reading parameters
	Int32 RThr,GThr,BThr;
	Int32::TryParse( ReadProperty("R",Parameters),RThr);
	Int32::TryParse( ReadProperty("G",Parameters),GThr);
	Int32::TryParse( ReadProperty("B",Parameters),BThr);

	//const Mat a(In.cols,In.rows, CV_8UC1);
	//const Mat b(In.cols,In.rows, CV_8UC1);
	//const Mat c(In.cols,In.rows, CV_8UC1);
	

	
	//vector <Mat> OutChannels;
	//OutChannels.resize(4);
	//InChannels.resize(3);
	//vector <Mat> InChannels;
	//array <Mat> InChannels
	Mat InChannels[4];
	Mat OutChannels[4];
	split(In,InChannels);
	array <int>^Thrs={BThr,GThr,RThr};
	
	unsigned int  ChN=0;
	while(ChN<3){
	threshold(	InChannels[ChN],OutChannels[ChN],Thrs[ChN],255,THRESH_BINARY);

    ChN++;
	}
	merge(OutChannels,3,Out);
	/*
	
	float Red=0,Blue=0,Green=0;

	for(int i=0;i<Out.rows;i++){

		for(int j=0;j<Out.cols;j++){
			Scalar Intensity=Out.at<Vec3b>(i, j);
			Red+=(Int32) Intensity.val[2];
			Green+=(Int32) Intensity.val[1];
			Blue+=(Int32) Intensity.val[0];
			
		}
	}
	float Total=(Blue+Red+Green);
	Blue=(Blue*100)/Total;
	Red=(Red*100)/Total;
	Green=(Green*100)/Total;
	*/
//	array<System::String^>^ s ={"Red Pixel Percentage",System::String::Format("{0}",Red),"Green Pixels Percentage",System::String::Format("{0}",Green),"Blue Pixels Percentage",System::String::Format("{0}",Blue)};
	//ExtraResults=Results2Str(s);
	

	if(SingleCh){
		cvtColor(Out, tmp, CV_BGR2GRAY);
		Output=MatToBitmap(tmp);
		tmp.release();
	}
	else{
		Output=MatToBitmap(Out);
	//DeepCopyBitmap(Output);
	In.release();
	}
	
	return Success;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "RGBThreshold");
	//LogMessage("","");
}
}

/**********************************************************************************************
	  Output: Each color percentage in the image would be calculated and return
	  Kind : Parameter Measurement
			  
**********************************************************************************************/

private:static IPOErrors RGBPercentage(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output){
try{
	Mat In,Out,tmp;
	bool SingleCh=false;
	//Taking input

	if(Input->PixelFormat == System::Drawing::Imaging::PixelFormat::Format8bppIndexed)
	{
		tmp=BitmapToMat(Input);
		cvtColor(tmp, In, CV_GRAY2BGR);
		SingleCh=true;
	}
	else
	In=BitmapToMat(Input);
	
	float Red=0,Blue=0,Green=0;

	for(int i=0;i<In.rows;i++){

		for(int j=0;j<In.cols;j++){
			Scalar Intensity=In.at<Vec3b>(i, j);
			Red+=(Int32) Intensity.val[2];
			Green+=(Int32) Intensity.val[1];
			Blue+=(Int32) Intensity.val[0];
			
		}
	}
	float Total=(Blue+Red+Green);
	Blue=(Blue*100)/Total;
	Red=(Red*100)/Total;
	Green=(Green*100)/Total;
	array<System::String^>^ s ={"Red Pixel Percentage",System::String::Format("{0}",Red),"Green Pixels Percentage",System::String::Format("{0}",Green),"Blue Pixels Percentage",System::String::Format("{0}",Blue)};
	ExtraResults=Results2Str(s);

	if(SingleCh){
		tmp.release();
	}
	else{
		In.release();
	}
	Output=Input;
	return Success;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "RGBThreshold");
	//LogMessage("","");
}
}
/**********************************************************************************************
	 crop TopThird of the image
**********************************************************************************************/

/*
public: static Bitmap^ TopThird(Bitmap^ Image)
{
try{
	Bitmap^ Output;
	if(Image){
	Mat In,Out,tmp;
	In=BitmapToMat(Image);
	tmp=In(Rect(0,0,In.cols/2,In.rows));
	Out=tmp.clone();
	Output=MatToBitmap(Out);
	In.release();
	}
	return Output;
	
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "TopThird");
	//LogMessage("","");
}

}*/


/**********************************************************************************************
	  Crop right half of the image
**********************************************************************************************/
		/*
public: static Bitmap^ BottomTwoThird(Bitmap^ Image)
{
try{
	Bitmap^ Output;
	if(Image){
	Mat In,Out,tmp;
	In=BitmapToMat(Image);
	tmp=In(Rect(In.cols/2,0,In.cols/2,In.rows));
	Out=tmp.clone();
	Output=MatToBitmap(Out);
	In.release();
	}
	return Output;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BottomTwoThird");
	//LogMessage("","");
}

}*/

/**********************************************************************************************
	  Crop Top Third of the image
**********************************************************************************************/
public: static Bitmap^ TopThird(Bitmap^ Image)
{
try{
	Bitmap^ Output;
	if(Image){
	Mat In,Out,tmp;
	In=BitmapToMat(Image);
	tmp=In(Rect(0,0,In.cols,In.rows/3));
	Out=tmp.clone();
	Output=MatToBitmap(Out);
	In.release();
	}
	return Output;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "TopThird");
	//LogMessage("","");
}

}
/**********************************************************************************************
	  Crop right half of the image
**********************************************************************************************/
public: static Bitmap^ BottomTwoThird(Bitmap^ Image)
{
try{
	Bitmap^ Output;
	if(Image){
	Mat In,Out,tmp;
	In=BitmapToMat(Image);
	tmp=In(Rect(0,In.rows/3,In.cols,(int)(((float)In.rows*(float)2)/(float)3)));
	Out=tmp.clone();
	Output=MatToBitmap(Out);
	In.release();
	}
	return Output;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "BottomTwoThird");
	//LogMessage("","");
}

}
/**********************************************************************************************
	 crop a custom portion of the image
**********************************************************************************************/
public: static Bitmap^ SliceCustomPortion(Bitmap^ Image,System::Drawing::Point A,System::Drawing::Point B,System::Drawing::Point C,System::Drawing::Point D)
{
try{
	Bitmap^ Output;
	if(Image){
	Mat In,tmp;
	In=BitmapToMat(Image);

	//converting percentages to actual pixel value.
	//converting percentages to actual pixel value.
	A.X=(int)(((float)A.X/(float)100)*(float)In.cols);
	B.X=(int)(((float)B.X/(float)100)*(float)In.cols);
	C.X=(int)(((float)C.X/(float)100)*(float)In.cols);
	D.X=(int)(((float)D.X/(float)100)*(float)In.cols);

	A.Y=(int)(((float)A.Y/(float)100)*(float)In.rows);
	B.Y=(int)(((float)B.Y/(float)100)*(float)In.rows);
	C.Y=(int)(((float)C.Y/(float)100)*(float)In.rows);
	D.Y=(int)(((float)D.Y/(float)100)*(float)In.rows);

	int biggestX=0;
	int biggestY=0;

	biggestX=(A.X>B.X)?A.X:B.X;
	biggestX=(biggestX>C.X)?biggestX:C.X;
	biggestX=(biggestX>D.X)?biggestX:D.X;

	biggestY=(A.Y>B.Y)?A.Y:B.Y;
	biggestY=(biggestY>C.Y)?biggestY:C.Y;
	biggestY=(biggestY>D.Y)?biggestY:D.Y;
	cv::Rect rect=cv::Rect( A.X,A.Y,biggestX-A.X,biggestY-A.Y);
	tmp=In(rect);
	
	Mat Out = tmp.clone();
	Output=MatToBitmap(Out);
	In.release();
	}
	return Output;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "SliceCustomPortion");
	//LogMessage("","");
}

}
/**********************************************************************************************
	 Draw the custom selected portion of the image
**********************************************************************************************/
public: static Bitmap^ DrawCustomPortion(Bitmap^ Image,System::Drawing::Point A,System::Drawing::Point B,System::Drawing::Point C,System::Drawing::Point D)
{
try{
	Bitmap^ Output;
	if(Image){
	Mat In,Out;
	In=BitmapToMat(Image);

	//converting percentages to actual pixel value.
	A.X=(int)(((float)A.X/(float)100)*(float)In.cols);
	B.X=(int)(((float)B.X/(float)100)*(float)In.cols);
	C.X=(int)(((float)C.X/(float)100)*(float)In.cols);
	D.X=(int)(((float)D.X/(float)100)*(float)In.cols);

	A.Y=(int)(((float)A.Y/(float)100)*(float)In.rows);
	B.Y=(int)(((float)B.Y/(float)100)*(float)In.rows);
	C.Y=(int)(((float)C.Y/(float)100)*(float)In.rows);
	D.Y=(int)(((float)D.Y/(float)100)*(float)In.rows);

	int biggestX=0;
	int biggestY=0;

	biggestX=(A.X>B.X)?A.X:B.X;
	biggestX=(biggestX>C.X)?biggestX:C.X;
	biggestX=(biggestX>D.X)?biggestX:D.X;

	biggestY=(A.Y>B.Y)?A.Y:B.Y;
	biggestY=(biggestY>C.Y)?biggestY:C.Y;
	biggestY=(biggestY>D.Y)?biggestY:D.Y;

	//rectangle(In, cv::Point(A.X,A.Y) , cv::Point(biggestX,biggestY),  Scalar(0,0,0),2, 8,0);

	cv::Rect rect=cv::Rect( A.X,A.Y,biggestX-A.X,biggestY-A.Y);

	Mat tmp(In.rows, In.cols, CV_8UC3,Scalar(0,0,0));
	rectangle(tmp, cv::Point(A.X,A.Y) , cv::Point(biggestX,biggestY),  Scalar(255,255,255),-1, 8,0);
	//tmp=In(rect);
	bitwise_and(In,tmp,In);

	//Out=In(Rect(0,In->cols/2,In->cols/2,In->rows));
	line(In,cv::Point(A.X,A.Y),cv::Point(B.X,B.Y), Scalar(255,0,255),10, 8, 0);
	line(In,cv::Point(B.X,B.Y),cv::Point(C.X,C.Y), Scalar(255,0,255),10, 8, 0);
	line(In,cv::Point(C.X,C.Y),cv::Point(D.X,D.Y), Scalar(255,0,255),10, 8, 0);
	line(In,cv::Point(D.X,D.Y),cv::Point(A.X,A.Y), Scalar(255,0,255),10, 8, 0);

		cv::string Astr=" A ";
		cv::string Bstr=" B ";
		cv::string Cstr=" C ";
		cv::string Dstr=" D" ;
		

	putText(In,Astr,cv::Point(A.X,A.Y),FONT_HERSHEY_SIMPLEX, 1, Scalar(255,0,0),2, 8,false );

	putText(In, Bstr,cv::Point(B.X,B.Y), FONT_HERSHEY_SIMPLEX, 1,  Scalar(255,0,0),2, 8,false );
	putText(In, Cstr,cv::Point(C.X,C.Y), FONT_HERSHEY_SIMPLEX, 1, Scalar(255,0,0),2, 8,false );
	putText(In, Dstr,cv::Point(D.X,D.Y), FONT_HERSHEY_SIMPLEX, 1,  Scalar(255,0,0),2, 8,false );

	
	Output=MatToBitmap(In);
	In.release();
	}
	return Output;
} catch ( System::Exception^ ex ) {
	ThrowError(ex, "DrawCustomPortion");
	//LogMessage("","");
}

}



public: static IPOErrors Crop(Bitmap^ Input, System::String^ Parameters, System::String^ &ExtraResults,Bitmap^ &Output)
{
try{
	//Taking input

	if(!Input)
		return NOImageErr;
Mat tmp=BitmapToMat(Input);


//Reading parameters
System::String^ Method=ReadProperty("Method",Parameters);


if(System::String::Compare(Method, "Whole")==0){
	Output=MatToBitmap(tmp);
}else if(System::String::Compare(Method, "TopThird")==0){
	Output=TopThird(Input);
}else if(System::String::Compare(Method, "BottomTwoThird")==0){
	Output=BottomTwoThird(Input);
}else if(System::String::Compare(Method, "Custom")==0){


System::Drawing::Point CornerA, CornerB,CornerC,CornerD;
{
	array <System::String^>^ delimiter = {"(",",",")"};
	array <System::String^>^ arr = (ReadProperty("CornerA",Parameters))->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
	if(arr->Length==2){
			Int32 Val1,Val2;
			Int32::TryParse(arr[0],Val1);
			Int32::TryParse(arr[1],Val2);
			CornerA = System::Drawing::Point(Val1,Val2);
			}
}
{
	array <System::String^>^ delimiter = {"(",",",")"};
	array <System::String^>^ arr = (ReadProperty("CornerB",Parameters))->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
	if(arr->Length==2){
			Int32 Val1,Val2;
			Int32::TryParse(arr[0],Val1);
			Int32::TryParse(arr[1],Val2);
			CornerB = System::Drawing::Point(Val1,Val2);
			}
}
{
	array <System::String^>^ delimiter = {"(",",",")"};
	array <System::String^>^ arr = (ReadProperty("CornerC",Parameters))->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
	if(arr->Length==2){
			Int32 Val1,Val2;
			Int32::TryParse(arr[0],Val1);
			Int32::TryParse(arr[1],Val2);
			CornerC = System::Drawing::Point(Val1,Val2);
			}
}
{
	array <System::String^>^ delimiter = {"(",",",")"};
	array <System::String^>^ arr = (ReadProperty("CornerD",Parameters))->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
	if(arr->Length==2){
			Int32 Val1,Val2;
			Int32::TryParse(arr[0],Val1);
			Int32::TryParse(arr[1],Val2);
			CornerD =System::Drawing::Point(Val1,Val2);
			}

}

Output=SliceCustomPortion(Input,CornerA,CornerB,CornerC,CornerD);
	

}
array<System::String^>^ s ={"Croping","Done"};
	ExtraResults=Results2Str(s);
tmp.release();
return Success;

} catch ( System::Exception^ ex ) {
	ThrowError(ex, "Crop");
	//LogMessage("","");
}

}

		};


