#include <iostream>
#include <iterator>
#include <map>
#include <typeinfo>

using namespace std;

class Solution {
    private: map<char, int> romanIntegerConversion;
    private: string romanSymbol;
    private: int integerValue;

    public:
        int romanToInt(string s) {
			
            // Step-1: Separate each character form string
            // I- FIND Length of that string
            int lengthCount = 0;
            while(s[lengthCount]) { /* Iterate until String completes*/
//            	cout<<s[lengthCount]<<endl;
            	lengthCount++;
			}
			cout<<"\t\tlength of Roman String: "<<lengthCount<<endl;

			/* SET Array of input Roman Symbols */
			char RomanSymbolsArray[lengthCount];
			for(int i=0;i<lengthCount;i++) {
				RomanSymbolsArray[i] = s[i];
			}
			cout<<"\t\t";
			/* Showing Array of Inout Roman Symbols */
			for(int i=0;i<lengthCount;i++) {
				cout<<RomanSymbolsArray[i]<<" - ";
			}cout<<endl;
			
			int VIndex; /* Will hold V roman sybmol Index */
			int XIndex;
			char nextSymbol, previousSymbol, currentSymbol;
			int checkEnd = 0; 
			bool VSum, V_single_Subtract = false;
			bool X_single_Subtract = false;
			bool safeCheck = false;

			for(int i=0; i<lengthCount; i++) {
				/* STEP 3 - Verify Conventions by telling Program what Are Conventions/Rules that should follow    -    For SYMBOL   V   */	
				if(RomanSymbolsArray[i] == 'V') {
					VIndex = i;
					if(VIndex != 0) { /* means => V is not on 1st INDEX */
						previousSymbol = RomanSymbolsArray[i-1];
						if(i+1 != lengthCount) { /* Meaning, If that Index in Array exists */
							nextSymbol = RomanSymbolsArray[i+1];
						}
						else {
							nextSymbol = NULL;
						}
//						cout<<typeid(RomanSymbolsArray[i+1]).name()<<endl;;
						cout<<"\t\t----------\n\t\tprevious: "<<previousSymbol<<endl;
						cout<<"\t\tnext: "<<nextSymbol<<"\n\t\t------------"<<endl;
						if(nextSymbol == 'I') {
							if(previousSymbol != 'I') {
								cout<<" \t\tprevious Symbol I"<<endl;
								VSum += RomanSymbolsArray[i];
								VSum += nextSymbol;
							}
							else if(previousSymbol == 'I') { /* handles -> IVI Where I symbol should not be on Both sides */
								cout<<" * WRONG ROMAN Counting Entered. *"<<endl;
								checkEnd = 1;
								break; /* END Called */
							}
						}
						if(previousSymbol == 'I') {
							if(nextSymbol == NULL) {
								cout<<"\n\t\t no next index\n";
//								VSubtract += RomanSymbolsArray[i];
//								VSubtract += previousSymbol;
//								break;
								V_single_Subtract = true;
							}
							if(nextSymbol == 'I') { /*handles -> IV -> Where I Symbol should not be after that combination */
								cout<<" * WRONG ROMAN Counting Entered. *"<<endl;
								checkEnd = 1;
								break; /* END Called */
							}
							if(nextSymbol != 'I' && nextSymbol != NULL) { /* handles -> IV -> Where any Symbol should not be after that combination */
								cout<<" * WRONG ROMAN Counting Entered. *"<<endl;
								checkEnd = 1;
								break; /* END Called */
							}
						
						}
					}
					else if(VIndex == 0) { /* Means => V is in 1st Index */
						if(i+1 == lengthCount) { /* SAYS that it consist of only 1 V in complete Symbols Combination */
							safeCheck = true;
						}
						else if(i+2 == lengthCount) { /* means length is more (2) */
							if(RomanSymbolsArray[i+1] == 'I') {  /* SAYS that it consist of 'VI' in complete Symbols Combination */
								safeCheck = true;
							}
							else if(RomanSymbolsArray[i+1] != 'I') { /*  SAYS that if other than I exists Then WRONG */
								cout<<" * WRONG ROMAN Counting Entered. *"<<endl;
								checkEnd = 1;
								break; /* END Called */
							}
						}
						else if(i+3 == lengthCount) { /* means length is more more (3) */
							if(RomanSymbolsArray[i+2] == 'I') { /* SAYS that it consist of 'VII' in complete Symbols Combination */
								safeCheck = true;
							}
							else if(RomanSymbolsArray[i+2] != 'I') {
								cout<<" * WRONG ROMAN Counting Entered. *"<<endl;
								checkEnd = 1;
								break; /* END Called */
							}
						}
						else if(i+4 == lengthCount) { /* means length is more more more (4) */
							if(RomanSymbolsArray[i+3] == 'I') { /* SAYS that it consist of 'VIII' in complete Symbols Combination */
								safeCheck = true;
							}
							else if(RomanSymbolsArray[i+3] != 'I') {
								cout<<" * WRONG ROMAN Counting Entered. *"<<endl;
								checkEnd = 1;
								break; /* END Called */
							}
						}
//						if(RomanSymbolsArray[i+1])
//						safeCheck = true;
						/* tHEN IT is good to go */
					}
				}
				if(RomanSymbolsArray[i] == 'X') { /* Handles X Exists in Symbols Combination */
					XIndex = i;
					if(XIndex != 0) { /* means => IF X is not on Fiest Index */
						previousSymbol = RomanSymbolsArray[i-1];
						if(i+1 != lengthCount) { /* means => IF There i ANY Symbol after X */
							nextSymbol = RomanSymbolsArray[i+1];
						}
						else if(i+1 == lengthCount) {
							nextSymbol = NULL;
						}
						if(previousSymbol == 'I') {
							X_single_Subtract = true;
						}
						else if(previousSymbol == 'V') { /* Not Possible => VX = 5 + 10 WRONG*/
							cout<<" * WRONG ROMAN Counting Entered. *"<<endl;
							checkEnd = 1;
							break; /* END Called */
						}
						else { /* means => XX, CX, DX, LX, MX */
							safeCheck = true;
						}
					}
				}
				else {
					checkEnd == 0;
				}
			}
//			if(safeCheck == false) {
//				cout<<"\t\tHALF - SUM: "<<VSum<<" \n \t\tHALF - SUBTRACT: "<<VSubtract<<endl;
//			}
			
			if(checkEnd == 1) {
				cout<<"\t\tprogram End!_____"<<endl; /* END Executed */
			}
//			if(VSubtract == true)
			int convertedIntegerCharacters[lengthCount]; /* Array to store Converted romans*/

			/* Find what Each Character Means */

			map<char, int>::iterator itr;

			/* set Basic Conversions */
			setRomanIntegerBaseConversion();

		
//			int mapCount=0;
//			int RomanSymbolsArray[lengthCount];
//			for(itr = romanIntegerConversion.begin(); itr != romanIntegerConversion.end(); ++itr) {
//
//				romanSymbolsArray[mapCount] = itr->first;
//				/* STEP 3 - Verify Conventions by telling Program what Are Conventions/Rules that should follow */	
//				if(itr->first == 'V') {
//					VIndex = mapCount;
//					if(VIndex != 0) {
//						cout<<"----------\nprevious: "<<itr.prev()<<endl;
//						cout<<"next: "<<std::next(itr)<<"\n------------"<<endl;
//					}
//				}
//				mapCount++;
//			}
			/* Creating Integer ValuesArray for exact Input String */
			for(int i=0; i<lengthCount; i++) {
//				gatherCharcterAsString[i] = s[i];
//				cout<<s[i]<<"\t WITH TYPE \t"<<typeid(s[i]).name()<<endl; // S for string, i for int
//				cout<<"\n\t gatherCharcterAsString: "<<gatherCharcterAsString[i]<<"\t WITH TYPE \t"<<typeid(gatherCharcterAsString[i]).name()<<endl; // S for string, i for int
				for(itr = romanIntegerConversion.begin(); itr != romanIntegerConversion.end(); ++itr) {
//					cout << "\t" << itr->first << "\t" << itr->second<<"\t"<<typeid(itr->first).name()<< "\n";

					if(s[i] == itr->first) {
						convertedIntegerCharacters[i] = (*itr).second;
					}
				}
			}
			
//				gatherCharcterAsString[i] = s[i];
//				cout<<s[i]<<"\t WITH TYPE \t"<<typeid(s[i]).name()<<endl; // S for string, i for int
//				cout<<"\n\t gatherCharcterAsString: "<<gatherCharcterAsString[i]<<"\t WITH TYPE \t"<<typeid(gatherCharcterAsString[i]).name()<<endl; // S for string, i for int
//			int symbolIndex = 0;
//			for(itr = romanIntegerConversion.begin(); itr != romanIntegerConversion.end(); ++itr) {
//				convertedIntegerCharacters[symbolIndex] = (*itr).second;
//				symbolIndex++;
//			}
				
			if(checkEnd != 1){
				integerValue = 0;
				for(int j=0;j<lengthCount; j++) {	
					cout<<"\t\tConverted Integers: "<<convertedIntegerCharacters[j]<<endl;
					if(V_single_Subtract == true || X_single_Subtract == true) { /* vsUBTRACT Means only for V Situation */
						integerValue = convertedIntegerCharacters[j+1] - convertedIntegerCharacters[j];
						break;
					}
					else {
						integerValue += convertedIntegerCharacters[j];
					}
				}
				 return integerValue;
			}
			else {
				return 0;
			}
			
        }

