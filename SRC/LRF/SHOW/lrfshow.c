//local include
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>
//#include <core.h>

#include "lrfshow.h"

//for debug

#define printLOG( msg ) fprintf(stderr,"mesg : %s\nfile : %s\nline : %d\n",msg,__FILE__,__LINE__)

//local define
#define PI 3.141592

CvSize ellipse;
CvPoint lo_pt1, lo_pt2, 
        la_pt1, la_pt2, 
     slant_pt1, slant_pt2,
     limit_pt1, limit_pt2,
     object_pt, center_pt;
unsigned char flg = 0;

IplImage *img[NUM_OF_LRF];     //IplImage for LRFShow

/*-----------------------------------------------------------
  Name     : SetLRFShow
  Argument : int id (LRF ID)
  Return   : 0 (success) other(failed) 
  About    : Setup for LRFShow 
  Version  : Ver 1.0
  Date     : 2014/05/25
  Author   : Ryodo Tanaka (Kyushu Institute of Technology)
------------------------------------------------------------*/
int SetLRFShow(const int id)
{
  int i;

  if(id == LRF_ALL_ID){
    for(i=0; i<NUM_OF_LRF; i++){
      img[i] = cvCreateImage(cvSize(LRF_WINDOW_SIZE,LRF_WINDOW_SIZE), IPL_DEPTH_8U, 3);
      if(!img[i]){
	printLOG("cvCreateImage() LRFShow");
	exit(1);
      }
    }
  }
  else {
    img[id] = cvCreateImage(cvSize(LRF_WINDOW_SIZE,LRF_WINDOW_SIZE), IPL_DEPTH_8U, 3);
    if(!img[id]){
      printLOG("cvCreateImage() LRFShow");
      exit(1);
    }

  }

  return 0;
}

/*-----------------------------------------------------------
  Name     : CloseLRFShow
  Argument : int id (LRF ID)
  Return   : 0 (success) other(failed) 
  About    : Free IplImage & Windows for LRFShow 
  Version  : Ver 1.0
  Date     : 2014/05/25
  Author   : Ryodo Tanaka (Kyushu Institute of Technology)
------------------------------------------------------------*/
void CloseLRFShow(const int id)
{
  int i;

  cvDestroyAllWindows();
  if(id == LRF_ALL_ID)
    for(i=0; i<NUM_OF_LRF; i++)
      cvReleaseImage(&img[i]);
  else  
    cvReleaseImage(&img[id]);
}

/*================================================================
  Name     : DrawFundamental
  Argument : IplImage* img : 描写する画像のIplImage構造体
  Return   : no return
  About    : x軸y軸を描写した後、
　　　　　　　-45〜225(deg)までの円弧を描写する
  Author   : Ryodo Tanaka
=================================================================*/
void DrawFundamental(IplImage* img)
{ 
  int i; 

  //原点座標
  center_pt.x = (int)(img -> width / 2);
  center_pt.y = (int)(img -> height / 2);
 
  //横軸 la_pt1->la_pt2
  la_pt1.x = 0;
  la_pt1.y = center_pt.y;
  la_pt2.x = (int)(img -> width);
  la_pt2.y = center_pt.y;
  cvLine(img,la_pt1,la_pt2,CV_RGB(250,250,250),2,8,0);

  //縦軸 lo_pt1->lo_pt2
  lo_pt1.x = center_pt.x;
  lo_pt1.y = 0;
  lo_pt2.x = center_pt.x;
  lo_pt2.y = (int)(img -> height);

  cvLine(img,lo_pt1,lo_pt2,CV_RGB(250,250,250),2,8,0);

  //斜め軸(+-30deg直線) center_pt->slant_pt1 and slant_pt2
  slant_pt1.x = 0;
  slant_pt1.y = (int)(img -> height);
  slant_pt2.x = (int)(img -> width); 
  slant_pt2.y = (int)(img -> height);

  cvLine(img,center_pt,slant_pt1,CV_RGB(250,250,250),2,8,0);
  cvLine(img,center_pt,slant_pt2,CV_RGB(250,250,250),2,8,0);

  /* //指定表示角度の線 center_pt->limit_pt1 and limit_pt2 */
  /* limit_pt1.x = center_pt.x + (int)((img -> width/2)*cos(120*PI/180)); */
  /* limit_pt1.y = center_pt.y - (int)((img -> height/2)*sin(120*PI/180)); */
  /* limit_pt2.x = center_pt.x + (int)((img -> width/2)*cos(60*PI/180)); */
  /* limit_pt2.y = center_pt.y - (int)((img -> height/2)*sin(60*PI/180)); */
 
  /* cvLine(img,center_pt,limit_pt1,CV_RGB(255,0,0),1,8,0); */
  /* cvLine(img,center_pt,limit_pt2,CV_RGB(255,0,0),1,8,0); */

  //FIRSTRANGE〜LASTRANGE(deg)までの円を40pix(=1m)おきに描写する
  for(i=0; i<5; i++){
    ellipse.width = (i+1)*(img->width/2)/5;
    ellipse.height = (i+1)*(img->height/2)/5;
    cvEllipse(img,center_pt,ellipse,0,-225,45,CV_RGB(250,250,250),1,8,0);
  }

}

