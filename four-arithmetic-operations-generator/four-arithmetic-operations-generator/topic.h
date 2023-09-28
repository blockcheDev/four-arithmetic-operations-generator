#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <istream> 
#include <stack>

#define EXERCISEFILE	"exercisefile.txt"
#define ANSWERFILE		"answerfile.txt"
#define GRADE			"grade.txt"
#define MAX_LENGTH		20000
using namespace std;

const int maxn = 100;

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef struct variable {
	int num_or_Symbol;		 //0������1�Ƿ���
	int Symbol = -1;		//    + - * % ( ) �ֱ��ʾΪ 0 1 2 3 4 5
	int numer;				//��������ִ�Ϊ����
	int Den = 1;			//��������ִ�Ϊ��ĸ
	int num;

	bool operator == (variable c) {
		return num_or_Symbol == c.num_or_Symbol && Symbol == c.Symbol && numer == c.numer && Den == c.Den && num == c.num;
	}
}var;

/**
 *  @name			Status Create(var* exp, int size)
 *	@description	���ɱ��ʽ����
 *	@param			exp		���ʽ����
 *					size	���ʽ����ֵ�Ĵ�С
 *					length	���ʽ�ṹ��ĳ���
 *	@return			ERROR  SUCCESS
 *  @notice			none
 */
Status Create(var** exp, int size, int* length);

/**
 *  @name			Status Calculation(var *exp, int size, var *result);
 *	@description	������ʽ����
 *	@param			exp		���ʽ����
 *					size	���ʽ����ֵ�Ĵ�С���Լ������������ֵ�Ĵ�С
 *					result	���ʽ�ķ���ֵ
 *					length	���ʽ�ṹ��ĳ���
 *	@return			ERROR  SUCCESS
 *  @notice			none
 */
Status Calculation(var* exp, int size, var* result, int length);

/**
 *  @name			void visit(var* expression, int length);
 *	@description	������ʽ
 *	@param			expression		���ʽ����
 *					length			���ʽ�ṹ��ĳ���
 *					num				��Ŀ���
 *	@return			none
 *  @notice			none
 */
void Visit(var* expression, int length, int num);

/**
 *  @name			void M_instructions(var* expression, int amount, int size);
 *	@description	mָ���ִ��
 *	@param			expression		���ʽ����
 *					amount			���ʽ����
 *					size			��������ȡֵ��Χ
 *	@return			none
 *  @notice			none
 */
void M_instructions(var** expression, int amount, int size, var* result);

/**
 *  @name			void Destrory(var** expression, var* result, int amount);
 *	@description	���ٷ�����ڴ�
 *	@param			expression		���ʽ����
 *					amount			���ʽ����
 *					result			�������Ľṹ������
 *	@return			none
 *  @notice			none
 */
void Destrory(var** expression, var* result, int amount);

/**
 *  @name			void Correction(int* save, char* instructions);
 *	@description	�ж϶Դ�
 *	@param			save			������ȷ����������
 *					answerfile		���ļ�·��
 *					exercisefile	��Ŀ�ļ�·��
 *	@return			none
 *  @notice			none
 */
void Correction(int* save, char* answerfile, char* exercisefile);


/**
 *  @name			Status Infix_to_Postfix(var* p, int size, var* Postfix, int length, int& postLen);
 *	@description	��׺���ʽת��׺���ʽ
 *	@param			p		�ṹ��������ʽ�ı��ʽ
 *					size	���ʽ����ֵ�Ĵ�С���Լ������������ֵ�Ĵ�С
 *					Postfix	���صĺ�׺���ʽ
 *					length	���ʽ p �ĳ���
 *					postLen	��׺���ʽ�ĳ���
 *	@return			ERROR SUCCESS
 *  @notice			none
 */
Status Infix_to_Postfix(var* p, int size, var* Postfix, int length, int& postLen);

/**
 *  @name			bool priority(var p);
 *	@description	��������������ȼ�
 *	@param			element	һ�������
 *	@return			���ȼ����� ()  +-  *�� �ֱ��Ӧ 0 1 2
 *  @notice			none
 */
int prio(var element);

/**
 *  @name			void preprocess(var &a, var &b);
 *	@description	����������ͨ��
 *	@param			a	������
 *					b	������
 *	@return			ERROR SUCCESS
 *  @notice			none
 */
void preprocess(var& a, var& b);

/**
 *  @name			Status calc(var* Postfix, int length, var &ans);
 *	@description	�����׺���ʽ��ֵ
 *	@param			Postfix		��׺���ʽ
 *					length		��׺���ʽ�ĳ���
 *					ans			���ʽ�ļ�����
 *	@return			ERROR SUCCESS
 *  @notice			none
 */
Status calc(var* Postfix, int length, var& ans);

/**
 *  @name			void display(var* a);
 *	@description	��ӡ����������
 *	@param			a	������
 *	@return
 *  @notice			none
 */
void display(var* a);

/**
 *  @name			Status operate(var a, var b, var oper, var &ret);
 *	@description	ִ�мӼ��˳��Ĳ������Խ�����л���
 *	@param			a		������
 *					b		������
 *					oper	�����
 *					ret		���
 *	@return			ERROR SUCCESS
 *  @notice			none
 */
Status operate(var a, var b, var oper, var& ret);

/**
 *  @name			Status get_Subexpression(var* Postfix, int length, var ans[][3], int& sta_size);
 *	@description	�ɺ�׺���ʽ ��ȡ ��׺�ӱ��ʽ
 *	@param			Postfix		��׺���ʽ
 *					length		��׺���ʽ�ĳ���
 *					ans			��׺�ӱ��ʽ
 *					sta_size	��׺�ӱ��ʽ�ĸ���
 *	@return			ERROR  SUCCESS
 *  @notice			none
 */
Status get_Subexpression(var* Postfix, int length, var ans[][3], int& sta_size);

/**
 *  @name			bool cmp(var a[], var b[]);
 *	@description	�ж�������׺�ӱ��ʽ�Ƿ�ȼ�
 *	@param			a		��׺�ӱ��ʽ1
 *					b		��׺�ӱ��ʽ2
 *	@return			ERROR  SUCCESS
 *  @notice			none
 */
bool cmp(var a[], var b[]);

/**
 *  @name			Status is_same(var* Question, int lenQuest, var* newQuestion, int lenNewQuest, int size);
 *	@description	�ж����������Ƿ�ȼ�
 *	@param			Question		ԭ����е�һ�����ʽ
 *					lenQuest		ԭ����е�һ�����ʽ�ĳ���
 *					newQuestion		�����ɵı��ʽ
 *					lenNewQuest		�����ɵı��ʽ�ĳ���
 *					size			���ʽ����ֵ�Ĵ�С���Լ������������ֵ�Ĵ�С
 *	@return			ERROR  SUCCESS
 *  @notice			none
 */
Status is_question_same(var* Question, int lenQuest, var* newQuestion, int lenNewQuest, int size);