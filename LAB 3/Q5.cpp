#include<iostream>
using namespace std;

class song{
    public:
    string name;
    string singerName;
    song (){

    }
    song(string s,string name){
        name = s;
        singerName = name;
    }

    void showDetail(){
        cout << " Name of song is : " << name << endl;

        cout << " Singer Name is : " << singerName << endl;
    }
};

class MusicPlayer{
    private:
    song *playLisit;
    string currentlyPlayingSong;
    int num =0;
    public:
    MusicPlayer(){
        playLisit = nullptr;
    }
    void addsong(){
        num++;
        string name;
        string singer;
        cin.ignore();
        cout <<"Enter the name of song ";
        getline(cin,name);

        cout << " Enter the name of singer ";
        getline(cin,singer);

        song *s1 = new song[num];
        for (int i = 0; i < num -1; i++)
        {
            s1[i] = playLisit[i];
        }
        delete []playLisit;
        s1[num-1].name=name;
        s1[num-1].singerName = singer;
        playLisit = s1;
    }

    void removesong(){
        string name;
        string singer;
        bool signal = false;
        cin.ignore();
        cout <<"Enter the name of song ";
        getline(cin,name);

        cout << " Enter the name of singer ";
        getline(cin,singer);
        song *s1 = new song[num];
        int j =0;
        for (int i = 0; i < num; i++)
        {
            if(s1[i].name == name){
                j++;
                signal = true;
            }
            j++;
            s1[i] = playLisit[j];
        }

        delete []playLisit;
        playLisit = s1;
        
        if(signal == true){
            num--;
        }
        else{
            cout << " Song is not present in playlist" << endl;
        }
    }

    void playsong(){
        string name;
        bool signal = false;

        cout << " Enter the name of song " ;
        cin.ignore();
        getline(cin,name);
        for (int i = 0; i < num; i++)
        {
            if(playLisit[i].name == name){
                signal = true;
            }
        }
        if(signal == true){ 
            currentlyPlayingSong = name;
        }
        else{
            cout << " Song is not present in playlist in song";
        }
    }

    void DisplaySong(){
        for(int i=0;i<num ;i++){
            playLisit[i].showDetail();
        }
    }
};

int main(){
    MusicPlayer m1;

    int i;
    while(1){
        cout << " Enter \n 1. TO ADD SONG \n 2. TO REMOVE SONG \n 3. TO PLAY SONG \n 4. TO DISPLAY \n 5. EXIST";
        cin >> i;
        if( i==1 ){
            m1.addsong();
        }
        else if( i== 2 ){
            m1.removesong();
        }
        else if( i==3 ){
            m1.playsong();
        }
        else if( i==4 ){
            m1.DisplaySong();
        }
        else {
            return 0;
        }
    }
    return 0;
}
