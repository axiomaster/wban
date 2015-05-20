#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"PHYHeadGen.h"
#include"PHYHeadCRC.h"
#include"BCH.h"
#include"spread.h"
#include"interleave.h"
#include"scrambler.h"
#include"complex.h"
#include"dpsk.h"
#include "PHYrx.h"
#include "PHYtx.h"
#include "PHY.h"

/*#define FrameNum 1   //仿真设定传输的帧数为1帧
#define PLCP_H_LEN 31
#define PLCP_H_SP_LEN (PLCP_H_LEN*PLCP_H_SpreadFactor)
#define PLCP_P_LEN 90
#define PLCP_LEN (PLCP_H_SP_LEN+PLCP_P_LEN) //扩频后的PLCP_header和PLCP Preamble的长度和
#define PSDU_SP_LEN (PSDU_LEN*PSDU_SpreadFactor)
#define PPDU_LEN (PLCP_LEN+PSDU_LEN)
#define PI 3.1415926*/
//#define uc unsigned char
//#define DEBUG
int PSDU_LEN;  //是个变化的量，因为传输来的PSDU frame body的长度不确定，表示的是psdu的位数（即01），但mac层传来的是padu的字节数（十六进制表示的）
int PSDU_Mod_len, PLCP_Mod_len;

void main()
{
	//int rate = 121;
	int rate = 971;
	uc length = 10;
//	uc length = 255;
	//uc PSDU_MAC[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x88, 0x99, 0x11, 0x22,0x33, 0x44, 0x55, 0x66,0x77, 0xFF,0xFF, 0xFF,0x11,0x11, 0x22, 0x33, 0x44, 0x55,0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x88, 0x99, 0x11, 0x22,0x33, 0x44, 0x55, 0x66,0x77, 0xFF,0xFF, 0xFF,0x11,0x11, 0x22, 0x33, 0x44, 0x55,0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x88, 0x99, 0x11, 0x22,0x33, 0x44, 0x55, 0x66,0x77, 0xFF,0xFF, 0xFF,0x11,0x11, 0x22, 0x33, 0x44, 0x55,0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xFF, 0xFF, 0xFF};
	int i;
//	unsigned char PSDU_MAC[255] = {0};
	unsigned char PSDU_MAC[10] = {1,2,3,4,5,6,7,8,9,0};
	for(i=0;i<length; i++)
	{
		PSDU_MAC[i]=i;
	}
	complex *PPDU_Mod;


	PPDU_Mod = PHYtx(PSDU_MAC, length, rate);

	//PHYrx(PPDU_Mod);

}
