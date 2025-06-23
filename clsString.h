/**
 * @file clsString.h
 * @brief A utility class for enhanced string manipulation and processing in C++.
 * @author Maro
 * @date June 2025
 *
 * This class provides a comprehensive set of string manipulation utilities including:
 * - Case conversion (upper/lower/invert)
 * - Word and character counting
 * - Trimming, splitting, and joining
 * - Punctuation handling
 * - Replacement operations (case-sensitive and insensitive)
 * 
 * Both static and instance-based methods are supported.
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
using namespace std;

/**
 * @class clsString
 * @brief A class that encapsulates various string operations.
 *
 * The class provides methods for:
 * - Changing letter cases
 * - Counting types of characters
 * - Splitting and joining strings
 * - Trimming spaces
 * - Replacing substrings
 * - Reversing words
 * - Vowel detection
*/

class clsString {
private:
    string _Value;

public:
    clsString() {
        _Value = "";
    }

    clsString(string Value) {
        _Value = Value;
    }

    void setValue(string Value) {
        _Value = Value;
    }

    string getValue() {
        return _Value;
    }

    static short Length(string Text) {
        return Text.length();
    }

    short Length() {
        return _Value.length();
    }

    // count the words in string with different delimiters
    static short CountWords(string Text, string Delim = " ") {
        short Counter = 0;
        short Position = 0;
        string Word = "";

        while((Position = Text.find(Delim)) != string::npos) {

            Word = Text.substr(0, Position);

            if(Word != "") {
                Counter++;
            }
            Text.erase(0, Position + Delim.length());
        }

        if (!Text.empty()) {
            Counter++;
        }
        return Counter;
    }

    short CountWords() {
        return CountWords(_Value);
    }

    // upper the first letter of each word
    static string UpperFirstLetterOfEachWord(string Text) {
    bool IsFirstLetter = true;
    for (short i = 0; i < Text.length(); ++i) {
        if (Text[i] != ' ' && IsFirstLetter) {
            Text[i] = toupper(Text[i]);
        }
        IsFirstLetter = (Text[i] == ' ')? true : false;
    }
    return Text;
    }

