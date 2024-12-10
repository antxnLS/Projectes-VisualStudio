//TellingTheStory.cpp
//Nom: Anton Volegov
//Data: 18/10/2024

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    string sport, place, structure, adjective, object, adjective2, vehicle; //Inicialitzem les variables
    int objectCount;
    float number;
    bool choice;
    char character;
    double number2;
    long number3;
    cout << "Hola, usuari! Avui escriurem una historia en angles\n";

    do { //Utilitzem un do while per que el usuari jugui un altre cop si vol
        cout << "Enter a sport: \n";
        getline(cin, sport); //Utilitzem getline per tambe incloure espais
        system("CLS"); //Utilitzem aquesta funcio per esborrar la pantalla
        cout << "Enter a number: \n";
        cin >> number; //Utilitzem cin per numeros sencers
        cin.ignore(); //Posem el cin.ignore per que no s'emboliqui amb el getline
        system("CLS");
        cout << "Enter a place: \n";
        getline(cin, place);
        system("CLS");
        cout << "Enter another number: \n";
        cin >> number2;
        cin.ignore();
        system("CLS");
        cout << "Enter a structure: \n";
        getline(cin, structure);
        system("CLS");
        cout << "Enter a number of objects: \n";
        cin >> objectCount;
        cin.ignore();
        system("CLS");
        cout << "Enter an adjective: \n";
        getline(cin, adjective);
        system("CLS");
        cout << "Enter an object (plural): \n";
        getline(cin, object);
        system("CLS");
        cout << "Enter another number: \n";
        cin >> number3;
        cin.ignore();
        system("CLS");
        cout << "Enter another adjective: \n";
        getline(cin, adjective2);
        system("CLS");
        cout << "Enter a vehicle: \n";
        getline(cin, vehicle);
        system("CLS");

        int multipliedNumber = objectCount * number3; //Multiplica dos numeros per utilitzar-los mes tard al codi
        cout << "It's a sunny summer day, and you are playing " << sport << " with your friends, until suddenly, the sky starts to turn dark, " << endl;
        Sleep(1000); //Li posem un delay als missatges
        cout << "and you realize a very violent thunderstorm is going to commence. In a similar spontaneous manner, " << endl;
        Sleep(1000);
        cout << "a lightning bolt strikes " << number << " cars in the parking lot, you quickly turn your head to look, and you see electricity " << endl;
        Sleep(1000);
        cout << "arcing from car to car. Everyone is frightened, maybe the lightning can also strike us, you think. " << endl;
        Sleep(1000);
        cout << "The group decides it would be better to go to " << place << " and rest for the day, due to this erratic weather. " << endl;
        Sleep(1000);
        cout << "As " << number2 << " of your friends are packing their stuff, you notice " << objectCount << " strange " << adjective << " golden " << object << endl;
        Sleep(1000);
        cout << "pierced through the roof of " << number3 << " of the cars, which comes to you as a surprise since you are sure that it" << endl;
        Sleep(1000);
        cout << "wasn't there before. You try to pull one out but get shocked instantly, thankfully you don't have any permanent damage, but it still hurts. " << endl;
        Sleep(1000);
        cout << "At this point, your friends are already on their way to " << place << ", so you decide to go with them. " << endl;
        Sleep(1000);
        cout << "Upon arriving, you are shocked, some buildings look like someone has ripped the top off, a passer-by tells you that a tornado swept" << endl;
        Sleep(1000);
        cout << "through the street. You look around trying to find your friends but it appears you are lost, but while looking you find a magnet lying next to the road, " << endl;
        Sleep(1000);
        cout << "you think that maybe you can pull out those " << object << " you have seen earlier. " << endl;
        Sleep(1000);
        cout << "It's still raining outside, so you try your best to run to the parking lot without slipping along the way. " << endl;
        Sleep(1000);
        cout << "You find the " << object << ", and it looks like they're glowing even stronger than before. " << endl;
        Sleep(1000);
        cout << "You grab the magnet you took with you and put it near the " << object << ", they stick to the magnet. " << endl;
        Sleep(1000);
        cout << "When you examine it closely, you can see a " << structure << " symbol inscribed into it. You know what you have to do, you remember about a " << adjective2 << " " << structure << " in your city, " << endl;
        Sleep(1000);
        cout << "so you figure if you throw it something will happen. You hop on your " << vehicle << " and almost slip while exiting your driveway. " << endl;
        Sleep(1000);
        cout << "You start driving towards the center of the city, when you arrive, the " << structure << " is strangely dry, " << endl;
        Sleep(1000);
        cout << "even though everything around it was wet from the rain. " << endl;
        Sleep(1000);
        cout << "So you try to throw it at the " << structure << ", and it works! It absorbs the " << object << ", you briefly see the " << multipliedNumber << " destroyed cars still in the parking lot, " << endl;
        Sleep(1000);
        cout << "and you suddenly wake up in your house. You think that it was a dream, but you remember everything so vividly and when you wake up you aren't in your bed, " << endl;
        Sleep(1000);
        cout << "but standing in the middle of your room." << endl << endl;
        Sleep(3000);
        cout << "What do you do now?: " << endl;
        cout << "1 = ask your family about the incident, 0 = You go back to your room and try to fall asleep: ";
        cin >> choice;
        cin.ignore();
        Sleep(1000);

        if (choice == true) //Si el usuari escull la opcio 1
        {
            cout << "You run into your brother's room and find that he is weightlifting, you ask him if he remembers anything about the storm, " << endl;
            Sleep(1000);
            cout << "he says that you must be imagining things. Your parents say the same thing. " << endl;
            Sleep(3000);
            cout << "What do you do now?: " << endl;
            cout << "1 = ask your friends if they remember that day, 0 = Forget about it and stay in your room: ";
            cin >> choice;
            cin.ignore();
            Sleep(1000);
            
            if (choice == true) //Si el usuari escull la opcio 1 a la segona pregunta
            {
                cout << "You send a message in your groupchat and wait, a few hours pass and many people say that they had a similar experience to you, " << endl;
                Sleep(1000);
                cout << "explaining that after they went home, the storm suddenly cleared and they felt weird, like something wasn't right. But everyone they asked didn't share the same feeling. " << endl;
                Sleep(1000);
                cout << "Your deduction is that something very strange happened, and that you were somehow involved in it." << endl;
                Sleep(1000);
            }
            else if (choice == false) //Si el usuari escull la opcio 0 a la segona pregunta
            {
                cout << "You decide not to exhaust yourself even more and go play videogames, although something feels off, you just ignore it. " << endl;
                Sleep(1000);
                cout << "The next morning everything goes as usual, you eat breakfast and go to school, while you sit in class you wonder if what you saw was real. " << endl;
                Sleep(1000);
            }
            
        }
        else if (choice == false) //Si el usuari escull la opcio 0
        {
            cout << "You decide to go to bed and try to fall asleep, but you can't, the shock of what just happened is not letting you sleep. " << endl;
            Sleep(1000);
            cout << "After a few hours, you finally fall asleep, the next day you barely remember anything about yesterday. You think what you experienced is absurd, " << endl;
            Sleep(1000);
            cout << "and you suppose it was a dream. Time passes by and you completely forget about that day. " << endl;
            Sleep(1000);
        }

        cout << "\nDo you want to write another story? (Y/N): "; //Pregunta si vol jugar una altre cop
        cin >> character;
        cin.ignore();
        system("CLS");

    } while (character == 'Y' || character == 'y'); //Reinicia el programa si el usuari escriu "y"
}