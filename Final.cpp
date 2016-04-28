#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "MovieTree.h"

using namespace std;

void mainMenu();
// Command line argument is a parameter for the name of the file to be read in
int main(int argc, char* argv[]){
    MovieTree tree;                     // creates an instance of the movieTree called tree which is the binary tree
    int tracker, trackerEnd;
    int ranking, releasedYear, quantity;
    string title, rankingString, releasedYearString, quantityString;
    string fileName;
    fileName = argv[1];             // filename taken from the command line
    ifstream infile;                // input the file stream to infile
    infile.open("Assignment6Movies.text");
    if(infile.is_open()){       // if the file was successfully opened
    string line, parse;
        while(getline(infile,line)){        // while there are lines to get
            tracker = 0;
            trackerEnd = 0;
            rankingString = line.substr(tracker,line.find(","));    // Take the substring from the beginning of the line to the first comma
            ranking = stoi(rankingString);                          // convert the string to an integer for the ranking
            tracker = line.find(",")+1;                             // position of the first comma
            trackerEnd = line.find(",",tracker)-tracker;            // the length of characters to traverse
            title = line.substr(tracker,trackerEnd);                // Take the substring from the first comma to the second, this is the title
            tracker = line.find(",",trackerEnd)+1;                  // The position of the second comma
            trackerEnd = line.find(",",tracker);                    // The length of characters until the third comma
            releasedYearString = line.substr(tracker,(trackerEnd-tracker));         // Take the substring from the second comma to the third comma
            releasedYear = stoi(releasedYearString);                                // Convert the string to an int for the released year
            tracker = line.find(",",trackerEnd)+1;                  // The position of the third comma
            trackerEnd = line.find(",",tracker)-tracker;            // The character length until the end of the string
            quantityString = line.substr(tracker, trackerEnd);      // Take the substring from the third comma to the end of the line
            quantity = stoi(quantityString);                        // convert to an int for the quantity of movies available
            tree.addMovieNode(ranking, title, releasedYear, quantity);          // add the movie node to the tree, which passes it to the tree
        }
    }
    infile.close();                          // close the file
    string option;                          // user option
    int choice=0;
    while(choice!=4){                           // continue this loop until the choice of the user is 4 which is to quit the program
        mainMenu();
        choice=0;
        while(choice<1 || choice>4){            // keep making the user enter something until it is between 1 and 4
            getline(cin,option);                // getline takes it in
            choice = stoi(option);              // convert the string to an int
        }
        if(choice==1){                          // if equal to one
            char arrayOfChar[256];              // declare an array of chars
            cout<<"Enter title:"<<endl;
            cin.getline(arrayOfChar,256);       // getline into the array of chars
            string movieTitle(arrayOfChar);     // make the array of chars into a string
            tree.findMovie(movieTitle);         // call the fund movie based on the string passed to the function
        }
        else if(choice==2){                     // if choice is 3
            char arrayOfChar2[256];             // declare an array of char
            cout<<"Enter title:"<<endl;
            cin.getline(arrayOfChar2,256);      // getline into the char array
            string movieTitle2(arrayOfChar2);   // convert the char array into a string
            tree.rentMovie(movieTitle2);        // call the rent movie function with the string provided as the parameter
        }
        else if(choice==3){                     // if choice is 3
            tree.printMovieInventory();         // simply call the function to print all the movies
        }
    }
    cout<<"Goodbye!"<<endl;
    return 0;                                   // quit and say bye bye
}

void mainMenu(){                            // print the main menu
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Find a movie"<<endl;
    cout<<"2. Rent a movie"<<endl;
    cout<<"3. Print the entire inventory"<<endl;
    cout<<"4. Quit"<<endl;
}