    void UpperFirstLetterOfEachWord(){
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    // Lower the first letter of each word
    static string LowerFirstLetterOfEachWord(string Text) {
        bool IsFirstLetter = true;
        for (int i = 0; i < Text.length(); i++) {
            if (Text[i] != ' ' && IsFirstLetter) {
                Text[i] = tolower(Text[i]);
            }
            IsFirstLetter = (Text[i] == ' ')? true : false;
        }
        return Text;
    }

    void LowerFirstLetterOfEachWord() {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }
    
    // Lower all the letters in the string
    static string LowerAllString(string Text) {
        for(char& TempChar : Text) {
            TempChar = tolower(TempChar);
        }
        return Text;
    }

    void LowerAllString() {
        _Value = LowerAllString(_Value);
    }
    
    // Upper all the letters in the string
    static string UpperAllString(string Text) {
        for (char& TempChar : Text) {
            TempChar = toupper(TempChar);
        }
        return Text;
    }

    void UpperAllString() {
        _Value = UpperAllString(_Value);
    }

    // Convert upper letter to lower, and Lower letter to upper
    static char InvertLetter(char Character) {
        return (isupper(Character))? tolower(Character) : toupper(Character);
    }

    // Convert upper letter to lower, and Lower letter to upper in string
    static string InvertAllString(string Text) {
        for (char& TempChar : Text) {
            TempChar = InvertLetter(TempChar);
        }
        return Text;
    }

    void InvertAllString() {
        _Value = InvertAllString(_Value);
    }

    enum enWhatToCount {Small = 0, Capital = 1, Punctuation = 3, Space = 4  , All = 5};

    // Count\ letter type in the string
    static short CountAll(string Text, enWhatToCount LetterType = enWhatToCount::All) {
        short counter = 0;
        if (LetterType == enWhatToCount::All) {
            return Text.length();
        }

        // for (int i = 0; i < Text.length(); i++) {
        for (char& TempChar : Text) {

            if (LetterType == enWhatToCount::Capital && isupper(TempChar)) {
                counter++;
            }
            else if (LetterType == enWhatToCount::Small && islower(TempChar)) {
                counter++;
            }
            else if (LetterType == enWhatToCount::Punctuation && ispunct(TempChar)) {
                counter++;
            }
            else if (LetterType == enWhatToCount::Space && isspace(TempChar)) {
                counter++;
            }
        }
        return counter;
    }

    static short CountCapitalLetters(string Text) {  
        short Counter = 0;
        for (char& TempChar : Text) {
            if (isupper(TempChar)) {
                Counter++;
            }
        }
        return Counter;
    }

    short CountCapitalLetters() {  
        return CountCapitalLetters(_Value);
    }

    static short CountSmallLetters(string Text) {
        short Counter = 0;
        for (char& TempChar : Text) {
            if (islower(TempChar)) {
                Counter++;
            }
        }
        return Counter;
    }

    short CountSmallLetters() {
        return CountSmallLetters(_Value);
    }

    static short CountPunctuation(string Text) {
        short Counter = 0;
        for(char& TempChar : Text) {
            if (ispunct(TempChar)) {
                Counter++;
            }
        }
        return Counter;
    }

    short CountPunctuation() {
        return CountPunctuation(_Value);
    }

    static short CountSpace(string Text) {
        short Counter = 0;
        for(char& TempChar : Text) {
            if (isspace(TempChar)) {
                Counter++;
            }
        }
        return Counter;
    }
    
    short CountSpace() {
        return CountSpace(_Value);
    }

    short CountAll(enWhatToCount LetterType = enWhatToCount::All) {
        return CountAll(_Value, LetterType);
    }

    // Count a specific char in a string with 2 options if only the match char or the same char upper and lower
    static short CountSpecificLetter(string Text, char Character, bool MatchCase = true) {
        short counter = 0;
        for (char& TempChar : Text) {
            if (MatchCase) {
                if (TempChar == Character) {
                    counter++;
                }
            }
            else {
                if (tolower(TempChar) == tolower(Character)) {
                    counter++;
                }
            }
        }
        return counter;
    }

    short CountSpecificLetter(char Character, bool MatchCase = true) {
        return CountSpecificLetter(_Value, Character, MatchCase);
    }

    // Check if the letter is vowel
    static bool IsLetterVowel(char Letter) {
        char Character = tolower(Letter);
        return (Character == 'a' || Character == 'e' || Character == 'i' || Character == 'o' || Character == 'u');
    }

    // Count vowel letter in string
    static short CountVowel(string Text) {
        short  counter = 0;
        for (char& TempChar : Text) {
            if (IsLetterVowel(TempChar)) {
                counter++;
            }
        }
        return counter;
    }

    short CountVowel() {
        return CountVowel(_Value);
    }

    // return the total words in string
    static short CountStringWords(string Text) {
        short Counter = 0;
        short Position = 0;
        string Space = " ";
        string word;

        while ((Position = Text.find(Space)) != string::npos) {
            word = Text.substr(0, Position);
            if (!word.empty()) {
            Counter++;
            }
            Text.erase(0, Position + Space.length());
        }
        if (!Text.empty()) {
            Counter++;
        }
        return Counter;
    }

    short CountStringWords() {
        return CountStringWords(_Value);
    }

    // Split string words and load them in vector.
    static vector<string> Split(string Text, string Delim) {
        vector<string> vString;
        short Position = 0;
        string Word;

        while ((Position = Text.find(Delim)) != string::npos) {
            Word = Text.substr(0, Position);

            if (!Word.empty()) {  
                vString.push_back(Word);
            }
            Text.erase(0, Position + Delim.length());
        }
        if (!Text.empty()) {
            vString.push_back(Text);
        }
        return vString;
    }
    
    vector<string> Split(string Delim) {
        return Split(_Value, Delim);
    }

    // trim from the left of the string
    static string TrimLeft(string Text) {
        for (int i = 0; i < Text.length(); i++) {
            if (Text[i] != ' ') {
                return (Text.substr(i, Text.length() - i));
            }
        }
        return Text;
    }

    void TrimLeft() {
        _Value = TrimLeft(_Value);
    }

    // trim from the right of the string
    static string TrimRight(string Text) {
        for (int i = Text.length() - 1; i >= 0; i--) {
            if (Text[i] != ' ') {
                return Text.substr(0, i);
            }
        }
        return Text;
    }

    void TrimRight() {
        _Value = TrimRight(_Value);
    }

    //  trim string from left and right
    static string Trim(string Text) {
        return TrimLeft(TrimRight(Text));
    }

    void Trim() {
        _Value = Trim(_Value);
    }

    // gather words in vector in a string
    static string JoinString(vector<string>& vString, string Delim) {
        string Text = "";
        for (string& word : vString) {
            Text += word + Delim;
        }
        return Text.substr(0, Text.length() - Delim.length());
    }

    // gather words in array in a string
    static string JoinString(string Arr[], short ArrLength, string Delim) {
        string Text = "";
        for (int i = 0; i < ArrLength; i++) {
            Text += Arr[i] + Delim;
        }
        return Text.substr(0, Text.length() - Delim.length());
    }

    // gather words in vector in a string in reverse
    static string ReverseWordsInString(string Text) {
        string UpdatedText = "";
        vector<string> vString = Split(Text, " ");
        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin()) {
            UpdatedText += *iter + " ";
            iter--;
        }
        return UpdatedText.substr(0, UpdatedText.length() - 1);
    }

