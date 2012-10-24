#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

extern "C" {
#include "cleanurl.h"
}

using namespace std;

void usage(){
    printf("Usage: program input.txt (two columns seperated by TAB)\n");
}

int main(int argc, char** argv) {
    char buf[2048];
    if(argc==1){
        usage();
        exit(1);
    }

    ifstream file(argv[1]);
    string line;
    cout<<"Loading test ..."<<endl;
    while(getline(file,line)){
        int r;
        stringstream lst(line);
        string orig, desired;
        lst >> orig >> desired;
        cout<<"orig desired:"<<orig<<" "<<desired<<endl;
        r=clean_url(buf,orig.c_str(),orig.length());
        if(r!=0){
            fprintf(stderr,"clean_url failed. error number=%d\n",r);
            exit(1);
        }
        cout<<(strcmp(buf,desired.c_str())==0?"SUCCEED":"FAIL")<<" <="<<endl
                 <<"    our URL:"<<buf<<endl
                 <<"desired URL:"<<desired<<endl
                 <<endl;
    }

    return 0;
}
