// Colton O'Connor
// Final Project
// Hoenigman

#include "SongTree.h"
#include <iostream>
#include <string>

// Instance of song tree with a null root
SongTree::SongTree(){
    root = new SongNode;
    root = NULL;
}
// circular virtual
SongTree::~SongTree(){
}
/* the initial call to printing the song inventory. If the root is not null
    then it calls the recursive version of this function and passes the left child
    first, then it prints the root, then it continues and calls the recursive function
    with the right child */
void SongTree::printSongInventory(){
    if(root->leftChild!=NULL){
        printSongInventory(root->leftChild);
    }
    std::cout<<"Song: "<<root->title<<std::endl;
    if(root->rightChild!=NULL){
        printSongInventory(root->rightChild);
    }
}
/* This is the recursive print song function, if the leftchild node is not null, then
call it again with the leftchild of the node as the parameter to be searched. Once the
leftchild is NULL, that means that the minimum / top of the list has been found, and so it'll
print out the song with the leftchild pointer which is null. Then it passes its rightchild and does
the same thing (as long as its not null in the first place). */
void SongTree::printSongInventory(SongNode *node){
    if(node->leftChild!=NULL){
        printSongInventory(node->leftChild);
    }
    std::cout<<"Song: "<<node->title<<std::endl;
    if(node->rightChild!=NULL){
        printSongInventory(node->rightChild);
    }
}
/* The function that adds songs. It creates a new song node with all of the provided information that
is read in and sets its children to be null. Root is stored in x, and the parent is called p. The function
compares the titles of the song character by character. If the character of the song being read in
is smaller in ASCII value, then x is set to the left child and it keeps traversing until it finds a NULL
and places it as rightchild or leftchild to the parent according to ASCII value again */
void SongTree::addSongNode(std::string artist, std::string title, int releaseYear, std::string album, std::string genre){
    bool skip = false;
    int index;
    char char1, char2;
    SongNode *p = NULL;
    SongNode *x = root;
    SongNode *song = new SongNode(artist, title, releaseYear, album, genre);
    song->rightChild = NULL;
    song->leftChild = NULL;
    while(x!=NULL){
        skip = false;
        index = 0;
        p = x;
        char1 = song->title.std::string::at(index);
        char2 = x->title.std::string::at(index);
        while(char1==char2){
            index++;
            if(index>=(song->title.std::string::length())){
                skip = true;
                x = x->leftChild;
            }
            else if(index<song->title.std::string::length()){
                char1 = movie->title.std::string::at(index);
            }
            if(index>=(x->song.std::string::length())){
                skip = true;
                x = x->rightChild;
            }
            else if(index<x->title.std::string::length()){
                char2 = x->title.std::string::at(index);
            }
        }
        if(skip==false){
            if(char1<char2){
                x = x->leftChild;
            }
            else if(char1>char2){
                x = x->rightChild;
            }
        }
    }
    movie->parent = p;
    if(p==NULL){
        root = movie;
        skip = true;
    }
    else{
        index = 0;
        skip = false;
        char1 = song->title.std::string::at(index);
        char2 = p->title.std::string::at(index);
        while(char1==char2){
            index++;
            if(index>=(song->title.std::string::length())){
                p->leftChild = song;
                skip = true;
            }
            else if(index<song->title.std::string::length()){
                char1 = song->title.std::string::at(index);
            }
            if(index>=(p->title.std::string::length())){
                p->rightChild = song;
                skip = true;
            }
            else if(index<p->title.std::string::length()){
                char2 = p->title.std::string::at(index);
            }
        }
        if(skip==false){
            if(char1<char2){
                p->leftChild = song;
            }
            else if(char1>char2){
                p->rightChild = song;
            }
        }
    }
}

void SongTree::deleteSongNode(std::string title){
    SongNode *dnode = search(title);
    
}
/* The function that finds songs. It uses the same logic as the above function. It compares the title of the
song that is being looked for with the root. It compares the title of the root with the title char by char,
and if it equal, then it has found the song, and returns the song node into movieNode. If the title is before
the title in alphabetical order, then it will begin to traverse the left root of the tree with searchSongTree and
will return the song node if it is found, if not it will return NULL. If the title is after in alphabetical order to the
title of the root, then it will searchSongTree through the right root of the tree. Again, return the song node into foundSong,
or NULL if not found. The function compares the titles of the song character by character. Then, if foundSong is equal to NULL, it
will display that the song was not found, else, it will extract all the data from the node and display it. */
void SongTree::findSong(std::string title){
    bool skip = false;
    int place = 0;
    SongNode *foundSong = root;
    if(root->title == title){
        foundSong = foundSong;
    }
    else if(root->title.std::string::at(0) > title.std::string::at(0)){
        foundSong = search(title);
    }
    else if(root->title.std::string::at(0) < title.std::string::at(0)){
        foundSong = search(title);
    }
    else if(root->title.std::string::at(0) == title.std::string::at(0)){
        place = 0;
        while(root->title.std::string::at(place)==title.std::string::at(place)){
            skip = false;
            place++;
            if(place>=(title.std::string::length())){
                skip = true;
                std::cout<<root->title<<std::endl;
                foundSong = search(title);
            }
            if(place>=(root->title.std::string::length())){
                skip = true;
                std::cout<<root->title<<std::endl;
                foundSong = search(title);
            }
        }
        if(skip==false){
            if(title.std::string::at(place)<root->title.std::string::at(place)){
                std::cout<<root->title<<std::endl;
                foundSong = search(title);
            }
            else if(title.std::string::at(place)>root->title.std::string::at(place)){
                std::cout<<root->title<<std::endl;
                foundSong = search(title);
            }
        }
    }
    if(foundSong!=NULL){
        std::cout<<"Song Info:"<<std::endl;
        std::cout<<"==========="<<std::endl;
        std::cout<<"Title:"<<foundSong->title<<std::endl;
        std::cout<<"Artist:"<<foundSong->artist<<std::endl;
        std::cout<<"Album:"<<foundSong->album<<std::endl;
        std::cout<<"Year Released:"<<foundSong->year<<std::endl;
        std::cout<<"Genre:"<<foundSong->genre<<std::endl;
    }
    else if(foundSong==NULL){
        std::cout<<"Information not found."<<std::endl;
    }
}

