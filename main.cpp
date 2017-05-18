#include <iostream>
using namespace std;


int main() {

    string a;
    cout << "What is your credit card number: ";
    cin >> a;
    string b;
    string c;
    long sum;
    long answer;
    long non;
    bool isValid;
    int lengthOfCard = a.length();
    bool isMasterCard = false; //       51,52,53,54,55   16 digits
    bool isAmericanExpress = false; //  34 37            15 digits
    bool isVisa = false; //             14               13 and 16 digits
    bool isValidCard;

    //american express
   if(((a[0] - '0') == 3 && (a[1] - '0') == 7) || ((a[0] - '0') == 3 && (a[1] - '0') == 4)) {
       if(lengthOfCard == 15){
           isValidCard = true;
           isAmericanExpress = true;
       }
   }

    //master card
   if(((a[0] - '0') == 5 && (a[1] - '0') == 1) || ((a[0] - '0') == 5 && (a[1] - '0') == 2) || ((a[0] - '0') == 5 && (a[1] - '0') == 3) || ((a[0] - '0') == 5 && (a[1] - '0') == 4) || ((a[0] - '0') == 5 && (a[1] - '0') == 5)) {
       if(lengthOfCard == 16){
           isValidCard = true;
           isMasterCard = true;
       }
   }

    //visa
    if(((a[0] - '0') == 1 && (a[1] - '0') == 4)){
        if(lengthOfCard == 13 || lengthOfCard == 14 || lengthOfCard == 15 || lengthOfCard == 16){
            isValidCard = true;
            isVisa = true;
        }
    }


    if(isValidCard) {

        for (int i = 0; i < a.length(); i++) {

            if (i % 2 != 0) {

                if ((a[i] - '0') * 2 > 9) {
                    b += to_string((a[i] - '0') * 2);
                    for (int j = 0; j < b.length(); j++) {
                        answer += (b[j] - '0');
                    }
                } else {
                    sum += (a[i] - '0') * 2;
                }

            } else {
                //33
                non += (a[i] - '0');
            }
        }

        if ((answer + sum + non) % 10 == 0) {
            isValid = true;
        }

        if (isValid) {

            if(isMasterCard){
                printf("Master Card Verified\n");
            } else if(isAmericanExpress){
                printf("American Express Card Verified\n");
            } else if(isVisa){
                printf("Visa Card Verified\n");
            } else {
                printf("There was an unexpected error on our end\n");
            }
        } else if(isMasterCard && !isValid) {
            printf("This Master Card Is Invalid ");
        }else if(isVisa && !isValid) {
            printf("This Visa Card Is Invalid ");
        }else if(isAmericanExpress && !isValid) {
            printf("This American Express Card Is Invalid ");
        }
    } else {
        printf("Not Valid \n");
    }





    return 0;
}

