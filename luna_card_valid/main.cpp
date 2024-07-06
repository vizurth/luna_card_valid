#include <iostream>
#include <string>
using namespace std;

enum cardType {
    mastercard, visa,
};

struct cardInfo {
    bool validInfo;
    cardType type;
};

cardInfo lunaAlg(char card[17]){
    int sumonchet = 0;
    cardInfo cardThing;
    for (int i = 1; i < 16; i+=2){
        int val  = card[i] - '0';
        sumonchet += val;
    }
    
    for (int i = 0; i < 15; i+=2){
        int val  = card[i] - '0';
        int tempValue = 1;
        tempValue = val*2;
        if (tempValue > 9){
            tempValue = tempValue - 9;
        }
        sumonchet += tempValue;
    }
    if (sumonchet % 10 == 0){
        cardThing.validInfo = true;
    } else {
        cardThing.validInfo = false;
    }
    if (card[0] == '4'){
        cardThing.type = cardType::visa;
    } else if (to_string(card[0] - '0')+to_string(card[1] - '0') == "51" || to_string(card[0] - '0')+to_string(card[1] - '0') == "52" || to_string(card[0] - '0')+to_string(card[1] - '0') == "53" || to_string(card[0] - '0')+to_string(card[1] - '0') == "54" ||to_string(card[0] - '0')+to_string(card[1] - '0') == "55"){
        cardThing.type = cardType::mastercard;
    }
    return cardThing;
}

int main(){
    setlocale(LC_ALL, "RU");
    char card[17];
    cout << "Write a credit card number: ";
    cin >> card;
    cardInfo createCard = lunaAlg(card);
    
    if (createCard.type == cardType::visa && createCard.validInfo == true){
        cout << "Is Visa card\n";
    } else if (createCard.type == cardType::mastercard && createCard.validInfo == true){
        cout << "Is Mastercard card\n";
    } else if (createCard.validInfo == false){
        cout << "Its not valid card\n";
    }
    
    return 0;
}
