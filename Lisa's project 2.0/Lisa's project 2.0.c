#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define NAME_LEN 10						//人名占用的bytes
#define DS_PARTS 6						//第一班含值班主管、一次鹽水、鹽酸、充填1、充填2、電槽分析
#define ES_PARTS 3						//第二班含值班主管、一次鹽水、鹽酸
#define NS_PARTS 3						//第三班含值班主管、一次鹽水、鹽酸
#define DO_PARTS 6						//輪休含值班主管、一次鹽水、鹽酸、充填1、充填2、電槽分析
#define LEAVE_PARTS 6					//假差含值班主管、一次鹽水、鹽酸、充填1、充填2、電槽分析

char all_week[7][5] = { "一","二","三" ,"四" ,"五" ,"六" ,"日" };

void calendar_default(int* calendar, int max);

int month_days(int year, int month);

//知道當年當月星期幾
int Zeller(int year, int month);

int main()
{
	char list[DS_PARTS+ ES_PARTS+ NS_PARTS+ DO_PARTS+ LEAVE_PARTS][31][NAME_LEN] = { 0 };
	int calendar[31] = { 0 };
	
	calendar_default(calendar, month_days(2026, 11));

	

	return 0;
}

void calendar_default(int* calendar, int max)
{
	int i;
	for (i = 1; i <= max; i++)
	{
		calendar[i - 1] = i;
	}
}

int month_days(int year, int month)
{
	int days = 0;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		days = 31;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		days = 30;
		break;
	}

	case 2:
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			days = 29;
		else
			days = 28;
		break;
	}

	default:
		return 0;
	}
	return days;
}

int Zeller(int year, int month)
{
	//q = 日期（day） m = 月份（3~14） K = 年份後兩位 J = 世紀
	int input_year = year;
	int input_month = month;

	int day = 1;
	int year_ar = 0;
	int century = 0;
	int Zeller_week = 0;
	int week = 0;
	if (month == 1 || month == 2)
	{
		month = month + 12;
		year = year - 1;
	}

	year_ar = year % 100;
	century = year / 100;
	Zeller_week = (day + (13 * (month + 1)) / 5 + year_ar + (year_ar / 4) + (century / 4) + (5 * century)) % 7;

	week = (Zeller_week + 5) % 7;

	return week;
}