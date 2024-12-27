#ifndef BURM_H  // Check if BURM_H is not defined
#define BURM_H  // Define BURM_H

// The content of your header file goes here (variables, functions, etc.)



#include <string>
// #include <sstream>
// #include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int BurmFlag=0;
int SanFlag=1;

string ReplaceString(string subject, const string& search, const string& replace)
{
    size_t pos=0;
    while((pos=subject.find(search, pos)) != string::npos)
    {
        subject.replace(pos, search.length(),replace);
        pos+=1;
    }
    return subject;
}




string ReplaceStringRestricted(string subject, const string& search, const string& replace)
{
    size_t pos=0;
    char c;
    string replace_new=replace+"a";
    // replace_new=replace_new+m;
    //cout<<"here "<<subject<<endl;
    while((pos=subject.find(search, pos)) != string::npos)
    {   if(pos == subject.size()) break;
        //cout << subject<< " "<<pos <<" "<<subject.size()<< endl;
        if( subject.size() == pos + 3) c=subject.at(pos+2); else c=subject.at(pos+3);
        //CHANGE TO 3 IF EVERYTHING DOES NOT WORK
        if(c=='A' || c=='i' || c=='I' || c=='u' || c=='U' || c=='f' || c=='F' || c=='x' || c=='X' || c=='e' || c=='E' || c=='o' || c=='O')
            subject.replace(pos, search.length(),replace);
        else
            subject.replace(pos, search.length(),replace_new);
        pos+=1;
    }
    //cout<<"here21 "<<subject<<endl;
    return subject;
}


string toBurm(string s)
{ //Hin:-
    if(1){
        string vowel_dn[]={"","အ","ဣ","ဤ","ဥ","ဦ","ရ","ဧ","ऐ","ဩ","ဪ","","","း","",""};
        string vowel_dn_joiner[]={"","ာ","ိ","ဲ","ု","ူ","ြ","ီ","ေ","ံ","း","ျ"};
        string vowel_slp1[]={"a","A","i","I","u","U","f","e","E","o","O","Z","M","H","*","~"};
        //prev: string consonants_dn[] = {"က", "ခ", "ဂ", "ဃ", "င", "စ", "ဆ", "ဇ", "ဈ", "ဉ", "ည", "ဋ", "ဌ", "ဍ", "ဎ", "ဏ", "တ", "ထ", "ဒ", "ဓ", "န", "ပ", "ဖ", "ဗ", "ဘ", "မ", "ယ", "ရ", "လ", "ဝ", "သ", "ဟ", "ဠ", "အ", "ဢ", "ဣ", "ဤ", "ဥ", "ဦ", "ဧ", "ဨ", "ဩ", "ဪ", "၊", "။", "၌", "၍", "၎"};
        string consonants_dn[]={"က","ခ","ဂ","ဃ","င","စ","ဆ","ဇ","ဈ","ည","ဋ","ဌ","ဍ","ဎ","ဏ","တ","ထ","ဒ","ဓ","န","ပ","ဖ","ဗ","ဘ","မ","ယ","ရ","လ","ဝ","သ","ဿ","ဟ","ဠ"};
        string consonants_dn_halanta[] = {"က်","ခ်","ဂ်","ဃ်","င်","စ်","ဆ်","ဇ်","ဈ်","ည်","ဋ်","ဌ်","ဍ်","ဎ်","ဏ်","တ်","ထ်","ဒ်","ဓ်","န်","ပ်","ဖ်","ဗ်","ဘ်","မ်","ယ်","ရ်","လ်","ဝ်","သ်","ဿ်","ဟ်","ဠ်"};
        string consonants_slp1[]= {"ka","Ka","ga","Ga","Na","ca","Ca","ja","Ja","Ya","wa","Wa","qa","Qa","Ra","ta","Ta","da","Da","na","pa","Pa","ba","Ba","ma","ya","ra","la","va","sa","Sa","ha","&a"};
        //string consonants_slp1[] = {"ka", "Ka", "ga", "Ga", "Na", "sa", "Sa", "za", "Za", "n~a", "Ra", "t~~a", "t~a", "Da", "da", "na", "wa", "Wa", "qa", "Qa", "R~a", "pa", "Pa", "ba", "Ba", "ma", "ya", "y~a", "la", "va", "ta", "ha", "xa", "aa", "Aa", "ia", "Ia", "ua", "O~a", "E~a", "Ea", "Oa", "O~~a", ".a", "..a", "n~a", "y~~a", "l~a"};
        string no_dn[] = {"၀", "၁", "၂", "၃", "၄", "၅", "၆", "၇", "၈", "၉", "॥", "।", "–", "—"};
        // string consonants_slp1[]=          {"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","S","z","s","h","@","#","$","F","x","X","%","^","L","V","&"};
        //string consonants_slp1_halanta[] = {"k", "K", "g", "G", "N", "s", "S", "z", "Z", "n~", "R", "t~~", "t~", "D", "d", "n", "w", "W", "q", "Q", "R~", "p", "P", "b", "B", "m", "y", "y~", "l", "v", "t", "h", "x", "a", "A", "i", "I", "u", "O~", "E~", "E", "O", "O~~", ".", "..", "n~", "y~~", "l~"};
        string consonants_slp1_halanta[]={"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","s","S","h","&"};
        string no_slp1[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "||", "|", "-", "-"};
        string numbers_etc_dn[]={"၀", "၁", "၂", "၃", "၄", "၅", "၆", "၇", "၈", "၉","।","॥","॰","’","‘","”","“"};
        string numbers_eng[]={"0","1","2","3","4","5","6","7","8","9","|","||","0","'","'","''","''"};

        cout<<size(numbers_etc_dn);
        for(int i=0;i<33;i++)
        {
            s=ReplaceString(s,consonants_slp1_halanta[i],consonants_dn_halanta[i]);// k in ka becomes k with halanta and a
        }
        // cout << "here1 " << s <<endl;
        for(int i=0;i<12;i++)
        {
            s=ReplaceString(s,"်"+vowel_slp1[i],vowel_dn_joiner[i]);
        }

        // cout << "here2 " << s <<endl;
        for(int i=0;i<16;i++)
        {
            s=ReplaceString(s,vowel_slp1[i],vowel_dn[i]);
        }
        // cout << "here3 " << s <<endl;
        for(unsigned int i=0;i<(sizeof(numbers_etc_dn)/sizeof(numbers_etc_dn[0]));i++)
        {
            s=ReplaceString(s,numbers_eng[i],numbers_etc_dn[i]);
        }
        // cout << "here4 " << s <<endl;
        cout<<s<<endl;
    }

    return s;
}