void printGenre(std::string genre){
    bool skip = false;
    int place = 0;
    SongNode *foundSong = root;
    string title = foundSong->title; 
    std::cout<<"Song in the Genre:"<<genre<<std:endl;
    std::cout<<"=========="<<std::endl;
    while(foundSong != NULL){
        if(root->genre == genre){
            std::cout<<"Title:"<<foundSong->title<<std::endl;
            std::cout<<"Artist:"<<foundSong->artist<<std::endl;
            std::cout<<"Album:"<<foundSong->album<<std::endl;
            std::cout<<"Year Released:"<<foundSong->year<<std::endl;
            std::cout<<"Genre:"<<foundSong->genre<<std::endl;
            std::cout<<"=========="<<std::endl;
        }
        else if(root->title.std::string::at(0) > title.std::string::at(0)){
            foundSong = search(title);
        }
        else if(root->title.std::string::at(0) < title.std::string::at(0)){
            foundSong = search(title);
        }
        else if(root->title.std::string::at(0) == title.std::string::at(0)){
            place = 0;
            while(root->title.std::string::at(place)==title.std::string::at(place)){
                skip = false;
                place++;
                if(place>=(title.std::string::length())){
                    skip = true;
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
                if(place>=(root->title.std::string::length())){
                    skip = true;
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
            }
            if(skip==false){
                if(title.std::string::at(place)<root->title.std::string::at(place)){
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
                else if(title.std::string::at(place)>root->title.std::string::at(place)){
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
            }
        }
        else if(foundSong==NULL){
            std::cout<<"Information not found."<<std::endl;
        }
    }
}

void printDecade(int year){
    bool skip = false;
    int place = 0;
    SongNode *foundSong = root;
    string title = foundSong->title; 
    std::cout<<"Song in the Decade:"<<year<<" to "<<year+9<<std:endl;
    std::cout<<"=========="<<std::endl;
    while(foundSong != NULL){
        if(root->year<year+10 && root->year >= year){
            std::cout<<"Title:"<<foundSong->title<<std::endl;
            std::cout<<"Artist:"<<foundSong->artist<<std::endl;
            std::cout<<"Album:"<<foundSong->album<<std::endl;
            std::cout<<"Year Released:"<<foundSong->year<<std::endl;
            std::cout<<"Genre:"<<foundSong->genre<<std::endl;
            std::cout<<"=========="<<std::endl;
        }
        else if(root->title.std::string::at(0) > title.std::string::at(0)){
            foundSong = search(title);
        }
        else if(root->title.std::string::at(0) < title.std::string::at(0)){
            foundSong = search(title);
        }
        else if(root->title.std::string::at(0) == title.std::string::at(0)){
            place = 0;
            while(root->title.std::string::at(place)==title.std::string::at(place)){
                skip = false;
                place++;
                if(place>=(title.std::string::length())){
                    skip = true;
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
                if(place>=(root->title.std::string::length())){
                    skip = true;
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
            }
            if(skip==false){
                if(title.std::string::at(place)<root->title.std::string::at(place)){
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
                else if(title.std::string::at(place)>root->title.std::string::at(place)){
                    std::cout<<root->title<<std::endl;
                    foundSong = search(title);
                }
            }
        }
        else if(foundSong==NULL){
            std::cout<<"Information not found."<<std::endl;
        }
    }
}

/* This is the recursive version of searchSongTree and does the same as the above function, but starts comparing on the
node / leaf that was passed to it. It compares the title of the song that is being looked
for with the node. It compares the title of the node with the title char by char,
and if it equal, then it has found the song, and returns the song node. If the title is before
the title in alphabetical order, then it will begin to traverse the left child of the that node with searchMovieTree with that node as the parameter and
will return the song node if it is found, if not it will return NULL. If the title is after in alphabetical order to the
title of the node, then it will searchSongTree through the right node of the tree. It does the same as it does for the leftchildren but
on the right side. The function compares the titles of the song character by character. */
SongNode* SongTree::search(std::string title){
    SongNode *node = new SongNode;
    int place = 0;
    bool skip = false;
    if(node == NULL){
        return node;
    }
    else if(node->title == title){
        return node;
    }
    else{
        place = 0;
        if(node->title.std::string::at(place) > title.std::string::at(place)){
            return search(title);
        }
        else if(node->title.std::string::at(place) < title.std::string::at(place)){
            return search(title);
        }
        else{
            while(node->title.std::string::at(place)==title.std::string::at(place)){
                skip = false;
                place++;
                if(place>=(title.std::string::length())){
                    skip = true;
                    return search(title);
                }
                if(place>=(node->title.std::string::length())){
                    skip = true;
                    return search(title);
                }
            }
            if(skip==false){
                if(title.std::string::at(place)<node->title.std::string::at(place)){
                    return search(title);
                }
                else if(title.std::string::at(place)>node->title.std::string::at(place)){
                    return search(title);
                }
            }
        }
    }
}
