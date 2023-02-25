#pragma once

#define SIZE 255
#define STATE 3

typedef	enum { ctUnknown, ctLetter, ctDigit, ctSpecSymb } TChar;
typedef enum { FALSE, TRUE } TBool;

const int Transitions[STATE][sizeof(TChar)] =
{
	{0, 0, 0, 0},	// ќшибка
	{0, 2, 0, 2},	// ∆дЄм нижнее подчЄркивание/букву
	{0, 2, 2, 2}	// ∆дЄм нижнее подчЄркивание/число/букву
};

TBool IsFinalState[STATE] = { FALSE, FALSE, TRUE };


int	  getCharType(const char C);
TBool checkString(const char S[]);
TBool searchSubStrs(char S[]);
void  inputString(char S[]);
void  isCorrect(char S[]);