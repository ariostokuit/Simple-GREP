//
//  main.cpp
//  Project2CS351
//
//  Created by Ariosto Kuit on 2/26/19.
//  Copyright © 2019 Ariosto Kuit. All rights reserved.
//
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    /* The command buffer */
    string cmdBuff;
    
    /* The ID of the child process */
    pid_t pid = 0;
    
    /* Keep running until the user has typed "exit" */
    do
    {
        /* Prompt the user to enter the command */
        cerr << "cmd>";
        cin >> cmdBuff;
        
        /* If the user wants to exit */
        if(cmdBuff != "exit")
        {
            string user_file = "urls.txt";
            fstream in_file;
            string url_string;
            
            in_file.open(user_file);
            if(in_file.fail()){
                cout << "URLs file does not exist!" << endl;
            }
            else{
                while(!in_file.eof()){
                    getline(in_file,url_string);
                
                /* TODO: Create a child */
                    pid = fork();
                
                    /* TODO: Error check to make sure the child was successfully created */
                    if(pid != 0){
                        /*** TODO: If I am a parent, I will do the following ***?*/
                        /* Wait for the child process to terminate */
                        cout << "Parent Process is now waiting\n";
                        wait(NULL);
                    }
                /*** TODO: If I am child, I will do this: ****/
                    else
                    {
                        cout << "Child successfully created.\n";
                        execlp("/usr/bin/wget", "wget", url_string.c_str(), NULL);
                    }
                    /* Call execlp() to replace my program with that specified at the command line.
             * PLEASE NOTE: YOU CANNOT PASS cmdBuff DIRECTLY to execlp(). It is because
             * cmdBuff is an object of type string (i.e., a class) and execlp() expects
             * an array of characters.  However, you can pass cmdBuff.c_str(), which will
             * return an array of characters representation of the string object.
             *
             * Also, please do not forget to error check your exelp() system calls.
             */
            
                }
            }
            in_file.close();
        }
    }while(cmdBuff != "exit");
    
    return 0;
}
