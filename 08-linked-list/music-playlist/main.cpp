#include<iostream>
#include<string>
using namespace std;


class Song {
public:
    string title;
    Song *next;
    Song *prev;

    Song(string title) {
        this->title = title;
        this->next = nullptr;
        this->prev = nullptr;
    }

};

class Playlist {
private:
    Song *head;
    Song *tail;


public:
    Playlist(){
        this->head=nullptr;
        this->tail=nullptr;
    }

    void addSong(string title) {
        Song *newSong = new Song(title);

        if (!head) {
            head = newSong;
            tail = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    bool removeSong(string title) {
        Song *temp = head;
        while(temp != nullptr) {
            if(temp -> title == title) {
                if(temp->prev) temp->prev->next = temp->next;
                if(temp->next) temp->next->prev = temp->prev;
                if(temp == head) head = temp->next;
                if(temp == tail) tail = temp->prev;
                delete temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Song *temp = head;
        while(temp != nullptr) {
            cout << temp->title << "\n";
            temp = temp->next;
        }
    }

};

int main() {
    Playlist AniSongPlaylist;
    AniSongPlaylist.addSong("クスシキ");
    AniSongPlaylist.addSong("Watch me!");
    AniSongPlaylist.addSong("純恋愛のインゴット");

    cout << "Current Playlist" << "\n";
    AniSongPlaylist.display();

    AniSongPlaylist.removeSong("純恋愛のインゴット");
    cout << "Playlist after removing a song:" << "\n";
    AniSongPlaylist.display();

    return 0;
}