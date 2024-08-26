#include <iostream>
#include <cstring>  

using namespace std;

class Document {
private:
    char* content;  

public:
    
    Document(const char* initialContent){
        content = new char[strlen(initialContent) + 1];  
        strcpy(content, initialContent);  
    }
    ~Document(){
        delete[] content;  
    }
    
    Document(const Document& other){
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content); 
    }
    Document& operator=(const Document& other) {
        if (this != &other) {  
            delete[] content; 

            content = new char[strlen(other.content) + 1]; 
            strcpy(content, other.content); 
        }
        return *this;
    }

    void setContent(const char* newContent) {
        delete[] content; 

        content = new char[strlen(newContent) + 1]; 
        strcpy(content, newContent); 
    }

    void display() const {
        cout << "Document Content: " << content << endl;
    }
};

int main() {
    Document doc1("Hello 123");

    cout << "Document 1:" << endl;
    doc1.display();

    Document doc2(doc1);
    cout << "Document 2:" << endl;
    doc2.display();

    Document doc3("abc 123");
    doc3 = doc1;

    cout << "Document 3:" << endl;
    doc3.display();

    doc1.setContent("new content");

    cout << "\nAfter modifying Document content:" << endl;
    cout << "Document 1:" << endl;
    doc1.display();
    cout << "Document 2:" << endl;
    doc2.display();
    cout << "Document 3:" << endl;
    doc3.display();

    return 0;
}
