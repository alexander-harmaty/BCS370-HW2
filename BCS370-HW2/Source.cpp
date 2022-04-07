#include <iostream>
#include <fstream>
#include <random>
#include "../../M05_DynQueue/DataStructuresDynamicQueue/farmingdaleDynamicContiguousMemoryQueue.h"

using namespace std;

void randomStream(std::string filename, int iterations)
{
    //set randoms for letters
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_int_distribution<> dis1(0, 5);

    //set randoms for numbers that follow 'A'
    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::uniform_int_distribution<> dis2(INT_MIN, INT_MAX);

    //declare variables
    int temp;
    string letters[6] = { "A","D","P","E","C","S" }; //string to hold letters, use rand for i to get rand letter
    ofstream outputFile(filename); //open file

    for (int i = 0; i < iterations; ++i)
    {
        temp = dis1(gen1); //temp int to hold rand num
        if (temp == 0) //if rand num produces 'A', use rand gen2 to add more rand nums
        {
            outputFile << letters[temp] << " " << dis2(gen2);//output to file
        }
        else //if rand != A, the just add the letter
        {
            outputFile << letters[temp];
        }
        if (i != iterations - 1) //num of lines must be EXACTLY same as iterations...if not last line, add new line
        {
            outputFile << "\n";
        }
    }
    outputFile.close(); //close file
}

void testStream(std::string filename) 
{
    //create four instances of the farmingdale::queue ADT holding std::strings. 
    farmingdale::queue<std::string>* queue1 = new farmingdale::queue<std::string>();
    farmingdale::queue<std::string>* queue2 = new farmingdale::queue<std::string>();
    farmingdale::queue<std::string>* queue3 = new farmingdale::queue<std::string>();
    farmingdale::queue<std::string>* queue4 = new farmingdale::queue<std::string>();

    //open file
    fstream myfile;
    myfile.open(filename, ios::in);

    //read each line of the file
    if (myfile.is_open())
    {
        string fileLine;
        while (getline(myfile, fileLine))
        {
            //process each line as if it was a set of instructions
            switch (fileLine[0])
            {
                case 'A':
                {
                    //get the number from the remainder of the line as a string
                    fileLine.erase(0, 2);

                    //enqueue()that string into all of the queues
                    queue1->enqueue(fileLine);
                    queue2->enqueue(fileLine);
                    queue3->enqueue(fileLine);
                    queue4->enqueue(fileLine);

                    /*
                    It must check the return value of the enqueue() operations. 
                    If any of the enqueues return FAILURE because they are full, 
                    all must return that same return code 
                    (since these are dynamic, this really is not expected). 
                    If only some of the queues return FAILURE, that is an error, 
                    and it should terminate and print the line number from the instruction file 
                    (not the program line number)
                    */

                    //std::cout << line << std::endl; //console print test
                    break;
                }
                case 'P':
                {
                    //peek() the queues
                    queue1->peek(fileLine);
                    queue2->peek(fileLine);
                    queue3->peek(fileLine);
                    queue4->peek(fileLine);

                    /*
                    It must check the return value of the peek()operations. 
                    If any of the queues return FAILURE because they are empty, 
                    all must return that same return code. 
                    If only some of the queues return FAILURE, that is an error, 
                    and it should terminate and print the line number from the instruction file.
                    */

                    /*
                    If the peek()did not return FAILURE, 
                    your code should make sure all peek()s “returned” the same top string element
                    (we use “return” loosely here to include data returned to the caller as a reference parameter) 
                    */

                    //std::cout << line << std::endl; //console print test
                    break;
                }
                case 'D':
                {
                    //dequeue() all the queues
                    queue1->dequeue(fileLine);
                    queue2->dequeue(fileLine);
                    queue3->dequeue(fileLine);
                    queue4->dequeue(fileLine);

                    /*
                    It must check the return value of the dequeue()operations. 
                    If any of the queues return FAILURE because they are empty, 
                    all must return that same return code. 
                    If only some of the queues return FAILURE, that is an error, 
                    and it should terminate and print the line number from the instruction file.
                    */

                    /*
                    If the queues were not empty (that is, if it did not return FAILURE),
                    it must check all elements removed from each queue were the same  
                    */

                    //std::cout << line << std::endl; //console print test
                    break;
                }
                case 'E':
                {
                    //should check if the queues are empty
                    queue1->isEmpty();
                    queue2->isEmpty();
                    queue3->isEmpty();
                    queue4->isEmpty();
                    
                    /*
                    It should run isEmpty() on all queues
                    It should check the return values of isEmpty(). 
                    True or false is fine, but all must agree. 
                    If they don’t agree, then it’s an error. 
                    */
                    
                    //std::cout << line << std::endl; //console print test
                    break;
                }
                default:
                {
                    //If the line is anything other than D, E, P or A, ignore the line.
                    
                    //std::cout << line << std::endl; //console print test
                    break;
                }
            }
        }
        myfile.close();
    }
}

int main() {
    std::cout << "WELCOME TO THE EXTRA-MODULE INDIVIDUAL ASSIGNMENT" << std::endl;
    std::cout << "........now complete with part two functionality!" << std::endl;

    bool programRunning = true;
    int choice;

    //MAIN MENU
    while (programRunning) 
    {
        std::cout << "_________________________________________________";
        std::cout << "\nMENU\n----" << std::endl;
        std::cout << "1) Exit Program!" << std::endl;
        std::cout << "2) Run randomStream   : Produce a file filled with random letters. " << std::endl;
        std::cout << "3) Run testStream     : Read a file to test and compare queues." << std::endl;
        std::cout << "4) Run both functions : First run randomStream, then run testStream with the same file." << std::endl;

        std::cout << "\nPlease enter a number to select an option...";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                std::cout << "\nEnding program ... Goodbye!" << std::endl;
                programRunning = false;

                break;
            }
            case 2:
            {
                std::cout << "\nUser selected option 2 ... Starting randomStream" << std::endl;

                //ask for filename
                std::cout << "\nPlease input a filename. (remember to add an extension, ie '.txt')...";
                string filename;
                std::cin >> filename;

                //ask for iterations
                std::cout << "Please input the iterations...";
                int iterations;
                std::cin >> iterations;

                //call method
                randomStream(filename, iterations);

                break;
            }
            case 3:
            {
                std::cout << "\nUser selected option 3 ... Starting testStream" << std::endl;

                testStream("test.txt");

                break;
            }
            case 4:
            {
                std::cout << "\nUser selected option 4 ... Starting randomStream" << std::endl;

                //ask for filename
                std::cout << "Please input a filename. (remember to add an extension, ie '.txt')...";
                string filename;
                std::cin >> filename;

                //ask for iterations
                std::cout << "Please input the iterations...";
                int iterations;
                std::cin >> iterations;

                //call method
                randomStream(filename, iterations);

                break;
            }
            default:
            {
                std::cout << "\nPlease try again." << std::endl;

                break;
            }
        }
    }

    exit(0);

}