#include <iostream>

using namespace std;

class String {
public:

    String() {
        cout << "Default constructor called\n"; 
        CopyString("");
    }

    String(const char* str) {
        cout << "Parameterized constructor called\n";
        CopyString(str); 
    }

    String(String& s) {
        cout << "Copy constructor called\n";
        CopyString(s._str);
    }

    String& operator=(String& s) {
        cout << "Copy assignment called\n";
        //check for self assignment
        if (this != &s) {
            // delete existing memory
            delete []_str;
            CopyString(s._str);
            return *this;
        }

        return *this;
    }

    void Print() {
        cout << _str << endl;
    }

    int Length() {
        cout << Length(this->_str) << endl;
        return Length(this->_str);
    }

    friend ostream& operator<<(ostream& out, const String& str) {
        out << str._str;
        return out;
    }

    friend istream& operator>>(istream& in, String& str) {
        char buffer[100];
        in >> buffer;
        delete []str._str;
        str._str = new char[str.Length(buffer)+1];
        strcpy(str._str, buffer);
        return in;
    }

    ~String() {
        // delete _str; // Invokes only the first destructor of the array.
        delete []_str; // Invokes all the destructors of the array. Both of them free the allocated memory of the array.
    }

private:
    char* _str;

    int Length(const char* str) {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }

        return len;
    }

    void CopyString(const char* str) {
        _str = new char[Length(str)+1];
        int index = 0;
        while (str[index] != '\0') {
            _str[index] = str[index];
            index++;
        }

        _str[index] = '\0';
    }
};

int main() {
    String s1 = "Rudra";
    s1.Print();
    s1.Length();
    cout << s1 << endl;

    String s2("Pratap");
    s2.Print();

    String s5;
    s5.Print();
    s5.Length();

    String s3 = s2;
    s3.Print();
    String s4(s1);
    s4.Print();

    s5 = s1;
    s5.Print();

    String s6;
    cin >> s6;
    s6.Length();
    cout << s6;
}