    void ReverseWordsInString() {
        _Value = ReverseWordsInString(_Value);
    }

    // replace part in string with new one
    static string ReplaceWords(string Text, string OldString, string NewString) {
        short Position = Text.find(OldString);
        while (Position != string::npos) {
            Text = Text.replace(Position, OldString.length(), NewString);
            Position = Text.find(OldString);
        }
        return Text;
    }

    void ReplaceWords(string OldString, string NewString) {
        _Value = ReplaceWords(_Value, OldString, NewString);
    }

    // replace part in string with new one in any condition
    static string ReplaceWord(string Text, string OldString, string NewString, bool MatchCase = true) {
        vector<string> vString = Split(Text, " ");
        string UpdatedText = "";
        for (string& Word : vString) {
            if (MatchCase) {
                if (Word == OldString) {
                    Word = NewString;
                }
            }
            else {
                if (LowerAllString(Word) == LowerAllString(OldString)) {
                    Word = NewString;
                }
            }
        }
        return JoinString(vString, " ");
    }

    void ReplaceWord(string OldString, string NewString, bool MatchCase = true) {
        _Value = ReplaceWord(_Value, OldString, NewString, MatchCase);
    }

    // remove the puncituations from string
    static string RemovePunctuations(string Text) {
        string UpdatedText = "";
        for (char& TempChar : Text) {
            if (!ispunct(TempChar)) {
                UpdatedText += TempChar;
            }
        }
        return UpdatedText;
    }

    void RemovePunctuations() {
        _Value = RemovePunctuations(_Value);
    }

    /// @brief replace specific word or part in the string 
    /// @param OriginalString take the original string you want to edit
    /// @param StringToReplace take the old new part you want to update in the original string
    /// @param NewString take the new part you want to update in the original string
    /// @return the string after updating it
    static string Replace(string OriginalString, string StringToReplace, string NewString) {
        short Position = OriginalString.find(StringToReplace);
        while (Position != string::npos) {
            OriginalString = OriginalString.replace(Position, StringToReplace.length(), NewString);
            Position = OriginalString.find(StringToReplace);
        }
        return OriginalString;
    }
};