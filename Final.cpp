#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "SongTree.h"

using namespace std;

void mainMenu();
// Command line argument is a parameter for the name of the file to be read in
int main(int argc, char* argv[]){
    SongTree tree;                     // creates an instance of the SongTree called tree which is the binary tree
    int tracker, trackerEnd;
    int releasedYear;
    string title, artist, releasedYearString, album, genre;
    string fileName;
    fileName = argv[1];             // filename taken from the command line
    ifstream infile;                // input the file stream to infile
    infile.open("");
    if(infile.is_open()){       // if the file was successfully opened
    string line, parse;
        while(getline(infile,line)){        // while there are lines to get
            tracker = 0;
            trackerEnd = 0;
            artist = line.substr(tracker,line.find(","));    // Take the substring from the beginning of the line to the first comma
            tracker = line.find(",")+1;                             // position of the first comma
            trackerEnd = line.find(",",tracker)-tracker;            // the length of characters to traverse
            title = line.substr(tracker,trackerEnd);                
            tracker = line.find(",",trackerEnd)+1;                 
            trackerEnd = line.find(",",tracker);                    
            releasedYearString = line.substr(tracker,(trackerEnd-tracker));
            releasedYear = stoi(releasedYearString);
            tracker = line.find(",",trackerEnd)+1;                  
            trackerEnd = line.find(",",tracker)-tracker;            
            album = line.substr(tracker, trackerEnd);               
            tracker = line.find(",",trackerEnd)+1;                  
            trackerEnd = line.find(",",tracker)-tracker;
            genre = line.find(tracker, trackerEnd);
            tree.addSongNode(artist, title, releasedYear, album, genre);          // add the movie node to the tree, which passes it to the tree
        }
    }
    infile.close();                          // close the file
    string option;                          // user option
    int choice=0;
    while(choice!=6){                           // continue this loop until the choice of the user is 4 which is to quit the program
        mainMenu();
        choice=0;
        while(choice<1 || choice>6){            // keep making the user enter something until it is between 1 and 4
            getline(cin,option);                // getline takes it in
            choice = stoi(option);              // convert the string to an int
        }
        if(choice==1){                          // if equal to one
            char arrayOfChar[256];              // declare an array of chars
            cout<<"Enter Song Title:"<<endl;
            cin.getline(arrayOfChar,256);       // getline into the array of chars
            string songTitle(arrayOfChar);     // make the array of chars into a string
            tree.findSong(songTitle);         // call the fund movie based on the string passed to the function
        }
        else if(choice==2){
            char arrayTitle[256];
            char arrayArtist[256];
            char arrayYear[256];
            char arrayGenre[256];
            char arrayAlbum[256];
            cout<<"Enter Song Title:"<<endl;
            cin.getline(arrayTitle,256);
            string songTitle2(arrayTitle);
            cout<<"Enter Song Artist:"<<endl;
            cin.getline(arrayArtist,256);
            string songArtist(arrayArtist);
            cout<<"Enter Song Album:"<<endl;
            cin.getline(arrayAlbum,256);
            string songAlbum(arrayAlbum);
            cout<<"Enter Song Release Year:"<<endl;
            cin.getline(arrayYear,256);
            string songYearString(arrayYear);
            int songYear = stoi(songYearString);
            cout<<"Enter Song Genre:"<<endl;
            cin.getline(arrayGenre,256);
            string songGenre(arrayGenre);
            tree.addSongNode(songArtist, songTitle, songYear, songAlbum, songGenre);
        }
        else if(choice==3){                     // if choice is 3
            char arrayOfChar3[256];
            cout<<"Enter Song Title:"<<endl;
            cin.getline(arrayTitle,256);
            string songTitle3(arrayOfChar3);
            tree.deleteSongNode(arrayOfChar3);
        }
        else if(choice==4){                     // if choice is 3
            char arrayOfChar4[256];
            cout<<"Enter Genre You Want to Find:"<<endl;
            cin.getline(arrayOfChar4,256);
            string songGenre4(arrayOfChar4);
            tree.printGenre(songGenre4);
        }
        else if(choice==5){                     // if choice is 3
            char arrayOfChar5[256];
            cout<<"Enter Start Year of Decade:"<<endl;
            cin.getline(arrayOfChar5,256);
            string songDecadeString(arrayOfChar5);
            int songDecade = stoi(songDecadeString);
            tree.printDecade(songDecade);
        }
    }
    cout<<"Goodbye!"<<endl;
    return 0;                                   // quit and say bye bye
}

void mainMenu(){                            // print the main menu
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Find Song"<<endl;
    cout<<"2. Add a Song"<<endl;
    cout<<"3. Delete a Song"<<endl;
    cout<<"4. Print Same Genre"<<endl;
    cout<<"5. Print Same Decade"<<endl;
    cout<<"6. Quit"<<endl;
}
