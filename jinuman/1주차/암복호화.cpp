#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string type;        //encrypt,decrypt
    string secret_key;  //secret key
    int temp;           //a~z : 0~25
    int rotate_num;     //rotate num
    string msg;         //message


    cin >> type >> secret_key >> rotate_num >> msg;

    //encrypt
    if (type == "encrypt") {
        for (int i = 0; i < msg.length(); i++) {
            temp = (int)secret_key[i] - 97;
            if ((int) msg[i] + temp > 122)
                msg[i] = char((int)msg[i] + temp - 26);
            else
                msg[i] = char((int)msg[i] + temp);
        }
        rotate(begin(msg), begin(msg)+rotate_num, end(msg));
    }
        //decrypt
    else if (type == "decrypt"){
        rotate(begin(msg), begin(msg)+(msg.length() - rotate_num), end(msg));
        for (int i = 0; i < msg.length(); i++) {
            temp = (int)secret_key[i] - 97;
            if ((int) msg[i] - temp < 97)
                msg[i] = char((int) msg[i] - temp + 26);
            else
                msg[i] = char((int) msg[i] - temp);
        }
    }
    cout << msg;

    return 0;
}
