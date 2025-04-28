#include <iostream>
#include <fstream>
using namespace std;

bool isNum(char num);
bool isDate(string str); //TODO: Implement and replace isNum

int main(){
    int numshows = 0;
    int numbands = 0;
    int i=0;
    string curLine;
    char first;
    bool newBand;

    struct band{
        string name;
        int shows = 0;
    };
    band bands[1000];

    ofstream bandsOut("output.txt");
    ifstream shows;
    shows.open ("shows.txt");
    if(!shows.is_open()){
        cout << "Failed to open shows.txt\n";
        return 0;
    }

    while(getline(shows, curLine)){ //start working through the file top-to-bottom
        if(!curLine.empty() && isNum(curLine.at(0))) numshows++;

        else if(curLine.size() > 1){ //if line isn't a date, assume contents are a band name
            for(i=0; i<sizeof(bands); i++){
                if(bands[i].name == curLine) {
                        bands[i].shows++;
                        break;
                }
                else if(bands[i].name.empty()){ //if at end of band list and haven't found a matching name yet, add band to list
                    bands[i].name = curLine;
                    numbands++;
                    bands[i].shows++;
                    break;
                }
            }
        }
    }

    cout << "Show count: " << numshows << endl;
    bandsOut << "Show count: " << numshows << endl;

    for(i=0; !bands[i].name.empty(); i++){
    }
    numbands = i;
    cout << "Band Count: " << numbands << "\n\n";
    cout << "Count\tBand\n";
    bandsOut << "Band Count: " << numbands << "\n\n";
    bandsOut <<"Count\tBand\n";

    band tempBand;
    for(int i=0; i<numbands; i++){
        if(bands[i].shows < bands[i+1].shows){
            tempBand = bands[i];
            bands[i] = bands[i+1];
            bands[i+1] = tempBand;
            i=-1;
        }
    }

    for(i=0; !bands[i].name.empty(); i++){
        cout << bands[i].shows << "\t" << bands[i].name << endl;
        bandsOut << bands[i].shows << "\t" << bands[i].name << endl;
    }

    shows.close();
    bandsOut.close();
    return 0;
}


bool isNum(char num){
    if(num=='1' ||
       num=='2' ||
       num=='3' ||
       num=='4' ||
       num=='5' ||
       num=='6' ||
       num=='7' ||
       num=='8' ||
       num=='9' ||
       num=='0')return 1;
    else return 0;
}

bool isDate(string str){
    return 0;
}
