#include <iostream>
#include <iterator>
#include <map>
#include <typeinfo>

using namespace std;

class Solution {
    private: map<char, int> romanIntegerConversion;
    private: string romanSymbol;
    private: string integerSymbol;

    public:
        int romanToInt(string s) {

            // Step-1: Separate each character form string
            // I- FIND Length of that string
            int lengthCount = 0;
            while(s[lengthCount]) { /* Iterate until String completes*/
//            	cout<<s[lengthCount]<<endl;
            	lengthCount++;
			}
			cout<<"length of Roman String: "<<lengthCount<<endl;

			int convertedIntegerCharacters[lengthCount]; /* Array to store Converted romans*/

			/* Find what Each Character Means */

			map<char, int>::iterator itr;
			
			/* set Basic Conversions */
			setRomanIntegerBaseConversion();
			
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
			for(int j=0;j<lengthCount; j++) {	
				cout<<"Converted Integers: "<<convertedIntegerCharacters[j]<<endl;
			}

			
			
			
			

			
            return 2;
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

    cout<<"Please Input any Roman Symbol OR Combination of Symbols: ";
    cin>>romanInput;
    convertedIntegerOutput = solution.romanToInt(romanInput);
    cout<<"\n - Integer for '"<<romanInput<<"' is = "<<convertedIntegerOutput<<endl;
   return 0; 
}
