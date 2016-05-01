#ifndef SONGTREE_H
#define SONGTREE_H
#include <string>

struct SongNode{
    std::string artist;
    std::string title;
    int year;
    std::string album;
    std::string genre;
    SongNode *parent;
    SongNode *leftChild;
    SongNode *rightChild;

    SongNode(){};

    SongNode(std::string in_artist, std::string in_title, int in_year, std::string in_album, std::string genre)
    {
        artist = in_ranking;
        title = in_title;
        year = in_year;
        album = in_album;
        genre = in_genre;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class SongTree
{

    public:
        SongTree();
        ~SongTree();
        void printSongInventory();
        int countSongNodes();
        void deleteSongNode(std::string title);
        void addSongNode(std::string artist, std::string title, int releaseYear, std::string album, std::string genre);
        void findSong(std::string title);
        void printGenre(std::string genre);
        void printDecade(int year);

    protected:

    private:
        void DeleteAll(SongNode * node); //use this for the post-order traversal deletion of the tree
        void printSongInventory(SongNode * node);
        SongNode* search(std::string title);
        SongNode *root;
};

#endif // SONGTREE_H