/*=================================================================
  Name     : DrawObject
  Argument : IplImage* img   : 描写する画像のIplImage構造体
             long* lrf_data : LRFから返される物体までの距離(mm)
             int lrf_data_max : LRF取得データ数
                              の配列(0〜1024,0〜180deg)
  Return   : no return
  About    : LRFから送られてくる物体までの距離(〜5000mm)の
　　　　　　　情報を読み取り、ラインを引く。
  Author   : Ryodo Tanaka
=================================================================*/
void DrawObject(IplImage* img, const long lrf_data_max, const long *lrf_data,  const long max_dist)
{
 
  int i;
  int first_range;
  int last_range;

  //描写開始角度をステップに変換
  first_range = (int)((FIRST_RANGE+45)*(lrf_data_max-1)/270);
  last_range = (int)((LAST_RANGE+45)*(lrf_data_max-1)/270);

  //中心点
  center_pt.x = (int)(img -> width/2);
  center_pt.y = (int)(img -> height/2);
 
  //LRFの情報の描写
  for(i=first_range;i<last_range;i++){
    object_pt.x = center_pt.x + (int)(((img->width/2)*((double)lrf_data[i]/max_dist))*cos(3*PI/2*((double)i/(double)(lrf_data_max-1))-PI/4));
    object_pt.y = center_pt.y - (int)(((img->height/2)*((double)lrf_data[i]/max_dist))*sin(3*PI/2*((double)i/(double)(lrf_data_max-1))-PI/4));
  
    //15000mmより長いものは表示を打ち切る
    if(lrf_data[i] > max_dist){
      object_pt.x = center_pt.x;
      object_pt.y = center_pt.y;
    }
 
    cvLine(img,center_pt,object_pt,CV_RGB(147,166,251),1,8,0);
  }
}

/*=========================================================================================
  Name     : LRFShow
  Argument : IplImage* img : 表示に使うIplImage構造体
             char* window_name  : ウィンドウ名
             long* lrf_data : LRF取得データ関数でコピーして使う
　　　　　　　　　　　　　　　　 (オリジナルはそのまま)
             int lrf_data_max : LRF取得データ数
             int window_x : ウィンドウ表示位置x座標
             int window_y : ウィンドウ表示位置y座標
  Return   : no return
  About    : LRFより取得したデータをOpenCVを用いて表示する
  Author   : Ryodo Tanaka
=========================================================================================*/
int LRFShow(const int id, const long lrf_data_max, const long *lrf_data, const long max_dist, const char* lrf_window_name)
{

  cvZero(img[id]);
  DrawObject(img[id], lrf_data_max, lrf_data, max_dist);
  DrawFundamental(img[id]);
  cvShowImage(lrf_window_name,img[id]);
  
  return cvWaitKey(1);

}
