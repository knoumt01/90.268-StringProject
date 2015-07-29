 // -- TString.h header file --
// Assignment #3 for 90.268 SU 2015 by Matt Knouff

#ifndef _TSTRING_H    // only include once in a compilation unit
#define _TSTRING_H

class TString { // Prefix with 'T' for uniqueness
public:
	TString(); // empty ctor
	TString(const char *pText); // default ctor
	TString(const TString& string); // copy ctor
	~TString(); // destructor using c++ delete operator
	int length() const; // a length member fx returning current size
	char* asChar() const; // asChar member fx returning a const char pointer
	void assign(const TString& string); // assign member fx accepting a String obj param by const ref
	void assign(char* string); // assign member fx accepting a char ptr to char[]
	bool equals(const TString& string) const; // an equals member fx accepting a String obj param by const ref
	int indexOf(const char character) const; // an indexOf member fx accepting a char param
private:
	int mLength;  // length of char data (not including null byte)
	char *mpText; // pointer to dynamic char array in heap
};

#endif   // _TSTRING_H