    public: 
        void setRomanIntegerBaseConversion() {
            /* One Way of insert pairs */
				//            romanIntegerConversion["I"] = 1;
            /* 2nd way to insert pairs */
            romanIntegerConversion.insert(std::pair<char,int>('I', 1));
            romanIntegerConversion.insert(std::pair<char,int>('V', 5));
            romanIntegerConversion.insert(std::pair<char,int>('X', 10));
            romanIntegerConversion.insert(std::pair<char,int>('L', 50));
            romanIntegerConversion.insert(std::pair<char,int>('C', 100));
            romanIntegerConversion.insert(std::pair<char,int>('D', 500));
            romanIntegerConversion.insert(std::pair<char,int>('M', 1000));

        }
    public: 
        map<char,int> getRomanIntegerBaseConversion() {
            return romanIntegerConversion;
        }
    
};
int main() {
    string romanInput = "";
    int convertedIntegerOutput;
    Solution solution;
    
    cout<<"\n\t*******************************************************************************\n\n";
	int RunLimit = 0; int checkRunLimit = 0;
	cout<<"\t\tINPUT LIMIT to run this Code repeadlty After Output: ";
    cin>>RunLimit;

	do {
    	cout<<"\n\t\tPlease Input any Roman Symbol OR Combination of Symbols: ";
	    cin>>romanInput;
	    convertedIntegerOutput = solution.romanToInt(romanInput);
	    if(convertedIntegerOutput != 0) {
	    	cout<<"\n \t\t- Integer for '"<<romanInput<<"' is = "<<convertedIntegerOutput<<endl<<endl;
		}
		checkRunLimit++;
		if(checkRunLimit < RunLimit){
			cout<<"\n\t\t"<<checkRunLimit+1<<" times ----------------------------\n\n";
		}
	}
	while(checkRunLimit < RunLimit);
	cout<<"\n\n\t******************************************************************************\n";
   return 0; 
}
