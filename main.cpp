/**************************************************************************
 *   Author    :  John Chen
 *   Assn #5   :  Cipher
 *   CLASS     :  CS 002
 *   SECTION   :  MTRF: 7a - 12p
 *   Due Date  :  7/1/19
 *************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
 *
 * CIPHER
 * ________________________________________________________________________
 * This program accepts two integers in from a user, sums them and then
 * outputs the result to the monitor
 * ________________________________________________________________________
 * INPUT:
 *   method: The type of method desired -> input from user
 *   map: Can refer to the default one or one from the user
 *         -> input from user
 *   word: The word to be changed during the process -> input from the user
 *
 * OUTPUT:s
 *   changed: The translated word after being either encrypted or decrypted
 *************************************************************************/
int main()
{
    //constants
    string method;   //INPUT - Determines whether the program will be an
                     //        encryption or a decryption
    string map;      //INPUT - Tells the program which map to use in the
                     //        process - default or user inputted
    string word;     //INPUT - the word to be encrypted or decrypted
    string changed;  //CALC & OUT - new word after the process
    bool val;        //CALC - Determines whether there is an error

    //Initializes the boolean to false so that the program runs
    val = false;

    //INPUT & OUTPUT: Prompt the user to input the desired method and
    //                store it for later use
    cout << "What is the method (encryption or decryption)? ";
    cin >> method;
    cout << endl;

    //PROCESSING: Test for whether the input is an error and will stop
    //            the program by making the boolean true
    if(method != "encryption" && method != "decryption")
    {
        cout << "Error: invalid method choice." << endl;
        val = true;
    }

    //PROCESSING: Checks to proceed if not based on boolean state
    if(!val)
    {
        //INPUT & OUTPUT: prompts the user for a default or custom map
        cout << "What is the translation map "
                "(type 'default' to use default): ";
        cin >> map;
        cout << endl;

        //PROCESSING: Gives the map variable a default value or a custom
        //            one based on if it is 26 characters
        if(map == "default")
           map = "zyxwvutsrqponmlkjihgfedcba";
        else if(map.size() != 26)
        {
           //OUTPUT: Displays an error if the map is invalid
           cout << "Error: invalid translation map size." << endl;
           // switches the boolean state to prevent further procedure
           val = true;
        }

        //Checks to see to proceed based on whether there was a past error
        if(!val)
        {
            //OUTPUT & INPUT: Prompt for word to translate and store
            cout << "What is the single word to translate: ";
            cin >> word;
            cout << endl;
        }
    }

    //PROCESSING: checks to see which method to do and also checks boolean
    //            to see if it has to execute based on an error previously
    if(method == "encryption" && !val)
    {
        //PROCESSING: checks every character of word to see if it is within
        //            the ASCII range of lowercase letters and stops if
        //            it encounters one
        for(int i = 0; i < static_cast<int>(word.size())
            && val == false; i++)
        {
            if(word.at(i) > 96 && word.at(i) < 123) //isalpha isdigit
                val = false;
            //Breaks the loop immediately if there is an error
            else
            {
                val = true;
                cout << "Error: encryption cannot be performed." << endl;
            }
        }
    }
    else if(method == "decryption" && !val)
    {
        //PROCESSING: Will check every character in a word to see if the
        //            program can find it in the map
        for(int i = 0; i < static_cast<int>(word.size())
            && val == false; i++)
        {
            if(map.find(word.at(i)) != -1)
                val = false;
            else
            {
                //Loop breaks if the character cannot be found
                val = true;
                cout << "Error: decryption cannot be performed." << endl;
            }
        }
    }

    //Same as previous method loop above except this one translates
    //the word
    if(method == "encryption" && !val)
    {
        //PROCESSING: a new variable string is given and is outputted with
        //            the translated words
        for(int i = 0; i < static_cast<int>(word.length()); i++)
        {
            int num;
            num = static_cast<int>(word.at(i) - 'a');
            changed += map.at(num);
        }

        cout << "Encrypted word: " << changed << endl;
    }
    //Does the same as the encryption method but decrypts instead
    else if(method == "decryption" && !val)
    {
        for(int i = 0; i < word.length(); i++)
        {
            int num;
            string alpha = "abcdefghijklmnopqrstuvwxyz";

            //PROCESSING: Finds value of character in original alphabet
            //            and adds that to the changed variable
            num = map.find(word.at(i));
            changed += alpha.at(num);
        }

        //OUTPUT: displays the translated word
        cout << "Decrypted word: " << changed << endl;
    }
}
