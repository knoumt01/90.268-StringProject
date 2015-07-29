// -- TString.cpp source file --
// Assignment #3 by Matt Knouff for 90.268 SU 2015

// Note to self: remember to check to make sure that use of cstring does not break reqs
#include "TString.h"
#include <cstring>

// TODO: -- Add remaining TString class member functions --
// empty ctor
TString::TString() {
	mpText = new char[1];
	mpText[0] = '\0';
	mLength = 0;
}

// default ctor
TString::TString(const char *pText) {
	if (0 == pText) {
		mpText = new char[1];
		mpText[0] = '\0';
		return;
	} else {
		mpText = new char[strlen(pText) + 1];
		strcpy(mpText, pText);
		mLength = strlen(mpText);
	}
}

// copy ctor
TString::TString(const TString& string) {
	if (0 == string.mpText) {
		mpText = new char[1];
		mpText[0] = '\0';
	}
	mpText = new char[strlen(string.mpText) + 1];
	strcpy(mpText, string.mpText);
	mLength = strlen(mpText);
}

// destr using delete operator
TString::~TString() {
	delete mpText; // delete char[]
	mpText = 0; // set mpText to 0
	mLength = 0; // set length to 0
}

// a length member fx returning current size (value in mLength var)
int TString::length() const {
	return mLength; // return length
}

// asChar() returning const char ptr
char* TString::asChar() const {
	return mpText;
}

// assign() accepting String obj param by const ref
void TString::assign(const TString& string) {
	if (mpText == string.mpText) {
		mLength = strlen(mpText);
		return;
	} else {
		delete mpText;
		mpText = new char[strlen(string.mpText) + 1];
		strcpy(mpText, string.mpText);
		mLength = strlen(mpText);
	}
}

// assign() accepting char ptr to char[]
void TString::assign(char* string) {
	if (mpText == string || string == '\0') {
		return;
	} else {
		delete mpText;
		mpText = new char[strlen(string) + 1];
		strcpy(mpText,string);
		mLength = strlen(mpText);
	}
}

// equals() accepting String obj param by const ref
bool TString::equals(const TString& string) const {
	if(!strcmp(this->mpText, string.mpText)) {
		return true;
	} else { return false; }
}

// 	int indexOf(char character) const; // an indexOf member fx accepting a char param
int TString::indexOf(const char character) const {
	int index;
	int endOfString = strlen(mpText);

	for(index = 0; index < endOfString; index++) {
		if(mpText[index] == character) { return index; }
	}
	
	return -1;
}