string toslp1(string s)
{ //Hin:-
    // cout<<"inside slp1 function"<<endl;

    if (1){
        string vowel_dn[]={"","အ","ဣ","ဤ","ဥ","ဦ","ရ","ဧ","ऐ","ဩ","ဪ","","","း","",""};
        string vowel_dn_joiner[]={"","ာ","ိ","ဲ","ု","ူ","ြ","ီ","ေ","ံ","း","ျ"};
        string vowel_slp1[]={"a","A","i","I","u","U","f","e","E","o","O","Z","M","H","*","~"};
        //prev: string consonants_dn[] = {"က", "ခ", "ဂ", "ဃ", "င", "စ", "ဆ", "ဇ", "ဈ", "ဉ", "ည", "ဋ", "ဌ", "ဍ", "ဎ", "ဏ", "တ", "ထ", "ဒ", "ဓ", "န", "ပ", "ဖ", "ဗ", "ဘ", "မ", "ယ", "ရ", "လ", "ဝ", "သ", "ဟ", "ဠ", "အ", "ဢ", "ဣ", "ဤ", "ဥ", "ဦ", "ဧ", "ဨ", "ဩ", "ဪ", "၊", "။", "၌", "၍", "၎"};
        string consonants_dn[]={"က","ခ","ဂ","ဃ","င","စ","ဆ","ဇ","ဈ","ည","ဋ","ဌ","ဍ","ဎ","ဏ","တ","ထ","ဒ","ဓ","န","ပ","ဖ","ဗ","ဘ","မ","ယ","ရ","လ","ဝ","သ","ဿ","ဟ","ဠ"};
        string consonants_dn_halanta[] = {"က်","ခ်","ဂ်","ဃ်","င်","စ်","ဆ်","ဇ်","ဈ်","ည်","ဋ်","ဌ်","ဍ်","ဎ်","ဏ်","တ်","ထ်","ဒ်","ဓ်","န်","ပ်","ဖ်","ဗ်","ဘ်","မ်","ယ်","ရ်","လ်","ဝ်","သ်","ဿ်","ဟ်","ဠ်"};
        string consonants_slp1[]= {"ka","Ka","ga","Ga","Na","ca","Ca","ja","Ja","Ya","wa","Wa","qa","Qa","Ra","ta","Ta","da","Da","na","pa","Pa","ba","Ba","ma","ya","ra","la","va","sa","Sa","ha","&a"};
        //string consonants_slp1[] = {"ka", "Ka", "ga", "Ga", "Na", "sa", "Sa", "za", "Za", "n~a", "Ra", "t~~a", "t~a", "Da", "da", "na", "wa", "Wa", "qa", "Qa", "R~a", "pa", "Pa", "ba", "Ba", "ma", "ya", "y~a", "la", "va", "ta", "ha", "xa", "aa", "Aa", "ia", "Ia", "ua", "O~a", "E~a", "Ea", "Oa", "O~~a", ".a", "..a", "n~a", "y~~a", "l~a"};
        string no_dn[] = {"၀", "၁", "၂", "၃", "၄", "၅", "၆", "၇", "၈", "၉", "॥", "।", "–", "—"};
        // string consonants_slp1[]=          {"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","S","z","s","h","@","#","$","F","x","X","%","^","L","V","&"};
        //string consonants_slp1_halanta[] = {"k", "K", "g", "G", "N", "s", "S", "z", "Z", "n~", "R", "t~~", "t~", "D", "d", "n", "w", "W", "q", "Q", "R~", "p", "P", "b", "B", "m", "y", "y~", "l", "v", "t", "h", "x", "a", "A", "i", "I", "u", "O~", "E~", "E", "O", "O~~", ".", "..", "n~", "y~~", "l~"};
        string consonants_slp1_halanta[]={"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","s","S","h","&"};
        string no_slp1[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "||", "|", "-", "-"};
        string numbers_etc_dn[]={"၀", "၁", "၂", "၃", "၄", "၅", "၆", "၇", "၈", "၉","।","॥","॰","’","‘","”","“"};
        string numbers_eng[]={"0","1","2","3","4","5","6","7","8","9","|","||","0","'","'","''","''"};
        //         string vowel_dn[]={"အ","အ","ဣ","ဤ","ဥ","ဦ","ရ","ဧ","ऐ","ဩ","ဪ","း"};
        //  string vowel_dn_joiner[]={"ာ","ိ","ီ","ု","ူ","ြ","ေ","ဲ","ံ","့","ॉ"};
        // string vowel_slp1[]={"a","A","i","I","u","U","f","e","E","o","O","H"};
        //                string consonants_dn[]={"က","ခ","ဂ","ဃ","င","စ","ဆ","ဇ","ဈ","ည","ဋ","ဌ","ဍ","ဎ","ဏ","တ","ထ","ဒ","ဓ","န","ပ","ဖ","ဗ","ဘ","မ","ယ","ရ","လ","ဝ","ဿ","သ","ဟ","ဠ"};
        //         string consonants_dn_halanta[]={"က်","ခ်","ဂ်","ဃ်","င်","စ်","ဆ်","ဇ်","ဈ်","ည်","ဋ်","ဌ်","ဍ်","ဎ်","ဏ်","တ်","ထ်","ဒ်","ဓ်","န်","ပ်","ဖ်","ဗ်","ဘ်","မ်","ယ်","ရ်","လ်","ဝ်","ဿ်","သ်","ဟ်","ဠ်"};

        //         string consonants_slp1[]={"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","S","s","h","&"};
        //         string consonants_slp1_halanta[]={"ka","Ka","ga","Ga","Na","ca","Ca","ja","Ja","Ya","wa","Wa","qa","Qa","Ra","ta","Ta","da","Da","na","pa","Pa","ba","Ba","ma","ya","ra","la","va","Sa","sa","ha","&a"};
        //         string no_dn[]={"၀", "၁", "၂", "၃", "၄", "၅", "၆", "၇", "၈", "၉","।","॥","–","—"};
        //         string no_slp1[]={"0","1","2","3","4","5","6","7","8","9","|","||","-","-"};

        for(int i=0;i<33;i++)
        {
            s=ReplaceString(s,consonants_dn_halanta[i],consonants_slp1[i]);
        }
        // cout << "here1slp1 " << s <<endl;
        for(int i=0;i<12;i++)
        {
            s=ReplaceString(s,vowel_dn_joiner[i],vowel_slp1[i+1]);
        }
        // cout << "here2slp1 " << s <<endl;
        for(int i=0;i<16;i++)
        {

            s=ReplaceString(s,vowel_dn[i],vowel_slp1[i]);
        }
        // cout << "here3slp1 " << s <<endl;
        for(int i=0;i<33;i++)
        {
            s=ReplaceStringRestricted(s,consonants_dn[i],consonants_slp1[i]);
        }
        // cout << "here4slp1 " << s <<endl;
        for(int i=0;i<16;i++)
        {
            s=ReplaceString(s,no_dn[i],no_slp1[i]);
        }
        // cout << "here5slp1 " << s <<endl;
    }

    return s;
}



#endif  // End the include guard
