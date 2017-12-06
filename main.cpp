#include <iostream>
#include <string>

using namespace std;

string z;

int volume(string x){
    int k = 0,i = 0;
    if(x[0] == x[1]){
        while(x[i + 1] == x[i] && i < x.size()){
            k++;
            i++;
        }

    }k++;
    return k;
}

int main()
{
    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    for(; ; ){
        if(s1[0] != s2[0] || s1[0] != s3[0] || s3[0] != s2[0]){
            cout << "IMP";
            break;
        }else{
            int ss1, ss2, ss3;
            ss1 = volume(s1);
            ss2 = volume(s2);
            ss3 = volume(s3);

            if(s2.size() == 0  && s1.size() == 0  && s3.size() == 0 ){
                cout << z;
                break;
            }else{
                if(s1.size() == 0 || s2.size() == 0 || s2.size() == 0){
                    cout << "IMP";
                    break;
                }else{
                    char symb = s1[0];
                    for(int i = 0; i < (ss1 + ss2 + ss3)/3; i++)
                        z += symb;

                    s1.erase(0,ss1);
                    s2.erase(0,ss2);
                    s3.erase(0,ss3);

                }

            }


        }


    }

    return 0;
}
